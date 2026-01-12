#include "exec_tm.h"

#include <chrono>

static std::chrono::steady_clock::time_point g_begin, g_end;
static bool result_is_valid;

void start_measuring_time() {
    g_begin = std::chrono::steady_clock::now();
    if (result_is_valid) {
        result_is_valid = false;
    }
}

void stop_measuring_time() {
    g_end = std::chrono::steady_clock::now();
    result_is_valid = true;
}

std::int64_t get_exec_time_ms() {
    if (!result_is_valid) {
        throw std::runtime_error("[get_exec_time_ms] execution time is invalid");
    }
    auto tmp = g_end - g_begin;
    g_end = g_begin = std::chrono::steady_clock::now();
    result_is_valid = false;
    return std::chrono::duration_cast<std::chrono::milliseconds>(tmp).count();
}
