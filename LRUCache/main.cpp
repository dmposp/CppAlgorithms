#include <iostream>
#include "Node.h"
#include "LRUCache.h"

using namespace std;


int main(int argc, char const *argv[])
{
    LRUCache cache = LRUCache(3);

    //cache.insert(25);
    //cache.insert(35);
    //cache.insert(45);
    //cout << "--" << endl;

    //cout << "size of cache = " << cache.getSize() << endl;
    //int num = 20;
    //int res = cache.find(num);
    //cout << "Find " << num << " = " << res << endl;
    // cout << "Cache has value 35 = " << cache.find(35) << endl;
    // cout << "Cache has value 45 = " << cache.find(45) << endl;

    return 0;
}
