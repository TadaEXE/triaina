#include "runtime/model/edge.hpp"

#include <algorithm>
#include <format>

#include "runtime/model/state.hpp"
#include "runtime/scheduler.hpp"

namespace rtm {

  void Edge::push_state(const State s) {
    state_buffer_.push_back(s);
  }

  void Edge::evaluate(const uint64_t step_count) {
    if (state_buffer_.empty()) return;

    last_update_ = step_count;

    auto first = state_buffer_.at(0);
    if (std::find_if_not(state_buffer_.begin(), state_buffer_.end(),
                         [first](auto s) { return s == first; }) !=
        state_buffer_.end()) {
      state_ = State::Error;
    } else {
      state_ = first;
    }

    state_buffer_.clear();
    scheduler_.enqueue(target_);
  }

}  // namespace rtm

template <>
struct std::formatter<rtm::Edge> : std::formatter<std::string> {
  auto format(const rtm::Edge& w, format_context& ctx) const {
    return std::formatter<std::string>::format(
        std::format("{}({}, {})", w.state(), w.last_update(), w.id()), ctx);
  }
};
