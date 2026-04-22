#pragma once

#include <cstdint>
#include <string>

namespace rtm {
  enum class port_type {
    in,
    out,
  };

  class edge;

  class port {
   private:
    uint64_t _id;
    std::string _label;
    port_type _type;
    edge* _binding;
  };

}  // namespace rtm
