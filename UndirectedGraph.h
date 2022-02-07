#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H
#include "Graph.h"
#include <vector>

class UndirectedGraph : public Graph
{
    public:
    UndirectedGraph();
    void listOnePath(Node*);
    void listAllPaths();
    bool helper(Node*, vector<Node*>&, vector<Node*>&);
    void caller(Node *n);
};

#endif