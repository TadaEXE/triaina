#pragma once

#include <algorithm>
#include <cstdint>
#include <list>

#include "runtime/model/edge.hpp"
#include "runtime/model/node.hpp"
#include "runtime/model/port.hpp"
namespace rtm {
class PseudoGraph {
 public:
  template <typename T>
  void add(T* ptr) {
    inner<T>().push_back(ptr);
  }
  template <typename T>
  bool remove(T* ptr) {
    auto& v = inner<T>();
    auto it = std::find(v.begin(), v.end(), ptr);
    if (it == v.end())
      return false;
    v.erase(it);
    return true;
  }
  template <typename T>
  T* find(uintptr_t id) {
    auto& v = inner<T>();
    auto it = std::find_if(v.begin(), v.end(),
                           [id](auto* i) { return i->id() == id; });

    if (it == v.end())
      return nullptr;
    return *it;
  }

 public:
  const auto node_count() const { return _nodes.size(); }
  const auto edge_count() const { return _edges.size(); }
  const auto port_count() const { return _ports.size(); }

 private:
  template <typename T>
  constexpr auto& inner() {
    if constexpr (std::is_same_v<T, Node>)
      return _nodes;
    else if constexpr (std::is_same_v<T, Edge>)
      return _edges;
    else if constexpr (std::is_same_v<T, Port>)
      return _ports;
    else
      static_assert(false, "unsupported type");
  }

 private:
  std::list<Node*> _nodes;
  std::list<Edge*> _edges;
  std::list<Port*> _ports;
};
} // namespace rtm
