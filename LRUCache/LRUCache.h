#ifndef LRUCache_H
#define LRUCache_H

#include "Node.h"

class LRUCache
{
    private:
        Node * head { 0 };
        Node * tail { 0 };
        int capacity;
        int size;

    public:
        LRUCache(const int capacity);

        void insert(const int value);

        bool find(const int value);

        void removeLeastUsedItem();

        int getSize();
};

#endif