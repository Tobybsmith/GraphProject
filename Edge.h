#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
#include <vector>

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
    bool operator==(Edge&); //operator overlaoding
    //-->
    //tail -> head
    //redefine == for edges
    //two edges are equal if same head, tail, and directionality
    Node* getHead();
    Node* getTail();
};

#endif