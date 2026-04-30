#pragma once

#include <cstdint>
namespace rtm {
class port;
class edge {
 public:
  const uintptr_t id() { return _id; }
  const port* begin() { return _begin; }
  const port* end() { return _end; }

 private:
  uintptr_t _id;
  port* _begin;
  port* _end;
};
} // namespace rtm
