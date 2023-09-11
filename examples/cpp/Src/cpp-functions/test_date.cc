// https://modoocode.com/304#page-heading-5
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

void testDateTime(void)
{
  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);
  std::cout << "현재 시간은 : " << std::put_time(std::localtime(&t), "%F %T %z")
            << '\n';
}  
