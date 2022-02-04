#include "Edge.h"

Edge::Edge()
{
    //nothing
}

Edge::Edge(Node* a, Node* b, bool c, Graph* g)
{
    head = a;
    tail = b;
    directed = c;
    g->addEdge(this);
}

bool Edge::operator==(Edge& other)
{
    if((this->directed == other.directed)
            && (this->head->getIndex() == other.head->getIndex())
            && (this->tail->getIndex() == other.tail->getIndex()))
    {
        return true;
    }
    return false;
}

Node* Edge::getTail()
{
    return tail;
}
Node* Edge::getHead()
{
    return head;
}