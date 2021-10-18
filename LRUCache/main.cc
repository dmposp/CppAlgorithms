#include <iostream>

#include "lrucache.h"


int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    LRUCache<int, int> lru1 = LRUCache<int, int>(5);
    lru1.add(a, b);

    return 0;
}
