
#include "../../Inc/log.hpp"

namespace practice {
spdlog::level::level_enum log_level_from_int(int level) {
  switch (level) {
    case 0:
      return spdlog::level::debug;
    case 1:
      return spdlog::level::info;
    case 2:
      return spdlog::level::warn;
    case 3:
      return spdlog::level::err;
    default:
      return spdlog::level::info;
  }
}

int log_init(int log_level) {
  std::cout << "Call log_init function \n";
  try {
    const std::string default_logger = "oohyun";
    if (!spdlog::get(default_logger)) {
      auto console = spdlog::stdout_color_mt(default_logger);
      console->set_level(log_level_from_int(log_level));
      spdlog::set_default_logger(console);
    }
  } catch (const spdlog::spdlog_ex& e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 0;
}
}  // namespace practice
