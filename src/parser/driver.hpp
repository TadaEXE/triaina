#pragma once
#include <string>

#include "ast.hpp"

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

namespace parser {
class location;
}

struct Driver {
  yyscan_t scanner = nullptr;
  NodePtr program;

  bool had_error() { return !error_msg.empty(); }

  std::vector<std::string> error_msg;

  parser::location* loc = nullptr;

  void set_program(NodePtr p) { program = std::move(p); }

  void on_error(int line, int col, const std::string& msg) {
    error_msg.push_back(std::to_string(line) + ":" + std::to_string(col) + ": " + msg);
  }
};
