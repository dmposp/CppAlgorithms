#ifndef DOUBLY_LIST_H_
#define DOUBLY_LIST_H_


template <class K, class V>
class Doubly_List {

public:
    Doubly_List(): _size(0), head(nullptr), tail(nullptr) {};
    // deconstructor here
    class Node;

    Node* insert(K key, const V & value);

    int size() { return _size; }

private:
    Node* head;
    Node* tail;
    int _size;
};


template <class K, class V>
class Doubly_List<K, V>::Node {

public:
    Node(V v)
        : data(v), next(nullptr), prev(nullptr) {};

    V& getData();

private:
    V data;
    Node* next;
    Node* prev;
};

template <class K, class V>
typename Doubly_List<K, V>::Node* Doubly_List<K, V>::insert(K k, const V & v) {
    std::cout << "line 43: v = " << v << std::endl;

    Node* node = new Node(v);

    if (head == nullptr)
    {
        head = node;
        tail = node;
        _size += 1;
    }

    return node;
};

#endif  // DOUBLY_LIST_H_