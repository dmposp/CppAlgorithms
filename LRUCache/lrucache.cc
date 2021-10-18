#include <iostream>
#include <string>

#include "doubly_list.h"
#include "lrucache.h"

template<class K, class V>
bool LRUCache<K, V>::add(K key, const V & value) {


    /* Fix here */
    auto node = doublyList.insert(key, value);

    // TODO: hold address
    //cacheMap[key] = doublyList.insert(key, value);
    // cacheMap[key] = val;

    return true;
}

template<class K, class V>
V LRUCache<K, V>::get(K key) {
    return cacheMap[key];
}

template class LRUCache<int, Doubly_List<int, int>::Node*>;
//template class LRUCache<std::string, int>;

/**
 * Insert item only if the key is not already present.
 * When the cache is full, remove least recently used item
 * before inserting the item.
 *
 * @param[in] key identifier for quick lookup
 * @param[in] value holds content
 * @return true or false
 */
// bool LRUCache::add(int key, int value)
// {
//     if (cacheMap.find(key) == cacheMap.end())
//     {
//         // K is not in cache. Add new entry.
//         Node* newNode = new Node(key, value);

//         if (cacheMap.empty())
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else if (cacheMap.size() == capacity)
//         {
//             // Remove least recently used item
//             cacheMap.erase(tail->getKey());

//             if (cacheMap.empty())
//             {
//                 // List has one item
//                 delete tail;
//                 head = newNode;
//                 tail = newNode;
//             }
//             else
//             {
//                 // List has many items
//                 Node* prevNode = tail->getPrev();

//                 delete tail;
//                 tail = prevNode;
//                 tail->setNext(0);

//                 head->setPrev(newNode);
//                 newNode->setNext(head);
//                 head = newNode;
//             }
//         }
//         else
//         {
//             // List has not reached its limit yet.
//             // Safe to directly add item.
//             head->setPrev(newNode);
//             newNode->setNext(head);
//             head = newNode;
//         }

//         cacheMap[key] = newNode;
//         return true;
//     }

//     return false;
// }

// /**
//  * Retrieve item only if present otherwise return -1.
//  * Item retrieved will be placed in front of the list.
//  *
//  * @param[in] key identifier for quick lookup
//  * @return value for key
//  */
// bool LRUCache::get(int key)
// {
//     if (cacheMap.find(key) == cacheMap.end())
//     {
//         return false;
//     }

//     if (cacheMap[key] == head)
//     {
//         return true;
//     }

//     head->setPrev(cacheMap[key]);

//     if (cacheMap[key] == tail)
//     {
//         cacheMap[key]->setNext(head);
//         tail = cacheMap[key]->getPrev();
//         tail->setNext(0);
//         cacheMap[key]->setPrev(0);
//         head = cacheMap[key];
//     }
//     else
//     {
//         // Node is in middle of list
//         cacheMap[key]->getPrev()->setNext(cacheMap[key]->getNext());
//         cacheMap[key]->getNext()->setPrev(cacheMap[key]->getPrev());
//         cacheMap[key]->setPrev(0);
//         cacheMap[key]->setNext(head);
//         head = cacheMap[key];
//     }

//     return cacheMap[key]->getValue();
// }

// int LRUCache::getSize()
// {
//     return cacheMap.size();
// }