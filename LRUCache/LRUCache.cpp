#include "LRUCache.h"
#include "Node.h"

LRUCache::LRUCache(const int capacity)
{
    this->capacity = capacity;
    size = 0;
}

void LRUCache::insert(const int value)
{
    Node newNode = Node(value);

    if (size == 0)
    {
        head = &newNode;
        tail = &newNode;
        size += 1;
    }
    else
    {
        if (size == capacity)
        {
            removeLeastUsedItem();
        }
        else
        {
            size += 1;
        }

        tail->setNext(&newNode);
        newNode.setPrev(tail);
        tail = &newNode;
    }
}

bool LRUCache::find(const int value)
{
    Node *currentPtr = head;

    while (!currentPtr)
    {
        if (currentPtr->getData() == value)
        {
            if (size == 1 || currentPtr == tail)
            {
                currentPtr = 0;
                return true;
            }
            else
            {
                tail->setNext(currentPtr);

                if (head == currentPtr)
                {
                    head->setPrev(tail);
                    head = head->getNext();
                    head->setPrev(0);
                    currentPtr->setNext(0);
                    tail = currentPtr;

                    currentPtr = 0;
                    return true;
                }
                else
                {
                    // node is not on edges
                    //logic_error("Not implemented");
                }
            }
            return true;
        }

        // move pointer ahead to next node
        currentPtr = currentPtr->getNext();
    }

    return false;
}

void LRUCache::removeLeastUsedItem()
{
    Node *nextFirst = head->getNext();
    head->setNext(0);
    
    // Remove object pointed to located on the heap
    delete head;

    head = nextFirst;
    nextFirst = 0;
}

int LRUCache::getSize()
{
    return size;
}