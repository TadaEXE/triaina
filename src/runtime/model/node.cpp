#include "runtime/model/node.hpp"

#include <cstdint>
#include <vector>

#include "runtime/model/evaluator.hpp"
#include "runtime/model/port.hpp"

namespace rtm {
void node::enqueue_next() {}
void node::replace_eval(rtm::evaluator& e) {}
bool node::add_port(port& p) {
  if (p.type() == port::type::input) {
    _inputs.push_back(&p);
    return true;
  }

  return false;
}
void node::remove_port(uintptr_t id) {}
} // namespace rtm
