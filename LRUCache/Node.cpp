#include "Node.h"

Node::Node(const int value)
{
    data = value;
    //cout << "Node constructor" << endl;
}

int Node::getData()
{
    return data;
}

Node* Node::getNext()
{
    return next;
}

Node* Node::getPrev()
{
    return prev;
}

void Node::setNext(Node* node)
{
    next = node;
}

void Node::setPrev(Node* node)
{
    prev = node;
}
