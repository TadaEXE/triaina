#include <iostream>
#include <vector>

#include "ds/gate.hpp"
#include "ds/trit.hpp"

int main(int argc, char* argv[]) {
  std::vector<ds::GateArm> arms = {{{"++"}, ds::Trit::Minus}, {{"__"}, ds::Trit::Plus}};

  for (auto& a : arms) {
    for (auto& b : a.pattern.expand_wildcards()) {
      std::cout << std::to_string(b) << " => " << std::to_string(a.result) << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
