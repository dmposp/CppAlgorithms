#include <gtest/gtest.h>
#include "LRUCache.h"

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(LRUCache, EmptyTest) {
  int capacity = 1;
  LRUCache lru(capacity);

  EXPECT_EQ(lru.getSize(), 0);
}

TEST(LRUCache, InsertTest) {
  int capacity = 1;
  LRUCache lru(capacity);
  lru.insert(25);

  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LRUCache, FindTest) {
  LRUCache lru(1);
  lru.insert(25);

  EXPECT_FALSE(lru.find(1));
  EXPECT_TRUE(lru.find(25));
}