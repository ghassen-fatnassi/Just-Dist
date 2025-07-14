#pragma once
#include <vector>
#include <memory>

class Node;
class CommBus;
class Scheduler;

class Network {
public:
    Network();
    void initialize(int numNodes, CommBus* commBus, Scheduler* scheduler); // Setup nodes and dependencies.
    void startSimulation();   // Starts all node threads.
    void stopSimulation();    // Graceful shutdown.

private:
    std::vector<std::unique_ptr<Node>> nodes_;
    CommBus* commBus_;
    Scheduler* scheduler_;
};
