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

//make the egdes backwards
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
        cout << "(" << edgeList.at(i)->getHead()->getValue() << " -> "
             << edgeList.at(i)->getTail()->getValue()<<str;
    }
    cout << "}" << endl;
}

bool Graph::querynode(std::string v)//change to any type value
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

vector<Node*> Graph::getNodeList()
{
    return nodeList;
}