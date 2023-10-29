// Producer and Consumer pattern
#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <condition_variable>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
            int index) {
    for (int i = 0; i < 5; i++) {
        // Hypothesis: downloading each page takes different time
        std::this_thread::sleep_for(std::chrono::milliseconds(100*index));
        std::string page = "Page " + std::to_string(i) +
                      " from thread (" + std::to_string(index) + ")\n";

        // data is sharaed between threads, so we need to lock it
        m->lock();
        downloaded_pages->push(page);
        m->unlock();
    }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
            int* num_processed) {
    while (*num_processed < 25) {  // do until total 25 pages are processed
        m->lock();

        if (downloaded_pages->empty()) {
            m->unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        std::string page = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        m->unlock();

        std::cout << page;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));

    }

}

void _test_thread_pattern(void) {
    std::queue<std::string> downloaded_pages;
    std::mutex m;

    std::vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i+1));
    }

    int num_processed = 0;

    std::vector<std::thread> consumers;
    for (int i = 0; i < 5; i++) {
        consumers.push_back(std::thread(consumer, &downloaded_pages,
                                        &m, &num_processed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }

    for (int i = 0; i < 5; i++) {
        consumers[i].join();
    }
}


void producer_cv(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int index, std::condition_variable* cv) {
  for (int i = 0; i < 5; i++) {
    // 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다.
    // 각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다.
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
    std::string content = "Pages : " + std::to_string(i) + " from thread(" +
                          std::to_string(index) + ")\n";

    // data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다.
    m->lock();
    downloaded_pages->push(content);
    m->unlock();

    // consumer 에게 content 가 준비되었음을 알린다.
    cv->notify_one();
  }
}

void consumer_cv(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int* num_processed, std::condition_variable* cv) {
  while (*num_processed < 25) {
    std::unique_lock<std::mutex> lk(*m);

    // [&] means capture local area
    cv->wait(
        lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

    if (*num_processed == 25) {
      lk.unlock();
      return;
    }

    // 맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
    std::string content = downloaded_pages->front();
    downloaded_pages->pop();

    (*num_processed)++;
    lk.unlock();

    // content 를 처리한다.
    std::cout << content;
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }
}

void _test_thread_pattern_condition_var(void) {
  // 현재 다운로드한 페이지들 리스트로, 아직 처리되지 않은 것들이다.
  std::queue<std::string> downloaded_pages;
  std::mutex m;
  std::condition_variable cv;

  std::vector<std::thread> producers;
  for (int i = 0; i < 5; i++) {
    producers.push_back(
        std::thread(producer_cv, &downloaded_pages, &m, i + 1, &cv));
  }

  int num_processed = 0;
  std::vector<std::thread> consumers;
  for (int i = 0; i < 3; i++) {
    consumers.push_back(
        std::thread(consumer_cv, &downloaded_pages, &m, &num_processed, &cv));
  }

  for (int i = 0; i < 5; i++) {
    producers[i].join();
  }

  // 나머지 자고 있는 쓰레드들을 모두 깨운다.
  cv.notify_all();

  for (int i = 0; i < 3; i++) {
    consumers[i].join();
  }
}


void test_thread_pattern(void) {
    printf("  test_thread_pattern\n");
    // _test_thread_pattern();

    _test_thread_pattern_condition_var();

}