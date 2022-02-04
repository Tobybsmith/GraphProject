#ifndef NODE_H
#define NODE_H
#include "Edge.h"
#include <vector>

using namespace std;

class Edge;
class Node
{
    private:
    //change this int later to any val
    int value;
    static int counter;
    int index;
    vector<Edge*> edgeList;
    public:
    Node();
    Node(int);
    bool ifValueExists(int);
    void setValue(int);
    int getValue();
    void addEdge(Edge*);
    vector<Edge*> getEdgeList();
    int getIndex();
};

#endif