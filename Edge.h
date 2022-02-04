#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Graph;
class Node;
class Edge
{
    private:
    Node* head;
    Node* tail;
    bool directed;
    public:
    Edge();
    Edge(Node*, Node*, bool, Graph*);
    bool operator==(Edge&);
    //-->
    //redefine == for edges
    //two edges are equal if same head, tail, and directionality
    Node* getHead();
    Node* getTail();
};

#endif