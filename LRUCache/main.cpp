#include <iostream>
#include "Node.h"
#include "LRUCache.h"

using namespace std;


int main(int argc, char const *argv[])
{
    int capacity = 2;

    LRUCache cache = LRUCache(capacity);
    cout << "size of cache = " << cache.getSize() << endl;

    // cache.insert(5);
    // cout << "size of cache = " << cache.getSize() << endl;

    return 0;
}
