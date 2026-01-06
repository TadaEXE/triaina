#include "ds/vectors.hpp"

#include "ds/trit.hpp"

namespace ds {

TriVec::TriVec(std::string input) {
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        data_.push_back(Trit::Plus);
        break;
      case '0':
        data_.push_back(Trit::Zero);
        break;
      case '-':
        data_.push_back(Trit::Minus);
        break;
      default:
        continue;
    }
  }
}

TriVec::TriVec(TriMaVec& tmv) {
  for (auto& tm : tmv.data()) {
    switch (tm) {
      case TritMatch::Plus:
        data_.push_back(Trit::Plus);
        break;
      case TritMatch::Zero:
        data_.push_back(Trit::Zero);
        break;
      case TritMatch::Minus:
        data_.push_back(Trit::Minus);
        break;
      default:
        continue;
    }
  }
}

TriMaVec::TriMaVec(std::string input) {
  only_wildcrads_ = true;
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        data_.push_back(TritMatch::Plus);
        only_wildcrads_ = false;
        break;
      case '0':
        data_.push_back(TritMatch::Zero);
        only_wildcrads_ = false;
        break;
      case '-':
        data_.push_back(TritMatch::Minus);
        only_wildcrads_ = false;
        break;
      case '_':
        data_.push_back(TritMatch::Wild);
        has_wildcards_ = true;
        break;
      default:
        continue;
    }
  }
}

std::vector<TriMaVec> TriMaVec::resolve_wildcards(std::vector<TriMaVec>& tmvs, size_t i) const {
  std::vector<TriMaVec> res;
  const auto& test = tmvs[0].data();
  if (i >= test.size()) return tmvs;

  size_t j = i;
  for (; j < test.size(); ++j) {
    if (test[j] == TritMatch::Wild) { break; }
  }
  if (j >= test.size()) return tmvs;

  for (auto& tmv : tmvs) {
    auto tmp = tmv;
    tmp.data_[j] = TritMatch::Plus;
    res.push_back(tmp);
    tmp.data_[j] = TritMatch::Zero;
    res.push_back(tmp);
    tmp.data_[j] = TritMatch::Minus;
    res.push_back(tmp);
  }

  return resolve_wildcards(res, j);
}

std::vector<TriVec> TriMaVec::expand_wildcards() const {
  std::vector<TriMaVec> tmp({*this});
  auto fin = resolve_wildcards(tmp);
  std::vector<TriVec> res;
  for (auto& tmv : fin) {
    res.push_back(TriVec{tmv});
  }
  return res;
}

}  // namespace ds
