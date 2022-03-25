#include "DirectedGraph.h"
#include "Member.h"
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    //run with -i for interative mode, -d for project testing, nothing for a sample project
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
                g->addNode(new Node(Member(dob, f, n), true));
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
                Node *curr  = new Node(Member(dob, f, n), false);
                

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
            else if(type == 'P')
            {
                //display graph as a whole
                cout << "Enter first and last name of member > ";
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
                //now works as expected
                g->displayPathOfNode(g->getNodeFromName(ef, en));
            }
            else if (type == 'E')
            {
                cout << "Enter first and last name of first member > ";
                string ef1;
                string en1;
                cin >> ef1;
                cin >> en1;
                cin.ignore();
                //connects the current node and the specified child node.
                if(g->getNodeFromName(ef1, en1) == nullptr)
                {
                    cout << "That member does not exist" << endl;
                    continue;
                }

                cout << "Enter first and last name of first member > ";
                string ef2;
                string en2;
                cin >> ef2;
                cin >> en2;
                cin.ignore();
                //connects the current node and the specified child node.
                if(g->getNodeFromName(ef2, en2) == nullptr)
                {
                    cout << "That member does not exist" << endl;
                    continue;
                }
                //write a name, name to edge helper to do this.
                if(true)
                {
                    cout << "Pog" << endl;
                }
            }
            else if (type == 'H')
            {
                cout << "Help:" << endl;
                cout << "Use C to create a new family and add a starting member to it" << endl ;
                cout << "Use N to create a new family member on the tree." << endl 
                    <<" The child of this member must be specified to add this member." << endl;
                cout << "Use D to display the tree." << endl;
                cout << "Use P to display the path from one node to another if that path exists." << endl;
                cout << "Use E to determine whether or not an edge exists." << endl;
                //L??? lmao
                cout << "Use L to determine whether or not a family member exists" << endl;
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
        //this here can have the black box testing for the project demo
        std::cout << "demo1 mode" << endl;
    }
    else
    {
        DirectedGraph *tobyTree = new DirectedGraph();

        DirectedGraph *alexisTree = new DirectedGraph();

        Member rootT = Member("08/10/2002", "Toby", "Smith");
        Member fatherT = Member("21/10/1979", "Chris", "Smith");
        Member motherT = Member("17/09/1984", "Gillian", "Evans");
        Member motherMotherT = Member("17/09/1984", "Barb", "Evans");

        Member rootA = Member("05/06/2002", "Alexis", "Bernier");
        Member fatherA = Member("17/09/1972", "Hugo", "Bernier");//find right DOB
        Member motherA = Member("04/01/1972", "Nadine", "Tremblay");//find right DOB

        Node *n1 = new Node(tobyTree, rootT, true);
        Node *n2 = new Node(tobyTree, fatherT, false);
        Node *n3 = new Node(tobyTree, motherT, false);
        Node *n7 = new Node(tobyTree, motherMotherT, false);

        Node *n4 = new Node(alexisTree, rootA, true);
        Node *n5 = new Node(alexisTree, fatherA, false);
        Node *n6 = new Node(alexisTree, motherA, false);

        Edge e1 = Edge(n2, n1, false, tobyTree);
        Edge e2 = Edge(n3, n1, false, tobyTree);
        Edge e5 = Edge(n7, n3, false, tobyTree);

        Edge e3 = Edge(n5, n4, false, alexisTree);
        Edge e4 = Edge(n6, n4, false, alexisTree);

        //alexisTree->display();
        std::cout << endl;
        tobyTree->display();
        cout << endl;
        tobyTree->displayPathOfNode(n3);
        return 0;
    }
    
}