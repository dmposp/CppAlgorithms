#include <iostream>
//#include <unordered_map>
#include "Node.h"
#include "LRUCache.h"

using namespace std;


int main(int argc, char const *argv[])
{
    LRUCache cache = LRUCache(3);

    // std::unordered_map<int, int> cacheMap;

    // std::cout << "Size in map = " << cacheMap.size() << endl;

    // std::unordered_map<int, int>::const_iterator got = cacheMap.find(1);
    // bool res = got == cacheMap.end();
    // std::cout << "value = " << res << endl;
    // std::cout << "Size in map = " << cacheMap.size() << endl;

    return 0;
}
