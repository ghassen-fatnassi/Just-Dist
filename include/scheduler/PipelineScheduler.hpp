#pragma once
#include "Scheduler.hpp"
#include "Stage.hpp"

class PipelineScheduler : public Scheduler {
public:
    void schedule(std::vector<Node*>& nodes, std::vector<Task> tasks) override;

private:
    std::vector<Stage> stages_;
};
