#pragma once

#include <cstddef>
#include <format>
#include <span>
#include <vector>

#include "ds/errors.hpp"
#include "ds/trivec.hpp"
#include "resty.hpp"

namespace ds {

class Bus {
 public:
  Bus() = default;
  explicit Bus(const std::vector<TriVec>& items) : items_(items) {}
  explicit Bus(const std::span<TriVec>& items)
      : items_(items.begin(), items.end()) {}

  size_t size() const { return items_.size(); }
  bool empty() const { return items_.empty(); }

  const TriVec& at(size_t i) const { return items_.at(i); }
  TriVec& at(size_t i) { return items_.at(i); }

  const TriVec& operator[](size_t i) const { return at(i); }
  TriVec& operator[](size_t i) { return at(i); }

  const auto& items() const { return items_; }
  auto& items() { return items_; }

  res::expected<TriVec> get_ref(size_t k) {
    if (k >= items_.size()) {
      return res::unexpected(std::format("Busref {} is out-of-range.", k),
                             DSError::InvalidArgs);
    }
    return at(k);
  }

 private:
  std::vector<TriVec> items_;
};
}  // namespace ds
