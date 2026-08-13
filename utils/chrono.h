#pragma once
#include <chrono>
#include <unistd.h>

using namespace std::chrono;
using namespace std::chrono_literals;

class TimeCost {
public:
    TimeCost() : start_time_(std::chrono::high_resolution_clock::now()) {}

    void begin_time_point() {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    double get_time_cost(bool is_reset = false) {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            end_time - start_time_);
        double cost_ms = static_cast<double>(duration.count()) / 1e3;

        if (is_reset) {
            start_time_ = std::chrono::high_resolution_clock::now();
        }

        return cost_ms;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time_;
};