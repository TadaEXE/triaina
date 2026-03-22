#include "parser/ast/ast.hpp"

#include <ostream>

#include "parser/ast/dump.hpp"

namespace ast {

void Ast::dump(std::ostream& os) {
  Dumper dumper{os};
  if (!program_) {
    os << "No program in this ast\n";
    return;
  }
  dumper.dump(*program_);
}

}  // namespace ast
