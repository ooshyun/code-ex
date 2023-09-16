// https://modoocode.com/271

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using std::memory_order_relaxed;

std::atomic<bool> is_ready_global;
std::atomic<int> data_arr[3];

std::atomic<bool> x(false);
std::atomic<bool> y(false);
std::atomic<int> z(0);

std::atomic<bool> x_seq_cst(false);
std::atomic<bool> y_seq_cst(false);
std::atomic<int> z_seq_cst(0);

void worker(std::atomic<int>& counter) {
// void worker(int* counter) {
  for (int i = 0; i < 10000; i++) {
    counter++;
    // (*counter)++;
  }
}


void test_atomic(void) {
    printf("  test_atomic\n");
    std::atomic<int> counter(0);
    // int counter = 0;

    std::vector<std::thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, ref(counter)));
        // workers.push_back(std::thread(worker, &counter));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    std::cout << "Counter 최종 값 : " << counter << std::endl;
}

void t1(std::atomic<int>* a, std::atomic<int>* b) {
  b->store(1, memory_order_relaxed);      // b = 1 (쓰기)
  int x = a->load(memory_order_relaxed);  // x = a (읽기)

  printf("x : %d \n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) {
  a->store(1, memory_order_relaxed);      // a = 1 (쓰기)
  int y = b->load(memory_order_relaxed);  // y = b (읽기)

  printf("y : %d \n", y);
}

void test_memory_order_relaxed(void) {
  // It can show combination (a,b) = (0,0), (0,1), (1,0), (1,1)
  std::vector<std::thread> threads;

  std::atomic<int> a(0);
  std::atomic<int> b(0);

  threads.push_back(std::thread(t1, &a, &b));
  threads.push_back(std::thread(t2, &a, &b));

  for (int i = 0; i < 2; i++) {
    threads[i].join();
  }
}


void worker_atomic_memory_order_relaxed(std::atomic<int>* counter) {
  for (int i = 0; i < 10000; i++) {
    // 다른 연산들 수행

    counter->fetch_add(1, memory_order_relaxed);
  }
}

void test_atomic_memory_order_relaxed(void) {
  // It didn't have problem, because it only add to counter var
  std::vector<std::thread> threads;

  std::atomic<int> counter(0);

  for (int i = 0; i < 4; i++) {
    threads.push_back(std::thread(
      worker_atomic_memory_order_relaxed, \
      &counter));
  }

  for (int i = 0; i < 4; i++) {
    threads[i].join();
  }

  std::cout << "Counter : " << counter << std::endl;
}

void producer(std::atomic<bool>* is_ready, int* data) {
  *data = 10;
  is_ready->store(true, std::memory_order_release);
  
  data_arr[0].store(1, memory_order_relaxed);
  data_arr[1].store(2, memory_order_relaxed);
  data_arr[2].store(3, memory_order_relaxed);
  is_ready_global.store(true, std::memory_order_release);
}

void consumer(std::atomic<bool>* is_ready, int* data) {
    // data 가 준비될 때 까지 기다린다.

    while (!is_ready->load(std::memory_order_acquire)) {
    }

    std::cout << "Data : " << *data << std::endl;

    while (!is_ready_global.load(std::memory_order_acquire)) {
    }
    std::cout << "data[0] : " \
      << data_arr[0].load(memory_order_relaxed) << std::endl;
    std::cout << "data[1] : " \
      << data_arr[1].load(memory_order_relaxed) << std::endl;
    std::cout << "data[2] : " \
      << data_arr[2].load(memory_order_relaxed) << std::endl;

    std::atomic_thread_fence(std::memory_order_acquire);

}

void test_atomic_rel_ack(void) {
    std::vector<std::thread> threads;

    std::atomic<bool> is_ready(false);
    int data = 0;

    threads.push_back(std::thread(producer, &is_ready, &data));
    threads.push_back(std::thread(consumer, &is_ready, &data));

    for (int i = 0; i < 2; i++) {
        threads[i].join();
    }
}



void write_x_rel() { x.store(true, std::memory_order_release); }

void write_y_rel() { y.store(true, std::memory_order_release); }

void read_x_then_y_acq() {
  while (!x.load(std::memory_order_acquire)) {
  }
  if (y.load(std::memory_order_acquire)) {
    ++z;
  }
}

void read_y_then_x_acq() {
  while (!y.load(std::memory_order_acquire)) {
  }
  if (x.load(std::memory_order_acquire)) {
    ++z;
  }
}

void test_atomic_rel_ack_sequence(void) {
  std::thread a(write_x_rel);
  std::thread b(write_y_rel);
  std::thread c(read_x_then_y_acq);
  std::thread d(read_y_then_x_acq);
  a.join();
  b.join();
  c.join();
  d.join();
  std::cout << "z : " << z << std::endl;
}


void write_x_seq_cst() { x_seq_cst.store(true, std::memory_order_seq_cst); }

void write_y_seq_cst() { y_seq_cst.store(true, std::memory_order_seq_cst); }

void read_x_then_y_seq_cst() {
  while (!x_seq_cst.load(std::memory_order_seq_cst)) {
  }
  if (y_seq_cst.load(std::memory_order_seq_cst)) {
    ++z;
  }
}

void read_y_then_x_seq_cst() {
  while (!y_seq_cst.load(std::memory_order_acquire)) {
  }
  if (x_seq_cst.load(std::memory_order_acquire)) {
    ++z;
  }
}

void test_atomic_seq_cst_sequence(void) {
  std::thread a(write_x_seq_cst);
  std::thread b(write_y_seq_cst);
  std::thread c(read_x_then_y_seq_cst);
  std::thread d(read_y_then_x_seq_cst);
  a.join();
  b.join();
  c.join();
  d.join();
  std::cout << "z : " << z_seq_cst << std::endl;
}