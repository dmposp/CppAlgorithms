#include <gtest/gtest.h>
#include "LRUCache.h"

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, BasicLRUTest) {
  LRUCache lru(1);

  // empty object has zero size
  EXPECT_EQ(lru.getSize(), 0);
}