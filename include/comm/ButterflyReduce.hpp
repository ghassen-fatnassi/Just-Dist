#pragma once
#include "AllReduceAlgorithm.hpp"

class ButterflyReduce : public AllReduceAlgorithm {
public:
    void execute(std::vector<Node*>& peers, TensorChunk data) override;
};