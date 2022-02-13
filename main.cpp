#include "DirectedGraph.h"
#include "Member.h"

using namespace std;

int main()
{
    //TODO 
    //write report
    //write display()
    //graph.addNode(new Node(rootT)); do this

    DirectedGraph *tobyTree = new DirectedGraph();

    DirectedGraph *alexisTree = new DirectedGraph();
    
    Member rootT = Member("08/10/2002", "Toby", "Smith");
    Member fatherT = Member("21/10/1979", "Chris", "Smith");
    Member motherT = Member("17/09/1984", "Gillian", "Evans");

    Member rootA = Member("05/06/2002", "Alexis", "Bernier");
    Member fatherA = Member("17/09/1972", "Hugo", "Bernier");//find right DOB
    Member motherA = Member("04/01/1972", "Nadine", "Tremblay");//find right DOB

    Node *n1 = new Node(tobyTree, rootT);
    Node *n2 = new Node(tobyTree, fatherT);
    Node *n3 = new Node(tobyTree, motherT);

    Node *n4 = new Node(alexisTree, rootA);
    Node *n5 = new Node(alexisTree, fatherA);
    Node *n6 = new Node(alexisTree, motherA);

    Edge e1 = Edge(n2, n1, false, tobyTree);
    Edge e2 = Edge(n3, n1, false, tobyTree);

    Edge e3 = Edge(n5, n4, false, alexisTree);
    Edge e4 = Edge(n6, n4, false, alexisTree);
    
    alexisTree->display();
    cout << endl;
    tobyTree->display();
    tobyTree->displayPathOfNode(n3);
    return 0;
}