#ifndef NODE_H
#define NODE_H
#include "Edge.h"
#include "Graph.h"
#include <vector>
#include <string>

using namespace std;

class Graph;
class Edge;
class Node
{
    private:
    //change this int later to any val
    string value;
    static int counter;
    int index;
    vector<Edge*> edgeList;
    public:
    Node();
    Node(Graph*, string);
    bool ifValueExists(string);
    void setValue(string);
    string getValue();
    void addEdge(Edge*);
    vector<Edge*> getEdgeList();
    int getIndex();
};

#endif