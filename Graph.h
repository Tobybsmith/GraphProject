#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "Edge.h"
#include <iostream>

class Graph
{
    private:
    bool directed;
    vector<Node> nodeList;
    vector<Edge> edgeList;
    public:
    //addnode, display, listallpaths, listonepath, queryedge, querynode
    Graph();
    void addNode(Node);
    void addEdge(Edge);
    void display();
    //abstract part of class:
    //virtual void listAllPaths();
    //virtual void listOnePath();
    bool queryedge(Edge);
    bool querynode(int);//should change to any type
};
#endif