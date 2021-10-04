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

TEST(FindTest, SingleItem) {
  LRUCache lru(1);
  lru.insert(25);

  EXPECT_FALSE(lru.find(1));
  EXPECT_TRUE(lru.find(25));
}

TEST(FindTest, FirstItem) {
  LRUCache lru(3);

  lru.insert(25);
  lru.insert(35);
  lru.insert(45);

  EXPECT_TRUE(lru.find(25));
}

TEST(FindTest, SecondItem) {
  LRUCache lru(3);

  lru.insert(25);
  lru.insert(35);
  lru.insert(45);

  EXPECT_FALSE(lru.find(1));
  EXPECT_TRUE(lru.find(35));
}

TEST(FindTest, ThirdItem) {
  LRUCache lru(3);

  lru.insert(25);
  lru.insert(35);
  lru.insert(45);

  EXPECT_FALSE(lru.find(1));
  EXPECT_TRUE(lru.find(45));
}

TEST(LRUCache, CapacityTest1) {
  LRUCache lru(1);

  lru.insert(25);
  EXPECT_EQ(lru.getSize(), 1);

  lru.insert(35);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LRUCache, CapacityTest2) {
  LRUCache lru(3);

  lru.insert(15);
  EXPECT_EQ(lru.getSize(), 1);

  lru.insert(25);
  EXPECT_EQ(lru.getSize(), 2);

  lru.insert(35);
  EXPECT_EQ(lru.getSize(), 3);

  lru.insert(45);
  EXPECT_EQ(lru.getSize(), 3);
}
