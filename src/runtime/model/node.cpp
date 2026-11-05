#include "runtime/model/node.hpp"

#include <cstdint>
#include <vector>

#include "runtime/model/evaluator.hpp"
#include "runtime/model/port.hpp"

namespace rtm {
void Node::enqueue_next() {}
void Node::replace_eval(rtm::Evaluator& e) {}
bool Node::add_port(Port& p) {
  if (p.type() == Port::Type::Input) {
    _inputs.push_back(&p);
    return true;
  }

  return false;
}
void Node::remove_port(uintptr_t id) {}
} // namespace rtm
