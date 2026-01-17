#pragma once

#include "parser/driver.hpp"
#include "parser.tab.hpp"

namespace parser {

class ParserWrapper {
public:

private:
  Driver driver_;
  location loc_;
};
}
