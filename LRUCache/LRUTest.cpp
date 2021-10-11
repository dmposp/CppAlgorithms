#include <gtest/gtest.h>
#include "LRUCache.h"


TEST(LruCache, ConstructorTest) {
  int capacity = 1;

  LRUCache lru(capacity);
  EXPECT_EQ(lru.getSize(), 0);
}

TEST(LruCache, AddOneItemTest) {
  LRUCache lru(1);

  lru.put(5, 15);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LruCache, SingleCapacityTest) {
  LRUCache lru(1);
  EXPECT_EQ(lru.getSize(), 0);

  lru.put(5, 15);
  lru.put(6, 16);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LruCache, ManyCapacityTest) {
  LRUCache lru(2);
  EXPECT_EQ(lru.getSize(), 0);

  lru.put(5, 15);
  lru.put(6, 16);
  lru.put(6, 16);
  EXPECT_EQ(lru.getSize(), 2);
}
