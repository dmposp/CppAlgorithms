#include <gtest/gtest.h>
#include <string>

#include "doubly_list.h"
#include "lrucache.h"


TEST(Basic, Initialize) {
  LruCache<int, int> lru1(3);
  EXPECT_EQ(lru1.size(), 0);
}

TEST(Cache_Add, SingleItem) {
  LruCache<int, int> lru1(3);

  EXPECT_TRUE(lru1.add(12, 13));
  EXPECT_TRUE(lru1.containsKey(12));
  EXPECT_EQ(lru1.size(), 1);
}

TEST(LeastUsedItem, WithoutPromotion) {
  LruCache<int, int> lru1(2);

  lru1.add(11, 12);  // old
  lru1.add(13, 14);
  lru1.add(15, 16);  // new

  EXPECT_EQ(lru1.size(), 2);
  EXPECT_FALSE(lru1.containsKey(11));
  EXPECT_TRUE(lru1.containsKey(13));
  EXPECT_TRUE(lru1.containsKey(15));
}

TEST(LeastUsedItem, WithPromotion) {
  LruCache<int, int> lru1(2);

  lru1.add(11, 12);
  lru1.add(13, 14);
  lru1.add(11, 12);  // promote to new

  EXPECT_EQ(lru1.size(), 2);

  lru1.add(15, 16);

  EXPECT_EQ(lru1.size(), 2);
  EXPECT_TRUE(lru1.containsKey(11));
  EXPECT_FALSE(lru1.containsKey(13));
  EXPECT_TRUE(lru1.containsKey(15));
}

TEST(Size, Duplicates) {
  LruCache<int, int> lru1(2);

  lru1.add(11, 12);
  lru1.add(11, 12);
  lru1.add(11, 12);

  EXPECT_EQ(lru1.size(), 1);
}

TEST(Get, ItemExists) {
  LruCache<int, int> lru1(2);

  lru1.add(11, 12);
  lru1.add(15, 16);

  EXPECT_EQ(lru1.get(11), 12);
  EXPECT_EQ(lru1.get(15), 16);
}

TEST(Get, ItemDoesNotExists) {
  LruCache<int, int> lru1(2);
  LruCache<std::string, int> lru2(2);

  EXPECT_EQ(lru1.get(11), 0);  // correct way?
  EXPECT_FALSE(lru2.get("apple"));
}
