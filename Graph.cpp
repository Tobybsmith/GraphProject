#include "Graph.h"
#include <iostream>

Graph::Graph(bool b)
{
    //true for directed
    //false for undirected
    directed = b;
}
void Graph::addNode(Node *n)
{
    nodeList.push_back(n);
}

void Graph::addEdge(Edge *e)
{
    edgeList.push_back(e);
}

bool Graph::queryedge(Edge *e)
{
    for(int i = 0; i < edgeList.size(); i++)
    {
        if(edgeList.at(i) == e)
        {
            return true;
        }
    }
    return false;
}

void Graph::display()
{
    cout << "Nodes: {";
    for(int i = 0; i < nodeList.size(); i++)
    {
        string c = (i == nodeList.size() - 1 ? "\0" : ", "); 
        cout << nodeList.at(i)->getValue() << c;
    }
    cout << "}" << endl;
    cout<<"Edges: {";
    for(int i=0; i<edgeList.size();i++)
    {
        string str = i == edgeList.size() - 1 ? ")" : "), ";
        // (head, tail), (head, tail), ...
        cout << "(" << edgeList.at(i)->getTail()->getValue() << " -> "
             << edgeList.at(i)->getHead()->getValue()<<str;
    }
    cout << "}" << endl;
}

bool Graph::querynode(std::string v)//query node for any value type
{
    for(int i = 0; i < nodeList.size(); i++)
    {
        if(nodeList.at(i)->getValue() == v)
        {
            return true;
        }
    }
    return false;
}

bool Graph::querynode(Member* m)//query node for values of type Member
{
    for(int i = 0; i < nodeList.size(); i++)
    {
        if(nodeList.at(i)->getMember().getFirstname() == m->getFirstname() && nodeList.at(i)->getMember().getLastName() == m->getLastName())
        {
            return true;
        }
    }
    return false;
}

bool Graph::querynode(std::string fn, std::string ln)//query node for values of type Member
{
    for(int i = 0; i < nodeList.size(); i++)
    {
        if(nodeList.at(i)->getMember().getFirstname() == fn && nodeList.at(i)->getMember().getLastName() == ln)
        {
            return true;
        }
    }
    return false;
}

bool Graph::queryedge(std::string fn1, std::string ln1, std::string fn2, std::string ln2)
{
    //we have names. now we need to get two nodes and then check that edge
    //most simple way is to check every edge in the graph's edge list and cehck that stuff
    for(int i = 0; i < edgeList.size(); i++)
    {
        if(edgeList.at(i)->getHead()->getMember().getFirstname() == fn1 && edgeList.at(i)->getHead()->getMember().getLastName() == ln1)
        {
            if(edgeList.at(i)->getTail()->getMember().getFirstname() == fn2 && edgeList.at(i)->getTail()->getMember().getLastName() == ln2)
            {
                return true;
            }
        }
    }
    return false;
}

vector<Node*> Graph::getNodeList()
{
    return nodeList;
}

std::string Graph::getName()
{
    return name;
}

Node* Graph::getNodeFromName(std::string f, std::string l)
{
    for(int i = 0; i < nodeList.size(); i++)
    {
        if(nodeList.at(i)->getMember().getFirstname() == f && nodeList.at(i)->getMember().getLastName() == l)
        {
            return nodeList.at(i);
        }
    }
    return nullptr;
}