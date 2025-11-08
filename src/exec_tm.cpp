#include "exec_tm.h"

#include <chrono>

static std::chrono::steady_clock::time_point g_begin, g_end;

void start_measuring_time() {
    g_begin = std::chrono::steady_clock::now();
}

void stop_measuring_time() {
    g_end = std::chrono::steady_clock::now();
}

std::int64_t get_exec_time_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(g_end - g_begin).count();
}
