#include <gtest/gtest.h>
#include "../examples/cpp/Inc/log.hpp"

int main(int argc, char** argv) {
  practice::log_init(0);
  LOG_DEBUG("Start unittest main function ");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
