#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
    private:
        int key;
        int value;
        Node* next;
        Node* prev;

    public:
        Node(int key, int value);

        int getKey();

        int getValue();

        Node* getNext();

        Node* getPrev();

        void setNext(Node* node);

        void setPrev(Node* node);
};

#endif