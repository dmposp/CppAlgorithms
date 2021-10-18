#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include <unordered_map>

#include "doubly_list.h"


template <class K, class V>
class LRUCache {

public:
    LRUCache(const int cap): capacity(cap) {};  // Constructor init
    // destructor here

    bool add(K key, const V & value);

    V get(K key);  // bool get(K k, V& v)

    int size() const { return cacheMap.size(); };

private:
    std::unordered_map<K, V> cacheMap;
    Doubly_List<K, V> doublyList;
    int capacity;
};

#endif  // LRUCACHE_H_