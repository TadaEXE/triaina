#pragma once

#include <vector>

#include "runtime/scheduler.hpp"
#include "runtime/state.hpp"

namespace rtm {

  /// A wire represents a directional 1 to 1 connection between two ports one or two nodes in the graph.
  /// They can be seen as a sort of buffer that:
  ///   - collects inputs
  ///   - waits for the propagartion signal
  ///   - evaluates to one state
  ///   - enqueus the connected node to the eval queue
  class Wire : public ISchedulingTarget {
  public:
    Wire(uint64_t id, ISchedulingTarget& target, Scheduler& scheduler,
         const State default_state = State::Zero)
        : id_(id),
          target_(target),
          scheduler_(scheduler),
          state_(default_state) {}

    void push_state(const State s);

    void evaluate(uint64_t step_count) override;

    const uint64_t last_update() const { return last_update_; }

    const State state() const { return state_; }

    const uint64_t id() const override { return id_; }

    const auto& target() const { return target_; }

  private:
    uint64_t last_update_ = 0;
    State state_;

    const uint64_t id_;

    std::vector<State> state_buffer_;
    ISchedulingTarget& target_;

    Scheduler& scheduler_;
  };

}  // namespace rtm
