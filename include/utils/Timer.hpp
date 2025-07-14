#pragma once
#include <chrono>

class Timer {
public:
    void start();
    double stop();  // Returns elapsed time in milliseconds.

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};
