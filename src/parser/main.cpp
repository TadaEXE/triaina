#include <cstdio>
#include <iostream>

#include "parser/ast/ast.hpp"
#include "driver.hpp"
#include "parser.tab.hpp"

int triaina_lex_init(yyscan_t* scanner);
int triaina_lex_destroy(yyscan_t scanner);
void triaina_set_in(FILE* in_str, yyscan_t scanner);

int main() {
  ast::Ast ast{};
  parser::Driver driver{ast};

  parser::location loc;
  loc.begin.line = loc.end.line = 1;
  loc.begin.column = loc.end.column = 1;
  driver.loc = &loc;

  if (triaina_lex_init(&driver.scanner) != 0) {
    std::cerr << "failed to init lexer\n";
    return 1;
  }

  triaina_set_in(stdin, driver.scanner);

  parser::Parser parser(driver);
  int rc = parser.parse();

  triaina_lex_destroy(driver.scanner);
  driver.scanner = nullptr;

  if (driver.had_error() || rc != 0) {
    for (auto& msg : driver.error_msg) {
      std::cerr << msg << "\n";
    }
    std::cerr << "=========================================" << "\n";
  }

  ast.dump(std::cout);
  return 0;
}
