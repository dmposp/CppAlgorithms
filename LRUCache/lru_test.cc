#include <gtest/gtest.h>
#include <string>

#include "doubly_list.h"
#include "lrucache.h"

/*
TEST(LruBasic, AddTest) {
  LRUCache<int, int> lru1(5);
  LRUCache<std::string, int> lru2(5);

  EXPECT_TRUE(lru1.add(12, 13));
  EXPECT_EQ(lru1.size(), 1);

  EXPECT_TRUE(lru2.add("apple", 13));
  EXPECT_TRUE(lru2.add("pear", 14));
  EXPECT_EQ(lru2.size(), 2);
}

TEST(LruBasic, GetTest) {
  LRUCache<int, int> lru1(5);
  LRUCache<std::string, int> lru2(5);

  EXPECT_TRUE(lru1.add(12, 13));
  EXPECT_EQ(lru1.get(12), 13);

  EXPECT_TRUE(lru2.add("apple", 13));
  EXPECT_TRUE(lru2.add("pear", 14));
  EXPECT_EQ(lru2.get("apple"), 13);
  EXPECT_EQ(lru2.get("pear"), 14);
}
*/

TEST(DoublyList, InsertTest) {
  Doubly_List<int, int> dlist;
  EXPECT_TRUE(dlist.insert(12, 13));
}

TEST(Lrucache, AddTest) {
  LRUCache<int, int> lru1(5);
  lru1.add(1, 2);
}

/*
TEST(LruBasic, ConstructorTest) {
  int capacity = 1;

  LRUCache lru(capacity);
  EXPECT_EQ(lru.getSize(), 0);
}

TEST(LruCapacity, LimitOneTest) {
  LRUCache lru(1);

  EXPECT_TRUE(lru.add(5, 15));
  EXPECT_TRUE(lru.add(6, 16));
  EXPECT_EQ(lru.getSize(), 1);
}

TEST(LruCapacity, LimitTwoTest) {
  LRUCache lru(2);

  EXPECT_TRUE(lru.add(5, 15));
  EXPECT_TRUE(lru.add(6, 16));
  EXPECT_TRUE(lru.add(7, 17));
  EXPECT_EQ(lru.getSize(), 2);
}

TEST(LruCapacity, LimitManyTest) {
  LRUCache lru(4);

  EXPECT_TRUE(lru.add(5, 15));
  EXPECT_TRUE(lru.add(6, 16));
  EXPECT_TRUE(lru.add(7, 17));
  EXPECT_TRUE(lru.add(8, 18));
  EXPECT_TRUE(lru.add(9, 19));
  EXPECT_TRUE(lru.add(5, 15));
  EXPECT_EQ(lru.getSize(), 4);
}

TEST(LruDuplicates, OneTest) {
  LRUCache lru(2);

  EXPECT_TRUE(lru.add(5, 15));
  EXPECT_FALSE(lru.add(5, 15));
  EXPECT_EQ(lru.getSize(), 1);

  EXPECT_TRUE(lru.add(6, 16));
  EXPECT_FALSE(lru.add(5, 15));
  EXPECT_EQ(lru.getSize(), 2);
}

TEST(LruBasics, LeastUsedTest) {
  LRUCache lru(4);

  EXPECT_TRUE(lru.add(5, 15));  // oldest entry
  EXPECT_TRUE(lru.add(6, 16));
  EXPECT_TRUE(lru.add(7, 17));
  EXPECT_TRUE(lru.add(8, 18));  // latest entry

  EXPECT_FALSE(lru.add(5, 15));
  EXPECT_FALSE(lru.add(6, 16));
  EXPECT_FALSE(lru.add(7, 17));
  EXPECT_FALSE(lru.add(8, 18));

  EXPECT_TRUE(lru.add(9, 19));

  EXPECT_FALSE(lru.get(5));
  EXPECT_TRUE(lru.get(9));

  EXPECT_TRUE(lru.add(1, 10));
  EXPECT_FALSE(lru.add(1, 10));
  EXPECT_TRUE(lru.add(5, 15));

  EXPECT_FALSE(lru.get(6));
  EXPECT_FALSE(lru.get(7));
  EXPECT_TRUE(lru.get(8));
  EXPECT_TRUE(lru.get(9));
  EXPECT_TRUE(lru.get(1));
  EXPECT_TRUE(lru.get(5));

  EXPECT_EQ(lru.getSize(), 4);
}
*/