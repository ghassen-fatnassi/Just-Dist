#pragma once
#include <mutex>
#include <vector>
#include <string>

struct LogEvent {
    double time;
    std::string component;
    std::string action;
    std::string detail;
};

class Logger {
public:
    static Logger& getInstance(); // Singleton access
    void logEvent(const LogEvent& event);
    void dumpCSV(const std::string& path);

private:
    Logger() = default;
    std::mutex mtx_;
    std::vector<LogEvent> events_;
};
