#pragma once

#include <ostream>

#include "parser/ast/nodes.hpp"

namespace ast {

class Ast {
 public:
  void set_program(Program p) { program_ = p; }

  const auto& program() const { return program_; }

  void dump(std::ostream& os);

 private:
  std::optional<Program> program_;
};

}  // namespace ast
