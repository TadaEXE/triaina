#include <gtest/gtest.h>

TEST(Placeholder, Passes) {
  SUCCEED();
}

TEST(Placeholder, Fails) {
  FAIL() << "Intentional placeholder failure; replace with a real test.";
}
