// src/main.cpp
#include <torch/torch.h>
#include <iostream>

int pipeline() {
    auto x = torch::rand({2, 2}, torch::TensorOptions().device(torch::kCUDA));
    std::cout << "CUDA tensor:\n" << x << std::endl;
    return 0;
}
// src/scheduler/pipeline_scheduler.cpp