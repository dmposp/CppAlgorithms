#include <iostream>
#include "Node.h"
#include "LRUCache.h"

using namespace std;


int main(int argc, char const *argv[])
{
    int capacity = 2;
    bool hasValue;

    LRUCache cache = LRUCache(capacity);
    cout << "size of cache = " << cache.getSize() << endl;

    cache.insert(125);
    //cout << "size of cache = " << cache.getSize() << endl;

    hasValue = cache.find(5);
    // cout << "Cache has value 5 " << hasValue << endl;

    // cache.insert(3);
    // cout << "size of cache = " << cache.getSize() << endl;

    // cache.insert(4);
    // cout << "size of cache = " << cache.getSize() << endl;

    return 0;
}
