#include "runtime/model/node.hpp"

#include <algorithm>

namespace rtm {
  void Node::evaluate(uint64_t step_count) {
    std::for_each(outputs_.begin(), outputs_.end(),
                  [&](auto& w) { scheduler_.enqueue(w); });
  }

}  // namespace rtm
