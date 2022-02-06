#include "UndirectedGraph.h"

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
    UndirectedGraph *g = new UndirectedGraph();
    Node *n1 = new Node(g,1);
    Node *n2 = new Node(g, 2);
    Node *n3 = new Node(g, 1000);
    Node *n4 = new Node(g, -100);
    Edge e1 = Edge(n1, n2, false, g);
    Edge e2 = Edge(n1, n4, true, g);
    Edge e3 = Edge(n2, n3, false, g);
    //cout << n1->getEdgeList().size() << " " << n2->getEdgeList().size() << " " << n3->getEdgeList().size() << endl;
    g->listOnePath(n1);
    //cout << n2->getEdgeList().at(0)->getTail()->getValue() << endl;
    g->display();
    return 0;
}