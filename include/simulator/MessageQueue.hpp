#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Message.hpp"

class MessageQueue {
public:
    void push(const Message& msg);  // Push a message (producer).
    Message pop();                  // Pop a message (consumer, blocking).

private:
    std::queue<Message> queue_;
    std::mutex mtx_;
    std::condition_variable cv_;
};
