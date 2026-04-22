#pragma once
#include <cstdint>
#include <functional>
#include <vector>

#include "runtime/model/edge.hpp"
#include "runtime/scheduler.hpp"

namespace rtm {

  class Node : public ISchedulingTarget {
  public:
    Node(const uint64_t id, const std::string& label,
         std::function<State(std::vector<Edge>&, std::vector<Edge>&)> eval_func,
         Scheduler& scheduler)
        : id_(id),
          label_(label),
          eval_func_(eval_func),
          scheduler_(scheduler) {}

    const uint64_t id() const override { return id_; }

    const std::string& label() const { return label_; }

    auto& inputs() { return inputs_; }

    auto& outputs() { return outputs_; }

    void evaluate(uint64_t step_count) override;

  private:
    std::vector<Edge> inputs_;
    std::vector<Edge> outputs_;
    const uint64_t id_;
    std::string label_;
    std::function<State(std::vector<Edge>&, std::vector<Edge>&)> eval_func_;
    Scheduler& scheduler_;
  };

}  // namespace rtm
