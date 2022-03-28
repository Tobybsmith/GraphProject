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

//bad programming but im lazy
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
        //reverse the algo.
        reverse(visited.begin(), visited.end());
        for(int i = 0; i < visited.size(); i++)
        {
            str = i == visited.size()-1 ? "" : "->";
            cout << visited.at(i)->getValue() << str;
        }
        cout << endl;
    }
}

//straight up, IDK man lmao
bool DirectedGraph::helper(Node *current, vector<Node*> &past, vector<Node*> &blacklist)
{
    //null safe
    if(!current)
    {
        return false;
    }
    //end condition, at end of tree (root node)
    if(current->getIsRoot())
    {
        past.push_back(current);
        return true;
    }
    if(helper(current->getEdgeList().at(0)->getHead(), past, blacklist))
    {
        past.push_back(current);
        return true;
    }
    return false;
}