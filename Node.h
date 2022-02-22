#ifndef NODE_H
#define NODE_H
#include "Edge.h"
#include "Graph.h"
#include "Member.h"
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
    Member member;
    static int counter;
    int index;
    vector<Edge*> edgeList;
    public:
    Node();
    Node(Graph*, string);
    Node(Graph*, Member);
    Node(Member);
    bool ifValueExists(string);
    bool ifValueExists(Member);
    bool operator==(Member&);
    void setValue(string);
    void setValue(Member);
    string getValue();
    Member getMember();
    void addEdge(Edge*);
    vector<Edge*> getEdgeList();
    int getIndex();
};

#endif