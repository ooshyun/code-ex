#include <iostream>
#include <unistd.h>
#include <chrono>   // chrono::system_clock
#include <ctime>    // localtime
#include <sstream>  // stringstream
#include <iomanip>  // put_time
#include <string>   // string


void test() {
  // usleep(10);
  sleep(3);
}

std::string return_current_time_and_date() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

void test_chronos_time(void) {
  std::chrono::system_clock::time_point now =
      std::chrono::system_clock::now();
  test();
  std::chrono::system_clock::time_point end =
      std::chrono::system_clock::now();

  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::string now_string = std::to_string(now_time);
  std::cout << "now_time: " << now_time << std::endl;
  std::cout << "now_string: " << now_string << std::endl;

  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::string end_string = std::to_string(end_time);
  std::cout << "end_time: " << end_time << std::endl;
  std::cout << "end_string: " << end_string << std::endl;

  std::chrono::nanoseconds nano;
  std::chrono::microseconds micro;
  std::chrono::milliseconds milli;
  std::chrono::seconds sec;
  std::chrono::minutes min;
  std::chrono::hours hour;

  nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - now);
  micro = std::chrono::duration_cast<std::chrono::microseconds>(end - now);
  milli = std::chrono::duration_cast<std::chrono::milliseconds>(end - now);
  sec = std::chrono::duration_cast<std::chrono::seconds>(end - now);
  min = std::chrono::duration_cast<std::chrono::minutes>(end - now);
  hour = std::chrono::duration_cast<std::chrono::hours>(end - now);


  std::cout << "nano: " << nano.count() << std::endl;
  std::cout << "micro: " << micro.count() << std::endl;
  std::cout << "milli: " << milli.count() << std::endl;
  std::cout << "sec: " << sec.count() << std::endl;
  std::cout << "min: " << min.count() << std::endl;
  std::cout << "hour: " << hour.count() << std::endl;


  std::cout << return_current_time_and_date() << std::endl;
}
