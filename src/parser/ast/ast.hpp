#pragma once

#include <ostream>
#include <utility>

#include "parser/ast/arena.hpp"
#include "parser/ast/dump.hpp"
#include "parser/ast/nodes.hpp"

namespace ast {

class Ast {
 public:
  template <class T, class... Args>
    requires requires(Arena::Allowed a) { std::get<T>(a); }
  NodeId<T> make_id(Args&&... args) {
    return arena_.template emplace<T>(std::forward<Args>(args)...);
  }

  template <class T>
  T& get(NodeId<T> id) {
    return arena_[id];
  }

  void set_program(NodeId<Program> p) { program_ = p; }

  const auto& program() const { return program_; }
  const auto& arena() const { return arena_; }

  void dump(std::ostream& os);

 private:
  Arena arena_;
  std::optional<NodeId<Program>> program_;
};

}  // namespace ast
