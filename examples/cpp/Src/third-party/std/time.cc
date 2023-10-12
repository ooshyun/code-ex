#include <ctime>
#include <iostream>

void test_time(void) {
    std::time_t t = std::time(nullptr);  // t is an integer type
    std::time_t t2 = 1696702764;

    std::cout << t << std::endl;
}
