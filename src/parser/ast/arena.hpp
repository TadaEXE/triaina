#pragma once

#include <utility>
#include <variant>

#include "nodes.hpp"

namespace ast {

class Arena {
 public:
  using Allowed = std::variant<Expr, SourceSegment, Scope, Program>;

  template <class T, class... Args>
    requires requires(Allowed a) { std::get<T>(a); }
  NodeId<T> emplace(Args&&... args) {
    nodes_.emplace_back(T{std::forward<Args>(args)...});
    return NodeId<T>{nodes_.size() - 1};
  }

  template <class T>
  T& get(const NodeId<T>& id) {
    return std::get<T>(nodes_[id.id]);
  }

  template <class T>
  const T& get(const NodeId<T>& id) const {
    return std::get<T>(nodes_[id.id]);
  }

  template <class T>
  T& operator[](const NodeId<T>& id) {
    return get<T>(id);
  }

  template <class T>
  const T& operator[](const NodeId<T>& id) const {
    return get<T>(id);
  }

  size_t size() const { return nodes_.size(); }

  template <class F>
  void visit_node(size_t i, F&& f) const {
    std::visit(std::forward<F>(f), nodes_[i]);
  }

 private:
  std::vector<Allowed> nodes_;
};

}  // namespace ast
