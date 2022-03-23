#include "DirectedGraph.h"
#include "Member.h"
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    //dont need an index file, can use fstream.good() <- true if exists and false if doesn't
    if(stricmp(argv[1], "-i") == 0)
    { 
        cout << "Welcome to the interactive family tree manager, type H for help." << endl;
        DirectedGraph *g;
        while(true)
        {
            //prompt user for input.
            std::cout << "\n> ";
            //get input
            string line;
            getline(cin, line);
            //get the command type:
            char type = line.at(0);
            //works great
            if(type == 'C')
            {
                //have to add a base node to this tree in creation
                string name;
                std::cout << "\nEnter Tree Name > ";
                getline(cin, name);
                cout << name;
                ofstream of(name);
                g = new DirectedGraph(name);
                cout << "Enter First Name, Last Name, and Date Of Bith (dd/mm/yyyy) > ";
                string f;
                string n;
                string dob;
                //getline(cin, l);
                cin >> f;
                cin >> n;
                cin >> dob;
                //for reasons, that are myriad and complex.
                cin.ignore();
                
                //constructs a node, adds to g, and creates the underlying member all in one :)
                g->addNode(new Node(Member(dob, f, n)));
            }
            else if(type == 'N')
            {
                cout << "\nEnter First Name, Last Name, and Date Of Bith (dd/mm/yyyy) > ";
                string f;
                string n;
                string dob;
                //getline(cin, l);
                cin >> f;
                cin >> n;
                cin >> dob;
                //for reasons, that are myriad and complex.
                cin.ignore();
                Node *curr  = new Node(Member(dob, f, n));
                

                cout << "Enter First and Last name of this person's child > ";
                string ef;
                string en;
                cin >> ef;
                cin >> en;
                cin.ignore();
                //connects the current node and the specified child node.
                if(g->getNodeFromName(ef, en) == nullptr)
                {
                    cout << "That member does not exist" << endl;
                    continue;
                }
                g->addNode(curr);
                new Edge(g->getNodeFromName(ef, en), curr,  false, g);
            }
            else if(type == 'D')
            {
                //display graph as a whole
                g->display();
            }
            else if (type == 'H')
            {
                cout << "Help:" << endl;
                cout << "Use C to create a new family and add a starting member to it" << endl ;
                cout << "Use N to create a new family member on the tree." << endl 
                    <<" The child of this member must be specified to add this member." << endl;
                cout << "Use D to display the tree." << endl;
                cout << "Use P to display the path from one node to another if that path exists." << endl;
                cout << "Use R to remove a node from the tree (will recursively remove all parents of that node)." << endl;
                cout << "use Q to quit the program." << endl;
            }
            
            else if(type == 'Q')
            {
                //quit program
                return 0;
            }
        }
    }
    else if(stricmp(argv[1], "-d") == 0 && stricmp(argv[2], "demo1") == 0)
    {
        std::cout << "demo1 mode" << endl;
    }
    else
    {
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
        std::cout << endl;
        tobyTree->display();
        //tobyTree->displayPathOfNode(n3);
        return 0;
    }
    
}