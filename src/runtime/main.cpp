#include <iostream>
#include <vector>

#include "ds/gate.hpp"
#include "ds/trit.hpp"
#include "ds/trivec.hpp"
#include "resty.hpp"

enum class FooError : uint8_t {
  None = 0,
  One = 1,
  Two = 2,
};

enum class BarError : uint8_t {
  One = 1,
  Three = 3,
  Four = 4,
};

int main(int argc, char* argv[]) {
  // std::vector<ds::GateArm> arms = {{{"++"}, ds::Trit::Minus},
  //                                  {{"__"}, ds::Trit::Plus},
  //                                  {{"-_"}, ds::Trit::Zero}};
  // ds::Gate g(2);
  // if (auto r = g.init(arms); !r.has_value()) {
  //   std::cout << r.error() << std::endl;
  //   return 1;
  // }
  //
  // std::cout << std::to_string(g.eval({"++"}).value()) << std::endl;

  // ds::TriVec a("++");
  // ds::TriVec b("--");
  // b.fix_length();
  //
  // if (auto r = a.resize_to(4); !r.has_value()) {
  //   std::cout << "Error " << r.error() << std::endl;
  //   return 1;
  // }
  // std::cout << "Resized a " << std::to_string(a) << std::endl;
  // if (auto r = a.resize_to(2); !r.has_value()) {
  //   std::cout << "Error " << r.error() << std::endl;
  //   return 1;
  // }
  //
  // std::cout << "Resized a " << std::to_string(a) << std::endl;
  //
  // if (auto r = b.resize_to(4); !r.has_value()) {
  //   std::cout << "Error " << r.error() << std::endl;
  //   return 1;
  // }
  //
  // std::cout << "Resized b " << std::to_string(b) << std::endl;

  res::Error e1{"hello", FooError::One};

  if (FooError::One == e1) {
    std::cout << e1.msg << std::endl;
  }

  return 0;
}
