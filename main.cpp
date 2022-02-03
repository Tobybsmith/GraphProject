#include "Graph.h"

using namespace std;

int main()
{
    //TODO 
    //1. Convert Graph.cpp to an abstract class
    //2. Add Directed and Undirected Graph implementation
    //3. Move addNode() to construtor (will have to pass a graph to construtor)
    //4. Move addEdge() to construtor (will have to pass a graph to constructor)
    //5. List all possible paths from all verticies
    //6. List the path from one starting node
    //6.1 Path ends when a node has no edges or a node loops back to a node already
        //covered in the path.
    //7. Come up with application ideas
        //database, social media app, something like that.
    Graph g = Graph();
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(1000);
    Node *n4 = new Node(-100);
    g.addNode(*n1);
    g.addNode(*n2);
    g.addNode(*n3);
    g.addNode(*n4);
    Edge e1 = Edge(n1, n2, false);
    Edge e2 = Edge(n3, n4, true);
    Edge e3 = Edge(n2, n3, false);
    g.addEdge(e1);
    g.addEdge(e2);
    g.addEdge(e3);
    g.display();

    return 0;
}