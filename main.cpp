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
        //program is in interactive mode
        //some basic commands, create tree, add node, add node to another node (parent)
        //C, R, P, S
        //C for create, creates a new family tree with a name and no nodes
        //R creates the root node, must be used like R <firstname> <lastname> <DOB>
        //P creates a parent node, must be used like P <firstname> <lastname> <DOB> <indexofchild>
            //should rework to be name + DOB or index of child
        //S saves the graph to a file.
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
                //create file and break;
                //need to think about file format
                string name;
                std::cout << "\nEnter Tree Name > ";
                getline(cin, name);
                cout << name;
                ofstream of(name);
                g = new DirectedGraph(name);
            }
            else if(type == 'R')
            {
                //this adds the root node to graph g
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
                //now must add the node to the file
                ofstream in;
                in.open(g->getName(), ios::app);
                //file will look like FIRST LAST DOB INDEX CHILD or R to mark root node
                in << f << " " << n << " " << dob << " 0 R" << endl;
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
                
                //now must add the node to the file
                ofstream in;
                in.open(g->getName(), ios::app);
                //file will look like FIRST LAST DOB INDEX CHILDINDEX or R to mark root node
                in << f << " " << n << " " << dob << " "<< curr->getIndex() << " " << g->getNodeFromName(ef, en)->getIndex() << endl;
            }
            else if(type == 'D')
            {
                //display graph as a whole
                g->display();
            }
            else if (type == 'H')
            {
                cout << "Help:" << endl;
                cout << "Use C to create a new family tree named." << endl 
                    << "\tthe default name is tree<n> where n is the nth default named tree."<< endl;
                cout << "Use R to create a root in the family tree." << endl
                    << "\tR can only be used once, as there can only be one root on a tree. R must be used after a tree has been created." << endl;
                cout << "Use N to create a new family member on the tree." << endl 
                    <<"\tthe child of this member must be specified to add this member" << endl;
                cout << "Use D to display the tree" << endl;
                cout << "use Q to quit the program" << endl;
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