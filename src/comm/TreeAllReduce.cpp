#pragma once
#include "AllReduceAlgorithm.hpp"

class TreeAllReduce : public AllReduceAlgorithm {
public:
    void execute(std::vector<Node*>& peers, TensorChunk data) override;
};