#pragma once

#include "runtime/model/evaluator.hpp"
#include "runtime/model/port.hpp"

#include <cstdint>
#include <vector>
namespace rtm {
class node {
  public:
    node(const uintptr_t id, size_t max_inputs, size_t max_outputs)
        : _id(id), _max_inputs(max_inputs), _max_outputs(max_outputs) {}

    void enqueue_next();

    void replace_eval(evaluator& e);

    bool add_port(port& e);
    void remove_port(uintptr_t);

  public:
    auto& id() { return _id; }
    const auto& inputs() const { return _inputs; }
    const auto& output() const { return _outputs; }
    const auto* evaluator() const { return _evaluator; }

  private:
    const uintptr_t _id;
    std::vector<port*> _inputs;
    std::vector<port*> _outputs;
    rtm::evaluator* _evaluator;

    size_t _max_inputs;
    size_t _max_outputs;
};
} // namespace rtm
