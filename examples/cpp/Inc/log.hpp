
#ifndef LOG_H
#define LOG_H

#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace practice {
    int log_init(int log_level);

    #define LOG_INFO(message, ...) spdlog::info(message, ##__VA_ARGS__)
    #define LOG_DEBUG(message, ...) spdlog::debug(message, ##__VA_ARGS__)
    #define LOG_WARN(message, ...) spdlog::warn(message, ##__VA_ARGS__)
}  // namespace practice

#endif  // LOG_H
