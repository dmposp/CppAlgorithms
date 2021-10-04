#include "Node.h"

Node::Node(int value)
{
    this->data = value;
}

int Node::getData()
{
    return this->data;
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
