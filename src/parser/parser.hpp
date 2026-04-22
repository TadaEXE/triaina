#pragma once

#include "parser.tab.hpp"
#include "parser/driver.hpp"

namespace parser {

  class ParserWrapper {
   public:
   private:
    Driver driver_;
    location loc_;
  };
}  // namespace parser
