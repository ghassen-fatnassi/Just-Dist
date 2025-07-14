#pragma once
#include <vector>
#include "Task.hpp"

class Node;

class Scheduler {
public:
    virtual ~Scheduler() = default;
    virtual void schedule(std::vector<Node*>& nodes, std::vector<Task> tasks) = 0;
};
