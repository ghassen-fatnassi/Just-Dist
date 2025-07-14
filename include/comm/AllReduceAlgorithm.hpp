#pragma once
#include <vector>
#include "Message.hpp"

class Node;

class AllReduceAlgorithm {
public:
    virtual ~AllReduceAlgorithm() = default;
    virtual void execute(std::vector<Node*>& peers, TensorChunk data) = 0; // Algorithm executes AllReduce.
};
