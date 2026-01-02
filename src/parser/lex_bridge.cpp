#include "driver.hpp"
#include "parser.tab.hpp"

parser::Parser::symbol_type triaina_lex(yyscan_t yyscanner, Driver& driver);

parser::Parser::symbol_type yylex(Driver& driver) {
  return triaina_lex(driver.scanner, driver);
}
