#pragma once

#include <cstdint>

void start_measuring_time();
void stop_measuring_time();

std::int64_t get_exec_time_ms();
