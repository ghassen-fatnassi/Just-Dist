#pragma once
#include "Message.hpp"

struct Task {
    int microbatchId;
    TensorChunk data;
};
