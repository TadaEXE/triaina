#pragma once

#include <cstdint>
#include <forward_list>
#include <string>

#include "runtime/model/state.hpp"
namespace rtm {
class node;
class port {
 public:
  std::forward_list<node*> connected_nodes();

  void push_state(const state);

  void mark_dirty();

 public:
  enum class type {
    input,
    output,
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
  enum type _type;
  node* _binding;
  enum state _state;
  bool _dirty = true;
  std::forward_list<node*> _con_cache;
};
} // namespace rtm
