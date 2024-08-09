/*
  Copyright from https://modoocode.com/284
*/

#include <exception>
#include <future>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using std::string;

std::condition_variable cv;
std::mutex m;
bool done = false;
std::string info;

void worker_promise_future_scratch() {
  {
    std::lock_guard<std::mutex> lk(m);
    info = "some data";  // 위의 p->set_value("some data") 에 대응
    done = true;
  }
  cv.notify_all();
}

void test_promise_future_scratch(void) {
  std::thread t(worker_promise_future_scratch);

  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, [] { return done; });  // 위의 data.wait() 이라 보면 된다.
  lk.unlock();

  std::cout << "받은 데이터 : " << info << std::endl;

  t.join();
}

void worker_future_promise(std::promise<string>* p) {
  try {
    throw std::runtime_error("Some Error!");
  } catch (...) {
    // set_exception 에는 exception_ptr 를 전달해야 한다.
    p->set_exception(std::current_exception());
  }
}

void test_promise_future(void) {
  std::promise<string> p;

  // 미래에 string 데이터를 돌려 주겠다는 약속.
  std::future<string> data = p.get_future();

  std::thread t(worker_future_promise, &p);

  // 미래에 약속된 데이터를 받을 때 까지 기다린다.
  data.wait();

  try {
    data.get();
  } catch (const std::exception& e) {
    std::cout << "예외 : " << e.what() << std::endl;
  }
  t.join();
}

// wait for
void worker_wait_for(std::promise<void>* p) {
  std::this_thread::sleep_for(std::chrono::seconds(10));
  p->set_value();
}

void test_wait_for(void) {
  // void 의 경우 어떠한 객체도 전달하지 않지만, future 가 set 이 되었냐
  // 안되었느냐의 유무로 마치 플래그의 역할을 수행할 수 있습니다.
  std::promise<void> p;

  // 미래에 string 데이터를 돌려 주겠다는 약속.
  std::future<void> data = p.get_future();

  std::thread t(worker_wait_for, &p);

  // 미래에 약속된 데이터를 받을 때 까지 기다린다.
  while (true) {
    std::future_status status = data.wait_for(std::chrono::seconds(1));

    // 아직 준비가 안됨
    if (status == std::future_status::timeout) {
      std::cerr << ">";
    } else if (status == std::future_status::ready) {
      // promise 가 future 를 설정함.
      break;
    }
  }
  t.join();
}

// shared_future
void runner(std::shared_future<void> start) {
  start.get();
  std::cout << "출발!" << std::endl;
}

void test_shared_future(void) {
  std::promise<void> p;
  std::shared_future<void> start = p.get_future();

  std::thread t1(runner, start);
  std::thread t2(runner, start);
  std::thread t3(runner, start);
  std::thread t4(runner, start);

  // 참고로 cerr 는 std::cout 과는 다르게 버퍼를 사용하지 않기 때문에 터미널에
  // 바로 출력된다.
  std::cerr << "준비...";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cerr << "땅!" << std::endl;

  p.set_value();

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

// packaged_task
int some_task(int x) { return 10 + x; }

void test_packaged_task(void) {
  // int(int) : int 를 리턴하고 인자로 int 를 받는 함수. (std::function 참조)
  std::packaged_task<int(int)> task(some_task);

  std::future<int> start = task.get_future();

  // no need to set promise
  std::thread t(std::move(task), 5);

  std::cout << "결과값 : " << start.get() << std::endl;
  t.join();
}

// async
// std::accumulate 와 동일
int sum(const std::vector<int>& v, int start, int end) {
  int total = 0;
  for (int i = start; i < end; ++i) {
    total += v[i];
  }
  return total;
}

int parallel_sum(const std::vector<int>& v) {
  // lower_half_future 는 1 ~ 500 까지 비동기적으로 더함
  // 참고로 람다 함수를 사용하면 좀 더 깔끔하게 표현할 수 도 있다.
  // --> std::async([&v]() { return sum(v, 0, v.size() / 2); });
  // std::launch::async : 바로 쓰레드를 생성해서 인자로 전달된 함수를 실행한다.
  // std::launch::deferred : future 의 get 함수가 호출되었을 때 실행한다.
  //    (새로운 쓰레드를 생성하지 않음)

  std::future<int> lower_half_future =
    std::async(std::launch::async, sum, cref(v), 0, v.size() / 2);

  // upper_half 는 501 부터 1000 까지 더함
  int upper_half = sum(v, v.size() / 2, v.size());

  return lower_half_future.get() + upper_half;
}

void test_async(void) {
  std::vector<int> v;
  v.reserve(1000);

  for (int i = 0; i < 1000; ++i) {
    v.push_back(i + 1);
  }

  std::cout << "1 부터 1000 까지의 합 : " << parallel_sum(v) << std::endl;
}


// sync vs async
int do_work(int x) {
  // x 를 가지고 무슨 일을 한다.
  std::this_thread::sleep_for(std::chrono::seconds(3));
  return x;
}

void do_work_parallel() {
  auto f1 = std::async([]() { do_work(3); });
  auto f2 = std::async([]() { do_work(3); });
  do_work(3);

  f1.get();
  f2.get();
}

void do_work_sequential() {
  do_work(3);
  do_work(3);
  do_work(3);
}

void test_sync_vs_async_sync(void) { do_work_sequential(); }
void test_sync_vs_async_async(void) { do_work_parallel(); }

void test_sync_and_async(void) {
  test_promise_future_scratch();
  // test_promise_future();
  // test_wait_for();
  // test_shared_future();
  // test_packaged_task();
  // test_async();
  // test_sync_vs_async_sync();   // time .exe, expect around 9 sec
  // test_sync_vs_async_async();  // time .exe, expect around 3 sec
}