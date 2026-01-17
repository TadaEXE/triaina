#include "parser/ast/ast.hpp"

#include <ostream>

#include "parser/ast/dump.hpp"

namespace ast {

void Ast::dump(std::ostream& os) {
  Dumper dumper{arena_, os};
  if (!program_) {
    os << "No program in this ast, dumping " << arena_.size()
       << " existing nodes." << std::endl;
    dumper.dump_arena();
    return;
  }
  dumper.dump_program(*program_);
}

}  // namespace ast
