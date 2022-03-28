#include "Edge.h"

Edge::Edge()
{
    //nothing
}

//tail to head
//literally no idea how this works lmao
Edge::Edge(Node* a, Node* b, bool c, Graph* g)
{
    tail = b;
    head = a;
    directed = c;
    g->addEdge(this);
    b->addEdge(this);
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