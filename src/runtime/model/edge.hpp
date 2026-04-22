#pragma once

#include <cstdint>

namespace rtm {
  class port;

  class edge {
   private:
    uint64_t _id;
    uint64_t _form;
    uint64_t _to;
  };
}  // namespace rtm
