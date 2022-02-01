#include "Node.h"

int Node::counter = 0;

Node::Node()
{
    value = 0;
    index = counter;
    counter++;
}

Node::Node(int v)
{
    value = v;
    index = counter;
    counter++;
    
}

bool Node::ifValueExists(int v)
{
    return v == value;
}

int Node::getValue()
{
    return value;
}

void Node::setValue(int v)
{
    value = v;
}

void Node::addEdge(Edge* e)
{
    edgeList.push_back(e);
}

vector<Edge*> Node::getEdgeList()
{
    return edgeList;
}

int Node::getIndex()
{
    return index;
}
