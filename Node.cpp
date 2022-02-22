#include "Node.h"
#include "Member.h"

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

Node::Node(Graph* g, Member m)
{
    member = m;
    index = counter;
    counter++;
    value = member.getFirstname() + " " + member.getLastName() + " (" + member.getDOB()+")";
    g->addNode(this);
}

Node::Node(Member m)
{
    member = m;
    index = counter;
    counter++;
    value = member.getFirstname() + " " + member.getLastName() + " (" + member.getDOB()+")";
    //g->addNode(this);
}

bool Node::ifValueExists(string v)
{
    return v == value;
}

bool Node::operator==(Member& other)
{
    if(member.getFirstname()==other.getFirstname()
        &&(member.getLastName()==other.getLastName())
        &&(member.getDOB()==other.getDOB()))
    {
        return true;
    }
    return false;
}

bool Node::ifValueExists(Member m)
{
    return *this == m;
}

string Node::getValue()
{
    return value;
}

Member Node::getMember()
{
    return member;
}

void Node::setValue(string v)
{
    value = v;
}

void Node::setValue(Member m)
{
    member = m;
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
