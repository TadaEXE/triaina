#include "resty.hpp"

#include <any>
#include <string>

#include <gtest/gtest.h>

#include "ds/errors.hpp"

namespace {

TEST(Resty, UnexpectedWithDbgTagComparesByTag) {
  auto make = []() -> res::expected<int> {
    return res::unexpected("x", ds::DSError::InvalidArgs);
  };
  auto val = make();
  ASSERT_FALSE(val.has_value());
  EXPECT_TRUE(val.error() == ds::DSError::InvalidArgs);
  EXPECT_FALSE(val.error() == ds::DSError::Redefinition);
}

TEST(Resty, NestedUnexpectedPreservesOuterTag) {
  auto inner_u = res::unexpected("inner", ds::DSError::InvalidArgs);
  auto outer_u = res::unexpected(inner_u.error(), "outer",
                                 ds::DSError::MalformedStructure);

  EXPECT_TRUE(outer_u.error() == ds::DSError::MalformedStructure);
}

}  // namespace
