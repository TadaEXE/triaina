#pragma once

#include <ranges>
#include <string>
#include <vector>

#include "ds/trit.hpp"

namespace ds {

class TriMaVec;

class TriVec : public std::vector<Trit> {
 public:
  TriVec() = default;
  /// @brief Convert string to trit vector (ignores all invalid symbols)
  explicit TriVec(std::string& input);
  // Something like:
  // static std::optional<TriVec> from_match_vec(TriMaVec& tmv, std::optional<Trit> wc);
  // Would be better but we will ge trust me bro path
  TriVec(TriMaVec& tmv, Trit t = Trit::Zero);
};

class TriMaVec : public std::vector<TritMatch> {
 public:
  TriMaVec() = default;
  /// @brief Convert string to tritmatch vector (ignores all invalid symbols)
  explicit TriMaVec(std::string& input);

  std::vector<TriVec> expand_wildcards();

  bool has_wildcards() const { return has_wildcards_; }

  bool only_wildcrads() const { return only_wildcrads_; }

 private:
  bool has_wildcards_{true};
  bool only_wildcrads_{true};
};

}  // namespace ds

namespace std {
static constexpr std::string to_string(ds::TriVec tv) {
  std::string res = "";
  for (auto& t : tv | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}

static constexpr std::string to_string(ds::TriMaVec tmv) {
  std::string res = "";
  for (auto& t : tmv | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}
}  // namespace std
