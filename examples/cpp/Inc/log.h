#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

int log_init(int log_level);

#define SENSE_LOG_INFO(message, ...) spdlog::info(message, ##__VA_ARGS__)
#define SENSE_LOG_DEBUG(message, ...) spdlog::debug(message, ##__VA_ARGS__)

#endif