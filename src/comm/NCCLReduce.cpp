#pragma once
#include "AllReduceAlgorithm.hpp"

class NCCLReduce : public AllReduceAlgorithm {
public:
    void execute(std::vector<Node*>& peers, TensorChunk data) override;
};