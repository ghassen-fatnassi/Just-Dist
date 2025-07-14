#pragma once
#include "AllReduceAlgorithm.hpp"

class RingAllReduce : public AllReduceAlgorithm {
public:
    void execute(std::vector<Node*>& peers, TensorChunk data) override;
};