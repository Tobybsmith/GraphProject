#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() : Graph(true)
{
    //do nothing
}

void UndirectedGraph::listOnePath(Node *n)
{
    vector<Node*> visited;
    vector<Node*> blacklist;
    if(helper(n, visited, blacklist))
    {
        for(int i = 0; i < visited.size(); i++)
        {
            cout << visited.at(i) << "->";
        }
        cout << endl;
    }
}

void UndirectedGraph::listAllPaths()
{
    cout << "hehe" << endl;
}

//https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
//keep working on this
bool UndirectedGraph::helper(Node *current, vector<Node*> past, vector<Node*> blacklist)
{
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