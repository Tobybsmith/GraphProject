#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <string>

class Node;
class Edge;
class Member;
class Graph
{
    private:
    bool directed;
    std::vector<Node*> nodeList;
    std::vector<Edge*> edgeList;
    protected:
    std::string name;
    public:
    //addnode, display, listallpaths, listonepath, queryedge, querynode
    Graph(bool);
    void addNode(Node*);
    void addEdge(Edge*);
    void display();
    //abstract part of class:
    virtual void listOnePath(Node*) = 0;
    bool queryedge(Edge*);
    bool querynode(std::string);//should change to any type
    bool querynode(Member*);//should change to any type
    bool querynode(std::string, std::string);//should change to any type
    bool queryedge(std::string, std::string, std::string, std::string);//should change to any type
    std::vector<Node*> getNodeList();
    Node* getNodeFromName(std::string, std::string);
    std::string getName();
};
#endif