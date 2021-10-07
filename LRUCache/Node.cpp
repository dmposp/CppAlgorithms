#include "Node.h"

Node::Node(int value)
{
    data = value;
}

int Node::getData()
{
    return data;
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
