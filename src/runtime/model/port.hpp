#pragma once

#include <cstdint>
#include <forward_list>
#include <string>

#include "runtime/model/state.hpp"

namespace rtm {

class Node;

class Port {
 public:
  std::forward_list<Node*> connected_nodes();

  void push_state(const State);

  void mark_dirty();

 public:
  enum class Type {
    Input,
    Output,
  };

 public:
  const uintptr_t id() const { return _id; }
  const auto& label() const { return _label; }
  const auto type() const { return _type; }
  const auto* binding() const { return _binding; }
  const auto state() const { return _state; }

 private:
  uintptr_t _id;
  std::string _label;
  Node _node();
  Type _type;
  Node* _binding;
  State _state;
  bool _dirty = true;
  std::forward_list<Node*> _con_cache;
};
} // namespace rtm
