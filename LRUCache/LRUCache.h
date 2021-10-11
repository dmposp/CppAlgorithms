#ifndef LRUCache_H
#define LRUCache_H

#include "Node.h"
#include <unordered_map>

//typedef ;

class LRUCache
{
    private:
        int capacity;
        std::unordered_map<int, Node*> cacheMap;
        Node* head;
        Node* tail;

    public:
        LRUCache(const int capacity);

        void put(int key, int value);

        int get(const int key);

        int getSize();
};

#endif