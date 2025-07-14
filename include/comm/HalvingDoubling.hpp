#pragma once
#include "AllReduceAlgorithm.hpp"

class HalvingDoubling : public AllReduceAlgorithm {
public:
    void execute(std::vector<Node*>& peers, TensorChunk data) override;
};