#include <gtest/gtest.h>
#include "LRUCache.h"


TEST(LruCache, ConstructorTest) {
  int capacity = 1;

  LRUCache lru(capacity);
  EXPECT_EQ(lru.getSize(), 0);
}

TEST(LruCache, AddOneItemTest) {
  LRUCache lru(1);

  lru.add(5, 15);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LruCache, SingleCapacityTest) {
  LRUCache lru(1);
  EXPECT_EQ(lru.getSize(), 0);

  lru.add(5, 15);
  lru.add(6, 16);
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LruCache, ManyCapacityTest) {
  LRUCache lru(2);
  EXPECT_EQ(lru.getSize(), 0);

  lru.add(5, 15);
  lru.add(6, 16);
  lru.add(6, 16);
  EXPECT_EQ(lru.getSize(), 2);
}

TEST(LruCache, DuplicatesTest) {
  LRUCache lru(4);

  lru.add(6, 16);
  lru.add(6, 16);
  lru.add(6, 16);
  EXPECT_EQ(lru.getSize(), 1);

  lru.add(7, 17);
  EXPECT_EQ(lru.getSize(), 2);
}