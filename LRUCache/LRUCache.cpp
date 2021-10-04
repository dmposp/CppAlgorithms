#include "LRUCache.h"
#include "Node.h"
#include <iostream>

LRUCache::LRUCache(const int capacity)
{
    this->capacity = capacity;
    size = 0;
}

void LRUCache::insert(const int value)
{
    Node newNode = Node(value);
    std::cout << "New node address: " << &newNode << std::endl;
    if (size == 0)
    {
        head = &newNode;
        tail = &newNode;
        size += 1;
        std::cout << "head " << head << std::endl;
        std::cout << "tail " << tail << std::endl;
        std::cout << "value in node " << head->getData() << std::endl;
        std::cout << "prev " << head->getPrev() << std::endl;
        std::cout << "next " << head->getNext() << std::endl;
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

    return;
}

bool LRUCache::find(const int value)
{
    Node *currentPtr = head;
    std::cout << "value = " << value << std::endl;
    std::cout << "head data" << head->getData() << std::endl;

    while (currentPtr)
    {
        std::cout << "current pointer address " << currentPtr << std::endl;
        std::cout << head->getData() << std::endl;
        std::cout << head->getNext() << std::endl;
        

        if (currentPtr->getData() == value)
        {
            if (size == 1 || currentPtr == tail)
            {
                std::cout << "Found with one" << std::endl;
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
        return false;
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