#include "ds/vectors.hpp"

namespace ds {

TriVec::TriVec(std::string input) {
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        this->push_back(Trit::Plus);
        break;
      case '0':
        this->push_back(Trit::Zero);
        break;
      case '-':
        this->push_back(Trit::Minus);
        break;
      default:
        continue;
    }
  }
}

TriVec::TriVec(TriMaVec& tmv, Trit t) {
  for (auto& tm : tmv) {
    switch (tm) {
      case TritMatch::Plus:
        this->push_back(Trit::Plus);
        break;
      case TritMatch::Zero:
        this->push_back(Trit::Zero);
        break;
      case TritMatch::Minus:
        this->push_back(Trit::Minus);
        break;
      case TritMatch::Wild:
        this->push_back(t);
        break;
      default:
        continue;
    }
  }
}

TriMaVec::TriMaVec(std::string input) {
  has_wildcards_ = false;
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        this->push_back(TritMatch::Plus);
        only_wildcrads_ = false;
        break;
      case '0':
        this->push_back(TritMatch::Zero);
        only_wildcrads_ = false;
        break;
      case '-':
        this->push_back(TritMatch::Minus);
        only_wildcrads_ = false;
        break;
      case '_':
        this->push_back(TritMatch::Wild);
        has_wildcards_ = true;
        break;
      default:
        continue;
    }
  }
}

std::vector<TriVec> TriMaVec::expand_wildcards() {
  std::vector<TriVec> res;
  if (has_wildcards_) {
    res.push_back({*this, Trit::Minus});
    res.push_back({*this, Trit::Zero});
    res.push_back({*this, Trit::Plus});
  } else {
    res.push_back({*this});
  }
  return res;
}

}  // namespace ds
