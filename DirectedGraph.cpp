#include "DirectedGraph.h"
#include <algorithm>

DirectedGraph::DirectedGraph() : Graph(true)
{
    //do nothing
}

DirectedGraph::DirectedGraph(std::string n) : Graph(true)
{
    //do nothing
    name = n;
}

//
void DirectedGraph::displayPathOfNode(Node *n)
{
    //vector<Node*> blacklist;
    for(int i = 0; i < 1; i++)
    {
        listOnePath(n);
    }
}
void DirectedGraph::listOnePath(Node *n)
{
    vector<Node*> visited;
    vector<Node*> blacklist;
    string str;
    if(helper(n, visited, blacklist))
    {
        for(int i = 0; i < visited.size(); i++)
        {
            str = i == visited.size()-1 ? "" : "->";
            cout << visited.at(i)->getValue() << str;
        }
        cout << endl;
    }
}

void DirectedGraph::listAllPaths()
{
    cout << "hehe" << endl;
}

//this works. idk why
bool DirectedGraph::helper(Node *current, vector<Node*> &past, vector<Node*> &blacklist)
{

    if(!current)
    {
        return false;
    }
    past.push_back(current);

    if(current->getEdgeList().size() == 0)
    {
        return true;
    }
    for(int i = 0; i < current->getEdgeList().size(); i++)
    {
        if(helper(current->getEdgeList().at(i)->getHead(), past, blacklist))
        {
            return true;
        }
    }
    past.pop_back();
    
    return false;
}