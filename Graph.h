#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <string>

class Node;
class Edge;
class Graph
{
    private:
    bool directed;
    std::vector<Node*> nodeList;
    std::vector<Edge*> edgeList;
    public:
    //addnode, display, listallpaths, listonepath, queryedge, querynode
    Graph(bool);
    void addNode(Node*);
    void addEdge(Edge*);
    void display();
    //abstract part of class:
    virtual void listAllPaths() = 0;
    virtual void listOnePath(Node*) = 0;
    bool queryedge(Edge*);
    bool querynode(std::string);//should change to any type
};
#endif