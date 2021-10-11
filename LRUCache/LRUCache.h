#ifndef LRUCache_H
#define LRUCache_H

#include "Node.h"
#include <unordered_map>


class LRUCache
{
    private:
        int capacity;
        std::unordered_map<int, Node*> cacheMap;
        Node* head;
        Node* tail;

    public:
        LRUCache(const int capacity);

        bool add(int key, int value);

        // bool get(Key k, Value& v)
        bool get(const int key);

        int getSize();
};

#endif