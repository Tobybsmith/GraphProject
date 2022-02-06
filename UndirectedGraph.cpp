#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() : Graph(true)
{
    //do nothing
}

void UndirectedGraph::listOnePath(Node *n)
{
    vector<Node*> visited;
    vector<Node*> blacklist;
    string str;
    if(helper(n, visited, blacklist))
    {
        for(int i = 0; i < visited.size(); i++)
        {
            str = i == visited.size()-1 ? "->END" : "->";
            cout << visited.at(i)->getValue() << str;
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
bool UndirectedGraph::helper(Node *current, vector<Node*> &past, vector<Node*> &blacklist)
{
    if(!current)
    {
        return false;
    }
    past.push_back(current);
    
    for(int i = 0; i < blacklist.size(); i++)
    {
        if(blacklist.at(i) == current)
        {
            return false;
        }
    }
    if(current->getEdgeList().size() == 0)
        {
            //cout << "READH" << endl;
            blacklist.push_back(current);
            return true;
        }
    for(int i = 0; i < current->getEdgeList().size(); i++)
    {
        //cout << current->getEdgeList().size() << " ";
        //why getTail() instead of getHead()? idk lolz
        if(helper(current->getEdgeList().at(i)->getTail(), past, blacklist))
        {
            //cout << "WE MASSDE IT" << endl;
            return true;
        }
    }
    past.pop_back();
    
    return false;
}