#include "UndirectedGraph.h"

using namespace std;

int main()
{
    //TODO 
    //1. DirectedGraph needs to be done
    //2. Need to actually application
        //Database, social network, etc
    //3. Do testing
    //4. Write report
    UndirectedGraph *g = new UndirectedGraph();
    Node *n1 = new Node(g,"1");
    Node *n2 = new Node(g, "2");
    Node *n3 = new Node(g, "1000");
    Node *n4 = new Node(g, "Hello");
    Edge e2 = Edge(n1, n4, false, g);
    Edge e1 = Edge(n1, n2, false, g);
    Edge e3 = Edge(n2, n3, false, g);
    Edge e4 = Edge(n2, n4, false, g);
    //cout << n1->getEdgeList().size() << " " << n2->getEdgeList().size() << " " << n3->getEdgeList().size() << endl;
    g->caller(n1);
    //cout << n2->getEdgeList().at(0)->getTail()->getValue() << endl;
    g->display();
    return 0;
}