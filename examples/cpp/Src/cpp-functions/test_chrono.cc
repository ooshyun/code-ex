// https://modoocode.com/304#page-heading-5

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

namespace ch = std::chrono;

void testChrono(void) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> dist(0, 1000);

  for (int total = 1; total <= 1000000; total *= 10) {
    std::vector<int> random_numbers;
    random_numbers.reserve(total);

    ch::time_point<ch::high_resolution_clock> start =
        ch::high_resolution_clock::now();

    for (int i = 0; i < total; i++) {
      random_numbers.push_back(dist(gen));
    }

    ch::time_point<ch::high_resolution_clock> end =
        ch::high_resolution_clock::now();

    auto diff = end - start;
    std::cout << std::setw(7) << total << "개 난수 생성 시 걸리는 시간: "
              << ch::duration_cast<ch::microseconds>(diff).count() << "us"
              << std::endl;
  }
}
