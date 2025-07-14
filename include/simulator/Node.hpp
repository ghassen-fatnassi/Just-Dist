#pragma once
#include <thread>
#include <memory>
#include "MessageQueue.hpp"
#include "Message.hpp"

class Node {
public:
    explicit Node(int id);
    void sendMessage(int targetId, const Message& msg); // Send message to another Node.
    void receiveMessage(const Message& msg);            // Place message in inbox.
    void run();    // Main loop running on thread.

    int getId() const;

private:
    int id_;
    MessageQueue inbox_;
    std::thread thread_;
};
