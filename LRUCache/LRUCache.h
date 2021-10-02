#ifndef LRUCache_H
#define LRUCache_H

#include "Node.h"

class LRUCache
{
    private:
        Node *head;
        Node *tail;
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