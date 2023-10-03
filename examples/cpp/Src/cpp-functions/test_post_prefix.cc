#include <iostream>
#include <stdio.h>
#include <chrono>
#include <limits>

void test_post_pre_fix(void) {
    int x = 0;
    int total_n = 1000;  // std::numeric_limits<int>::max();

    std::cout << "prefix: \n";
    for (int i = 0; i < 5; i++) printf("i: %d \n", i);

    std::cout << "postfix: \n";
    for (int i = 0; i < 5; ++i) printf("i: %d \n", i);

    std::cout << "  total_n: " << total_n << std::endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> start =
        std::chrono::high_resolution_clock::now();
    for (int i = 0; i < total_n; i++) total_n += 1;
    std::chrono::time_point<std::chrono::high_resolution_clock> end =
        std::chrono::high_resolution_clock::now();

    auto diff = end - start;
    std::cout << "prefix: "
              << std::chrono::duration_cast
                <std::chrono::microseconds>(diff).count()
              << "us" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < total_n; ++i) total_n += 1;
    end = std::chrono::high_resolution_clock::now();

    diff = end - start;
    std::cout << "postfix: "
              << std::chrono::duration_cast
                <std::chrono::microseconds>(diff).count()
              << "us" << std::endl;

    
    int in = 10;
    int y = in++;
    printf("prefix: in: %d, y: %d \n", in, y);

    in = 10;
    y = ++in;
    printf("postfix: in: %d, y: %d \n", in, y);
}
