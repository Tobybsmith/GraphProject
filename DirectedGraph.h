#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "Graph.h"
#include <vector>

class DirectedGraph : public Graph
{
    public:
    DirectedGraph();
    DirectedGraph(std::string);
    void listOnePath(Node*);
    bool helper(Node*, vector<Node*>&, vector<Node*>&);
    void displayPathOfNode(Node *n);
    void betweenTwoNodes(Node*, Node*);
    bool helper2(Node*, Node*, vector<Node*>&);
};

#endif