#include "LRUCache.h"
#include "Node.h"
#include <iostream>


LRUCache::LRUCache(const int capacity)
{
    this->capacity = capacity;
    cacheMap.reserve(2);
    head = 0;
    tail = 0;
}

/**
 * Insert item only if the key is not already present.
 * When the cache is full, remove least recently used item
 * before inserting the item.
 *
 * @param[in] key identifier for quick lookup
 * @param[in] value holds content
 */
void LRUCache::put(int key, int value)
{
    if (cacheMap.find(key) == cacheMap.end())
    {
        // Create new entry
        Node* newNode = new Node(key, value);

        if (cacheMap.size() == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else if (cacheMap.size() == capacity)
        {
            // Full cache, remove least recently used item in list
            int leastUsedKey = tail->getKey();

            Node* prevNode = tail->getPrev();

            // Delete last node from the heap
            delete tail;
            tail = prevNode;
            tail->setNext(0);

            // Remove from cacheMap
            cacheMap.erase(leastUsedKey);
        }
        else
        {
            head->setPrev(newNode);
            newNode->setNext(head);
            head = newNode;
        }

        cacheMap[key] = newNode;
    }
}

/**
 * Retrieve item only if present otherwise return -1.
 * Item retrieved will be placed in front of the list.
 *
 * @param[in] key identifier for quick lookup
 * @return value for key
 */
int LRUCache::get(int key)
{
    if (!cacheMap[key])
    {
        return -1;
    }

    if (cacheMap[key] == head || (cacheMap.size() == 1 && cacheMap[key]))
    {
        return cacheMap[key]->getValue();
    }

    head->setPrev(cacheMap[key]);

    if (cacheMap[key] == tail)
    {
        cacheMap[key]->setNext(head);
        tail = cacheMap[key]->getPrev();
        tail->setNext(0);
        cacheMap[key]->setPrev(0);
        head = cacheMap[key];
    }
    else
    {
        // Node is in middle of list
        cacheMap[key]->getPrev()->setNext(cacheMap[key]->getNext());
        cacheMap[key]->getNext()->setPrev(cacheMap[key]->getPrev());
        cacheMap[key]->setPrev(0);
        cacheMap[key]->setNext(head);
        head = cacheMap[key];
    }

    return cacheMap[key]->getValue();
}

int LRUCache::getSize()
{
    return cacheMap.size();
}