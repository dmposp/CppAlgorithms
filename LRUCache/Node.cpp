#include "Node.h"

Node::Node(int key, int value)
{
    this->key = value;
    this->value = value;
    next = 0;
    prev = 0;
}

int Node::getKey()
{
    return key;
}

int Node::getValue()
{
    return value;
}

Node * Node::getNext()
{
    return next;
}

Node * Node::getPrev()
{
    return prev;
}

void Node::setNext(Node * node)
{
    next = node;
}

void Node::setPrev(Node * node)
{
    prev = node;
}
