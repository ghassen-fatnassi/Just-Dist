#pragma once
#include "Task.hpp"

class Node;

class Stage {
public:
    void setNode(Node* node);
    void execute(const Task& task); // Simulates compute delay.

private:
    int id_;
    Node* node_;
    double computeDelay_;
};
