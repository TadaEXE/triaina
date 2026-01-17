#include "parser/driver.hpp"
#include "parser.tab.hpp"

parser::Parser::symbol_type triaina_lex(yyscan_t yyscanner, parser::Driver& driver);

parser::Parser::symbol_type yylex(parser::Driver& driver) {
  return triaina_lex(driver.scanner, driver);
}
