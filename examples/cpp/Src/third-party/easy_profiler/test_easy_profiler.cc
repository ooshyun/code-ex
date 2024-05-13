#include <easy/profiler.h>
#include <log.hpp>

void easy_profiler_init(void) {
  LOG_INFO("Call easy_profiler_init");
  // remain profiler and not connect through network
  EASY_PROFILER_ENABLE;
  EASY_MAIN_THREAD;
  profiler::startListen();
}

void easy_profiler_finish(void) {
  LOG_INFO("Call easy_profiler_finish");
  auto blocks_written = profiler::dumpBlocksToFile("test_profile.prof");
  LOG_INFO("Blocks count: {0}", blocks_written);
}

void foo() {
    EASY_FUNCTION(profiler::colors::Magenta); // Magenta block with name "foo"

    EASY_BLOCK("Calculating sum");; // Begin block with default color == Amber100
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        EASY_BLOCK("Addition", profiler::colors::Red); // Scoped red block (no EASY_END_BLOCK needed)
        sum += i;
    }
    EASY_END_BLOCK; // End of "Calculating sum" block

    EASY_BLOCK("Calculating multiplication", profiler::colors::Blue500); // Blue block
    int mul = 1;
    for (int i = 1; i < 11; ++i)
        mul *= i;
    //EASY_END_BLOCK; // This is not needed because all blocks are ended on destructor when closing braces met
}

void bar() {
    EASY_FUNCTION(0xfff080aa); // Function block with custom ARGB color
}

void baz() {
    EASY_FUNCTION(); // Function block with default color == Amber100
}

void test_easy_profiler(void) {
    LOG_INFO("Start test_easy_profiler");

    foo();
    bar();
    baz();

    LOG_INFO("End test_easy_profiler");
}