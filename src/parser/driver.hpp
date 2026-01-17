#pragma once
#include <string>
#include <unordered_map>

#include "ast/ast.hpp"
#include "parser/ast/arena.hpp"
#include "parser/ast/nodes.hpp"

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

namespace parser {

class location;

struct Driver {

  yyscan_t scanner = nullptr;

  ast::Ast ast;

  std::vector<std::string> error_msg;

  parser::location* loc = nullptr;

  std::string filename;
  std::unordered_map<std::string, size_t> file_ids;

  bool had_error() const;
  void set_program(ast::NodeId<ast::Program> p);
  void set_filename(std::string&& fn);

  size_t file_id_for(const std::string_view& fn);

  ast::Span span_from(const parser::location& l);

  void on_error(int line, int col, const std::string& msg);
};
}  // namespace parser
