#include "DirectedGraph.h"
#include "Member.h"

using namespace std;

int main()
{
    //TODO 
    //write report
    //write display()
    //graph.addNode(new Node(rootT)); do this

    //a graph can be created with no nodes or edges (1)
    DirectedGraph *tobyTree = new DirectedGraph();

    DirectedGraph *alexisTree = new DirectedGraph();

    DirectedGraph *testTree = new DirectedGraph();
    
    Member rootT = Member("08/10/2002", "Toby", "Smith");
    Member fatherT = Member("21/10/1979", "Chris", "Smith");
    Member motherT = Member("17/09/1984", "Gillian", "Evans");

    Member rootA = Member("05/06/2002", "Alexis", "Bernier");
    Member fatherA = Member("17/09/1972", "Hugo", "Bernier");//find right DOB
    Member motherA = Member("04/01/1972", "Nadine", "Tremblay");//find right DOB

    //A node can contain any value (4)
    Node *test = new Node(testTree, "1000");
    Node *test2 = new Node(testTree, "Hello World");

    //a graph can be added in verticies (3)
    Node *n1 = new Node(tobyTree, rootT);
    Node *n2 = new Node(tobyTree, fatherT);
    Node *n3 = new Node(tobyTree, motherT);

    Node *n4 = new Node(alexisTree, rootA);
    Node *n5 = new Node(alexisTree, fatherA);
    Node *n6 = new Node(alexisTree, motherA);

    //and edges (3)
    Edge e1 = Edge(n2, n1, false, tobyTree);
    Edge e2 = Edge(n3, n1, false, tobyTree);

    Edge e3 = Edge(n5, n4, false, alexisTree);
    Edge e4 = Edge(n6, n4, false, alexisTree);
    
    //a graph can be displayed by listing all the possible pasths (5)
    cout << "Displaying alexisTree:" << endl;
    alexisTree->display();
    cout << endl;
    cout << "Displaying tobyTree:" << endl;
    tobyTree->display();
    cout << endl;
    //a graph can be displayed by giving a node and showing the path this node leads (6)
    cout << "Displaying path that Gillian Evans leads: " << endl;
    tobyTree->displayPathOfNode(n3);
    return 0;
}