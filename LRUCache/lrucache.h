#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include <unordered_map>
#include <list>

#include "doubly_list.h"


/**
 * Front of queue is oldest and back of queue is most recent.
 * [<- 1,2,3,4 <-]
 **/
template <class K, class V>
class LruCache {

public:
    using HashType = std::unordered_map<K, V>; // look up?

    LruCache(const int cap): capacity(cap) {};
    // add destructor here

    bool add(K key, const V &value) {

        if (containsKey(key)) {
            promote_to_back(key);
            return false;
        }

        if (size() >= capacity) {
            evict_front();
        }

        auto res = cacheMap.insert(std::make_pair(key, value));
        // assert(res.second);

        doublyList.push_back(key);

        return true;
    }

    /*
     * Returns whether cache contains an entry with specified key.
     */
    bool containsKey(K key) {
        return cacheMap.count(key) != 0;
    }

    size_t size() const {
        return cacheMap.size();
    };

    /*
     * Returns requested value or null from cache.
     */
    V get(K key) {
        return cacheMap[key];
    }

private:
    void evict_front() {
        if (doublyList.empty()) {
            return;
        }

        auto head = doublyList.front();
        cacheMap.erase(head);
        doublyList.pop_front();
    }

    void promote_to_back(K key) {
        if (doublyList.empty()) {
            return;
        }

        doublyList.remove(key);
        doublyList.push_back(key);
    }

private:
    std::unordered_map<K, V> cacheMap;
    //Doubly_List<K, V> doublyList;
    std::list<K> doublyList;
    int capacity;
};

#endif  // LRUCACHE_H_