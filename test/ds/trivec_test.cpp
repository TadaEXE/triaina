#include "ds/trivec.hpp"

#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "ds/errors.hpp"
#include "ds/trit.hpp"

namespace {

TEST(TriVec, FromStringParsesAndIgnoresInvalidSymbols) {
  ds::TriVec tv{"+x0-!"};
  EXPECT_EQ(std::to_string(tv), "+0-");
  ASSERT_EQ(tv.length(), 3u);
  EXPECT_EQ(tv.data()[0], ds::Trit::Minus);
  EXPECT_EQ(tv.data()[1], ds::Trit::Zero);
  EXPECT_EQ(tv.data()[2], ds::Trit::Plus);
}

TEST(TriVec, ResizeGrowsAndShrinksWhenNotFixed) {
  ds::TriVec tv{"+0-"};

  ASSERT_TRUE(tv.resize_to(5, ds::Trit::Plus).has_value());
  EXPECT_EQ(std::to_string(tv), "+++0-");
  EXPECT_EQ(tv.length(), 5u);

  ASSERT_TRUE(tv.resize_to(2).has_value());
  EXPECT_EQ(std::to_string(tv), "0-");
  EXPECT_EQ(tv.length(), 2u);
}

TEST(TriVec, ResizeFailsWhenFixed) {
  ds::TriVec tv{"+0-"};
  tv.fix_length();

  auto r = tv.resize_to(4, ds::Trit::Zero);
  ASSERT_FALSE(r.has_value());
  EXPECT_FALSE(r.error().msg.empty());
  EXPECT_EQ(std::to_string(tv), "+0-");
}

TEST(TriVec, TryLengthResolveWithNoFixedUsesMaxLen) {
  std::vector<ds::TriVec> tvs;
  tvs.emplace_back(ds::TriVec{"+0"});
  tvs.emplace_back(ds::TriVec{"+"});
  tvs.emplace_back(ds::TriVec{"-0+"});

  auto r = ds::TriVec::try_length_resolve(std::move(tvs));
  ASSERT_TRUE(r.has_value());
  ASSERT_EQ(r->size(), 3u);

  for (auto& tv : *r) {
    EXPECT_EQ(tv.length(), 3u);
  }

  EXPECT_EQ(std::to_string((*r)[0]), "0+0");
  EXPECT_EQ(std::to_string((*r)[1]), "00+");
  EXPECT_EQ(std::to_string((*r)[2]), "-0+");
}

TEST(TriVec, TryLengthResolveWithFixedResizesOthersToFixed) {
  std::vector<ds::TriVec> tvs;
  ds::TriVec fixed{"+0-"};
  fixed.fix_length();

  tvs.push_back(fixed);
  tvs.push_back(ds::TriVec{"+"});
  tvs.push_back(ds::TriVec{"-0+--"});

  auto r = ds::TriVec::try_length_resolve(std::move(tvs));
  ASSERT_TRUE(r.has_value());
  ASSERT_EQ(r->size(), 3u);

  for (auto& tv : *r) {
    EXPECT_EQ(tv.length(), 3u);
  }

  EXPECT_EQ(std::to_string((*r)[0]), "+0-");
  EXPECT_EQ(std::to_string((*r)[1]), "00+");
  EXPECT_EQ(std::to_string((*r)[2]), "+--");
}

TEST(TriVec, TryLengthResolveRejectsMultipleFixedDifferentLengths) {
  std::vector<ds::TriVec> tvs;
  ds::TriVec a{"+0-"};
  a.fix_length();
  ds::TriVec b{"+0"};
  b.fix_length();
  tvs.push_back(a);
  tvs.push_back(b);

  auto r = ds::TriVec::try_length_resolve(std::move(tvs));
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::InvalidArgs);
}

TEST(TriVec, TritwiseCutRejectsEmpty) {
  auto r = ds::TriVec::get_tritwise_cut({});
  ASSERT_FALSE(r.has_value());
  EXPECT_FALSE(r.error().msg.empty());
}

TEST(TriVec, TritwiseCutRejectsUnequalLengths) {
  std::vector<ds::TriVec> tvs;
  tvs.emplace_back(ds::TriVec{"+0-"});
  tvs.emplace_back(ds::TriVec{"+"});

  auto r = ds::TriVec::get_tritwise_cut(tvs);
  ASSERT_FALSE(r.has_value());
  EXPECT_FALSE(r.error().msg.empty());
}

TEST(TriVec, TritwiseCutProducesColumns) {
  std::vector<ds::TriVec> tvs;
  tvs.emplace_back(ds::TriVec{"+0-"});
  tvs.emplace_back(ds::TriVec{"-++"});

  auto r = ds::TriVec::get_tritwise_cut(tvs);
  ASSERT_TRUE(r.has_value());
  ASSERT_EQ(r->size(), 3u);

  EXPECT_EQ(std::to_string((*r)[0]), "+-");
  EXPECT_EQ(std::to_string((*r)[1]), "+0");
  EXPECT_EQ(std::to_string((*r)[2]), "-+");
}

TEST(TriMaVec, FromStringTracksWildcardsAndOnlyWildcards) {
  ds::TriMaVec a{"_+_0"};
  EXPECT_TRUE(a.has_wildcards());
  EXPECT_FALSE(a.only_wildcrads());

  ds::TriMaVec b{"__x__"};
  EXPECT_TRUE(b.has_wildcards());
  EXPECT_TRUE(b.only_wildcrads());
}

TEST(TriMaVec, ExpandWildcardsGeneratesAllCombinations) {
  ds::TriMaVec tmv{"_0_"};

  auto expanded = tmv.expand_wildcards();
  ASSERT_EQ(expanded.size(), 9u);

  std::set<std::string> got;
  for (auto& tv : expanded) got.insert(std::to_string(tv));

  std::set<std::string> expect = {
      "+0+", "+00", "+0-", "00+", "000", "00-", "-0+", "-00", "-0-",
  };

  EXPECT_EQ(got, expect);
}

TEST(TriMaVec, ExpandWildcardsNoWildcardsProducesSingleVector) {
  ds::TriMaVec tmv{"+0-"};
  auto expanded = tmv.expand_wildcards();
  ASSERT_EQ(expanded.size(), 1u);
  EXPECT_EQ(std::to_string(expanded[0]), "+0-");
}

}  // namespace
