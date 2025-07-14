#pragma once
#include <vector>
#include "AllReduceAlgorithm.hpp"

class Node;

class CommBus {
public:
    void allReduce(std::vector<Node*>& nodes, TensorChunk tensor, AllReduceAlgorithm* algo);
};
