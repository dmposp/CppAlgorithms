#include <gtest/gtest.h>
#include "LRUCache.h"


TEST(BasicTests, GetSize) {
  int capacity = 1;

  // Empty Case
  LRUCache lru(capacity);
  EXPECT_EQ(lru.getSize(), 0);

  lru.insert(25);
  EXPECT_EQ(lru.getSize(), 1);

  lru.insert(35);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(FindTest, Empty) {
  LRUCache lru(0);

  EXPECT_FALSE(lru.find(100));
}

TEST(FindTest, SingleItem) {
  LRUCache lru(1);

  lru.insert(25);

  EXPECT_FALSE(lru.find(1));
  EXPECT_TRUE(lru.find(25));
}

TEST(FindTest, ManyItems) {
  LRUCache lru(3);

  lru.insert(25);
  lru.insert(-35);
  lru.insert(45);

  EXPECT_FALSE(lru.find(35));

  EXPECT_TRUE(lru.find(25));
  EXPECT_TRUE(lru.find(-35));
  EXPECT_TRUE(lru.find(45));

  lru.insert(45);
}
