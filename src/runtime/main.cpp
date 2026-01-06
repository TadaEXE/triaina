#include <iostream>
#include <vector>

#include "ds/gate.hpp"
#include "ds/trit.hpp"

int main(int argc, char* argv[]) {
  std::vector<ds::GateArm> arms = {{{"++"}, ds::Trit::Minus},
                                   {{"__"}, ds::Trit::Plus},
                                   {{"-_"}, ds::Trit::Zero}};
  ds::Gate g(2);
  if (auto r = g.init(arms); !r.has_value()) {
    std::cout << r.error() << std::endl;
    return 1;
  }

  std::cout << std::to_string(g.eval({"++"}).value()) << std::endl;
  return 0;
}
