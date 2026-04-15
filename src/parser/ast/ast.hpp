#pragma once

#include <ostream>
#include <variant>
#include <vector>

#include "parser/ast/nodes.hpp"

namespace ast {

class Ast {
 public:
  void set_program(Program p) { program_ = p; }

  const auto& program() const { return program_; }

  void dump(std::ostream& os);

  template <typename T>
  const std::vector<const T*> get_all() {
    std::vector<const T*> ts;
    if (program_) {
      for (auto& t : program_->item_list) {
        if (std::holds_alternative<T>(t.inner)) {
          ts.push_back(&std::get<T>(t.inner));
        }
      }
    }
    return ts;
  }

  template <typename T>
  const std::vector<T> copy_all() {
    std::vector<T> ts;
    if (program_) {
      for (auto& t : program_->item_list) {
        if (std::holds_alternative<T>(t.inner)) {
          ts.push_back(std::copy(std::get<T>(t.inner)));
        }
      }
    }
    return ts;
  }

 private:
  std::optional<Program> program_;
};

}  // namespace ast
