#pragma once
#include <cstdint>
#include <forward_list>
#include <queue>

namespace rtm {
  class ISchedulingTarget {
  public:
    virtual const uint64_t id() const = 0;
    virtual void evaluate(uint64_t step_count) = 0;
  };

  /// Rules:
  /// 1. Evaluate all queued nodes.
  /// 2. Propagate results to wires.
  /// 3. Enqueue all adjacent nodes.
  /// 4. step count + 1
  /// 5. wait for next step
  /// 6. go to 1.
  class Scheduler {
  public:
    inline void enqueue(ISchedulingTarget& t) { queue_.push(&t); }

  private:
    std::forward_list<const ISchedulingTarget*> collect_unique_targets();
    std::queue<ISchedulingTarget*> queue_;

    uint64_t step_count = 0;
  };
}  // namespace rtm
