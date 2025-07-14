#pragma once

struct TensorChunk {
    // Placeholder for tensor chunk abstraction.
};

struct Message {
    int senderId;
    TensorChunk payload;
    double timestamp;
};
