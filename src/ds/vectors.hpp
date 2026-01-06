#pragma once

#include <ranges>
#include <string>
#include <vector>

#include "ds/trit.hpp"

namespace ds {

class TriMaVec;

class TriVec {
 public:
  TriVec() = default;
  TriVec(const TriVec&) = default;
  TriVec(TriVec&&) = default;
  TriVec& operator=(const TriVec&) = default;
  TriVec& operator=(TriVec&&) = default;

  /// @brief Convert string to trit vector (ignores all invalid symbols)
  TriVec(std::string input);
  // Something like:
  // static std::optional<TriVec> from_match_vec(TriMaVec& tmv, std::optional<Trit> wc);
  // Would be better but we will ge trust me bro path
  explicit TriVec(TriMaVec& tmv);

  const auto& data() { return data_; }

 private:
  std::vector<Trit> data_;
};

class TriMaVec {
 public:
  TriMaVec() = default;
  TriMaVec(const TriMaVec&) = default;
  TriMaVec(TriMaVec&&) = default;
  TriMaVec& operator=(const TriMaVec&) = default;
  TriMaVec& operator=(TriMaVec&&) = default;

  /// @brief Convert string to tritmatch vector (ignores all invalid symbols)
  TriMaVec(std::string input);

  std::vector<TriVec> expand_wildcards() const;

  bool has_wildcards() const { return has_wildcards_; }

  bool only_wildcrads() const { return only_wildcrads_; }

  const auto& data() { return data_; }

 private:
  std::vector<TritMatch> data_;
  bool has_wildcards_{false};
  bool only_wildcrads_{false};

  std::vector<TriMaVec> resolve_wildcards(std::vector<TriMaVec>& tmvs, size_t i = 0) const;
};

}  // namespace ds

namespace std {
static constexpr std::string to_string(ds::TriVec tv) {
  std::string res = "";
  for (auto& t : tv.data() | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}

static constexpr std::string to_string(ds::TriMaVec tmv) {
  std::string res = "";
  for (auto& t : tmv.data() | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}
}  // namespace std
