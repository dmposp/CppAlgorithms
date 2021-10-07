#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        int data;
        Node * next { 0 };
        Node * prev { 0 };

    public:
        Node(int value);

        int getData();

        Node * getNext();

        Node * getPrev();

        void setNext(Node * node);

        void setPrev(Node * node);
};

#endif