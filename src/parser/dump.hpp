#pragma once
#include <iostream>

#include "ast.hpp"

inline void dump_attr(const AttrVal& v) {
  if (auto p = std::get_if<std::string>(&v)) {
    std::cout << '"' << *p << '"';
  } else if (auto p2 = std::get_if<long>(&v)) {
    std::cout << *p2;
  }
}

inline void dump_ast(const Node& n, int indent = 0) {
  for (int i = 0; i < indent; ++i) {
    std::cout << "  ";
  }

  std::cout << std::to_string(n.kind);

  if (!n.attrs.empty()) {
    std::cout << " {";
    bool first = true;
    for (const auto& [k, v] : n.attrs) {
      if (!first) std::cout << ", ";
      first = false;
      std::cout << k << ": ";
      dump_attr(v);
    }
    std::cout << "}";
  }

  std::cout << "\n";
  for (const auto& c : n.children) dump_ast(*c, indent + 1);
}
