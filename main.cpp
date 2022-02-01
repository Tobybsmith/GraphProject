#include "Graph.h"

using namespace std;

int main()
{
    
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
    g.addEdge(e1);
    g.addEdge(e2);
    g.display();

    return 0;
}