/*
  Copyright from https://modoocode.com/285
*/
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool {
class ThreadPool {
 public:
  explicit ThreadPool(size_t num_threads);
  ~ThreadPool();

  // job 을 추가한다.
  template <class F, class... Args>
  std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
    F&& f, Args&&... args);

 private:
  // 총 Worker 쓰레드의 개수.
  size_t num_threads_;
  // Worker 쓰레드를 보관하는 벡터.
  std::vector<std::thread> worker_threads_;
  // 할일들을 보관하는 job 큐.
  std::queue<std::function<void()>> jobs_;
  // 위의 job 큐를 위한 cv 와 m.
  std::condition_variable cv_job_q_;
  std::mutex m_job_q_;

  // 모든 쓰레드 종료
  bool stop_all;

  // Worker 쓰레드
  void WorkerThread();
};

ThreadPool::ThreadPool(size_t num_threads)
    : num_threads_(num_threads), stop_all(false) {
  worker_threads_.reserve(num_threads_);
  for (size_t i = 0; i < num_threads_; ++i) {
    worker_threads_.emplace_back([this]() { this->WorkerThread(); });
  }
}

void ThreadPool::WorkerThread() {
  while (true) {
    std::unique_lock<std::mutex> lock(m_job_q_);
    cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
    if (stop_all && this->jobs_.empty()) {
      return;
    }

    // 맨 앞의 job 을 뺀다.
    std::function<void()> job = std::move(jobs_.front());
    jobs_.pop();
    lock.unlock();

    // 해당 job 을 수행한다 :)
    job();
  }
}

ThreadPool::~ThreadPool() {
  stop_all = true;
  cv_job_q_.notify_all();

  for (auto& t : worker_threads_) {
    t.join();
  }
}

template <class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
  F&& f, Args&&... args) {
  if (stop_all) {
    throw std::runtime_error("ThreadPool 사용 중지됨");
  }

  using return_type = typename std::result_of<F(Args...)>::type;
  // make promise / packaged_task
  auto job = std::make_shared<std::packaged_task<return_type()>>(
    // std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::bind(f, std::forward<Args>(args)...));
  // make thread
  std::future<return_type> job_result_future = job->get_future();
  {
    std::lock_guard<std::mutex> lock(m_job_q_);
    jobs_.push([job]() { (*job)(); });
  }
  cv_job_q_.notify_one();

  return job_result_future;
}
}  // namespace ThreadPool

class BaseClassThreadPool {
 public:
  virtual ~BaseClassThreadPool() = default;
  virtual int get_varable() = 0;
  BaseClassThreadPool& operator=(BaseClassThreadPool&&) = default;
  // BaseClassThreadPool(const BaseClassThreadPool&) = default;
  int get_x_base() { return _x_base; }
  int get_y_base() { return _y_base; }

 protected:
  BaseClassThreadPool(int x, int y) : _x_base(x), _y_base(y) {}
  int _x_base;
  int _y_base;

 private:
};

class ParentClassThreadPool : public BaseClassThreadPool {
 public:
  ParentClassThreadPool(int x, int y):
      BaseClassThreadPool(x, y) {
    _x = x+y;
    _y = x-y;
    _ptr = std::make_unique<ParentClassThreadPool>(x+1, y+1);
  }
  ~ParentClassThreadPool() final = default;
  int get_varable() final { return _x_base + _y_base; }
  int get_x() { return _x; }
  int get_y() { return _y; }
 private:
  int _x;
  int _y;
  std::unique_ptr<ParentClassThreadPool> _ptr;
};

int work(int t, int id) {
  printf("%d start \n", id);
  std::this_thread::sleep_for(std::chrono::seconds(t));
  printf("%d end after %ds\n", id, t);
  return t + id;
}

std::vector<float> work_ptr(const std::unique_ptr<ParentClassThreadPool>& ptr) {
// std::vector<float> work_ptr(const std::unique_ptr<ParentClassThreadPool>&& ptr) {
  printf("work_ptr %p start \n", std::ref(ptr));
  // std::this_thread::sleep_for(std::chrono::seconds(1));
  std::vector<float> result;
  result.push_back(static_cast<float>(ptr->get_x()));
  result.push_back(static_cast<float>(ptr->get_y()));
  result.push_back(static_cast<float>(ptr->get_varable()));
  printf("work_ptr %p end \n", std::ref(ptr));
  return result;
}

// static int call_time = 0;
// void work_ptr() {
//   printf("work_ptr! %d \n", call_time);
//   call_time++;
// }

int test_thread_pool() {
  ThreadPool::ThreadPool pool(8);

  // printf("-- start test 1\n");

  // // Test 1
  // std::vector<std::future<int>> futures;
  // for (int i = 0; i < 10; i++) {
  //   futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
  // }
  // for (auto& f : futures) {
  //   printf("result : %d \n", f.get());
  // }

  printf("-- start test 2\n");

  // Test 2-3 multi-thread
  std::vector<std::future<std::vector<float>>> futures_ptr;
  std::vector<std::unique_ptr<ParentClassThreadPool>> parent_ptrs;
  for (int i = 0; i < 10; i++) {
    std::unique_ptr<ParentClassThreadPool> parent_ptr =
        std::make_unique<ParentClassThreadPool>(i, i + 1);
    parent_ptrs.push_back(std::move(parent_ptr));
  }

  // Test 2: unique_ptr
  // OK
  for (int i = 0; i < 10; i++) {
    printf("%d - %p \n", i, std::ref(parent_ptrs[i]));
  }
  // for (int i = 0; i < 10; i++) {
  //   auto result = work_ptr(parent_ptrs[i]);
  // }

  for (int i = 0; i < 10; i++) {
    futures_ptr.emplace_back(pool.EnqueueJob(
        work_ptr, std::ref(parent_ptrs[i])));
  }

  printf("Get future!\n");
  for (auto& f : futures_ptr) {
    std::vector<float> result = f.get();
    for (size_t j = 0; j < result.size(); j++) {
      printf("%f \n", result[j]);
    }
  }

  printf("--Finished test 2!\n");

  // Test 3: async
  std::vector<std::future<std::vector<float>>> v_async;

  v_async.reserve(10);

  for (size_t i = 0; i < 10; i++) {
    v_async.emplace_back(std::async(
        std::launch::async, work_ptr, std::ref(parent_ptrs[i])));
        // std::launch::async, work_ptr, std::move(parent_ptrs[i])));
  }

  for (size_t i = 0; i < 10; i++)
    v_async[i].wait();

  printf("Get future!\n");
  for (size_t i = 0; i < 10; i++) {
    printf("result %d\n", i);
    std::vector<float> result = v_async[i].get();
    for (size_t j = 0; j < result.size(); j++) {
      printf("%f \n", result[j]);
    }
  }

  printf("--Finished test 3!\n");
}
