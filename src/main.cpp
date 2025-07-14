#include "Network.hpp"
#include "CommBus.hpp"
#include "PipelineScheduler.hpp"

int main() {
    CommBus commBus;
    PipelineScheduler scheduler;
    Network network;
    network.initialize(4, &commBus, &scheduler);  // Example: 4 nodes.

    network.startSimulation();
    // Run simulation, scheduler issues tasks, communication occurs.
    network.stopSimulation();

    return 0;
}
