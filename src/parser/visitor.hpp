#pragma once

#include <iostream>

#include "ast.hpp"

class SomeVisitor {
 public:
  template <NodeType T>
  void visit(Node& n) {
    std::cout << "Visiting unspecialized " << std::to_string(T) << std::endl;
  }
};

template <>
inline void SomeVisitor::visit<NodeType::Scope>(Node& n) {
  std::cout << "Visiting Scope" << std::endl;
}
