#include "Node.h"

using namespace std;

int Node::counter = 0;

Node::Node()
{
    value = "";
    index = counter;
    counter++;
}

Node::Node(Graph* g, string v)
{
    value = v;
    index = counter;
    counter++;
    g->addNode(this);
}

bool Node::ifValueExists(string v)
{
    return v == value;
}

string Node::getValue()
{
    return value;
}

void Node::setValue(string v)
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
