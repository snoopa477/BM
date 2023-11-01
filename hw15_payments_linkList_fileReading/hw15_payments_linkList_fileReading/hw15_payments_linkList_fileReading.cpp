#include <fstream>
#include <iostream>
//to use system("pause");
#include <cstdlib>
#include <string.h>
#include <cstdlib>

using namespace std;

bool IS_DEBUG = false;

namespace linkedlistofclasses
{
    class Node
    {
    public:
        Node();
        Node(double vmoney, string vname);
        Node(double vmoney, string vname, Node* next);
        //Constructors to initialize a node


        double getMoney() const;
        //Retrieve value for this node

        string getName() const;

        Node* getLink() const;
        //Retrieve next Node in the list

        void setMoney(double vmoney);
        //Use to modify the value stored in the list

        void setName(string vname);

        void setLink(Node* next);
        //Use to change the reference to the next node

    private:
        double money;
        string name;
        Node* link;
    };
    typedef Node* NodePtr;
} //linkedlistofclasses
//Node.h
using namespace linkedlistofclasses;

Node* read_to_get_node_per_line(ifstream& in_stream, double& total_money);
Node* get_list_of_nodes(ifstream& in_stream, double& total_money, int& size);
void print_reimbursement_suggestion(Node* p_head, double& const total_expense, int& const size);
void print_nodes(Node* p_head);
Node* get_list_of_nodes(ifstream& in_stream, double& total_money, int& size);
Node* next_recipient(Node* p_head, const double average_pay);
Node* next_payer(Node* p_head, const double average_pay);
void get_recipient_and_payer_heads(Node* p_head, Node*& p_recipient_head, Node*& p_payer_head, const double&  average_pay);

int main()
{

    
    char file_name[16];
    ifstream in_stream;

    cout << "I will sum three numbers taken from an input\n"
        << "file and write the sum to an output file.\n";
    cout << "Enter the input file name (maximum of 15 characters):\n";
    cin >> file_name;


    in_stream.open(file_name);
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        system("pause");
        exit(1);
    }

    double total_expense = 0;
    int list_size = 0;

    Node* p_head = get_list_of_nodes(in_stream, total_expense, list_size);

    //QUESION: if we call exit(1), will this method be ever called?
    in_stream.close();

    //print_nodes(p_head);
    cout << "total expense is " << total_expense << endl;
    cout << "list size is " << list_size << endl;

    print_reimbursement_suggestion(p_head, total_expense, list_size);


    cout << "End of Program.\n";

    system("pause");

    return 0;
}



Node* read_to_get_node_per_line(ifstream& in_stream, double& total_money) {

    if (IS_DEBUG)
    {
        cout << "read_to_get_node_per_line" << endl;
    }

    double money = 0;
    in_stream >> money;

    total_money += money;

    //consume one whitespace
    char next;
    in_stream.get(next);
    
    int i = 0;
    char name[32]{};
    do
    {
        in_stream.get(next);
        if (next != '\n')
        {
            name[i] = next;
        }
        i++;

        //cout << "while next != '\\n' " << next << endl;

    //if last record has no newline, would be stuch in infinite loop
    //} while (next != '\n' );
    } while (next != '\n' && !in_stream.eof());

    string str_name(name);

    Node* p_new_node = new Node(money, name);

    cout << "name: " << p_new_node->getName() << ", money: " << p_new_node->getMoney() << endl;

    return p_new_node;

}



Node* get_list_of_nodes(ifstream& in_stream, double& total_money, int& size)
{
    Node* p_head = NULL;
    Node* p_tail = NULL;

    while (!in_stream.eof())
    {
        if(p_head == NULL)
        {
            p_head = read_to_get_node_per_line(in_stream, total_money);
            p_tail = p_head;
        }
        else 
        {
            Node* p_new_node = read_to_get_node_per_line(in_stream, total_money);
            p_tail->setLink(p_new_node);
            //move to the newly created node
            p_tail = p_tail->getLink();
        }
        size++;
    }

    return p_head;

}


void print_reimbursement_suggestion(Node* p_head, double& const total_expense, int& const size)
{
    const double average_pay = total_expense / size;

    Node* p_recipient_head = NULL; 
    Node* p_payer_head = NULL;

    get_recipient_and_payer_heads(p_head, p_recipient_head, p_payer_head, average_pay);


    Node* p_recipient_current = p_recipient_head;
    Node* p_payer_current = p_payer_head;

    double recipient_amount = p_recipient_current->getMoney() - average_pay;
    double payer_amount = p_payer_current->getMoney() - average_pay;

    while ((p_recipient_current == NULL && p_payer_current == NULL) == false)
    {
        if (IS_DEBUG)
        {
            cout << "----" << endl;
            cout << "payer name " << (p_payer_current != NULL ? p_payer_current->getName() : "xxx") << endl;
            cout << "recipient name " << (p_recipient_current != NULL ? p_recipient_current->getName() : "xxx") << endl;
        }

        //confused, if I don't add this line, will be null accessing field, causing program forcifully ends
        if ((p_recipient_current == NULL || p_payer_current == NULL))
        {
            break;
        }

        if ( abs(recipient_amount) < abs(payer_amount))
        {
            if (IS_DEBUG)
            {
                cout << "case 1" << endl;
            }

            //recipient_amount = recipient_amount - recipient_amount = 0
            payer_amount = -(abs(payer_amount) - abs(recipient_amount));

            cout << "" << p_payer_current->getName() << ", you give " << p_recipient_current->getName() << " " << recipient_amount << endl;
            //TODO: next recipient, get its recipient_amount
            p_recipient_current = next_recipient(p_recipient_current, average_pay);
            if (p_recipient_current == NULL)
            {
                continue;
            }
            recipient_amount = p_recipient_current->getMoney() - average_pay;

        }
        else if (abs(recipient_amount) > abs(payer_amount))
        {
            if (IS_DEBUG)
            {
                cout << "case 2" << endl;
            }

            //payer_amount = -payer_amount + payer_amount = 0
            recipient_amount = recipient_amount - abs(payer_amount);

            cout << "" << p_payer_current->getName() << ", you give " << p_recipient_current->getName() << " " << abs(payer_amount) << endl;

            //TODO: next payer, get its payer_amount
            p_payer_current = next_payer(p_payer_current, average_pay);
            if (p_payer_current == NULL)
            {
                continue;
            }
            payer_amount = p_payer_current->getMoney() - average_pay;
        }
        //approximation !!
        //else if(abs(recipient_amount) == abs(payer_amount))
        else
        {
            if (IS_DEBUG)
            {
                cout << "case 3" << endl;
            }

            //payer_amount = -payer_amount + payer_amount = 0
            recipient_amount = recipient_amount - abs(payer_amount);

            cout << "" << p_payer_current->getName() << ", you give " << p_recipient_current->getName() << " " << abs(payer_amount) << endl;

            //TODO: next payer, get its payer_amount
            p_payer_current = next_recipient(p_payer_current, average_pay);
            if (p_payer_current == NULL)
            {
                continue;
            }
            payer_amount = p_payer_current->getMoney() - average_pay;

            //TODO: next recipient, get its recipient_amount
            p_recipient_current = next_recipient(p_recipient_current, average_pay);
            if (p_recipient_current == NULL)
            {
                continue;
            }
            recipient_amount = p_recipient_current->getMoney() - average_pay;
        }

        if (IS_DEBUG)
        {
            cout << "----(next round)" << endl;
            cout << "payer name " << ( p_payer_current != NULL? p_payer_current->getName() : "xxx" ) << endl;
            cout << "recipient name " << (p_recipient_current != NULL ? p_recipient_current->getName() : "xxx") << endl;
        }


    }
}


Node* next_recipient(Node* p_head, const double average_pay)
{
        
    p_head = p_head->getLink();
    if (IS_DEBUG)
    {
        cout << "next_recipient" << endl;
    }

    while (p_head != NULL && (p_head->getMoney() > average_pay) == false )
    {
        if (IS_DEBUG)
        {
            cout << "next_recipient" << endl;
        }
        p_head = p_head->getLink();
    }
    return p_head;
}



Node* next_payer(Node* p_head, const double average_pay)
{

    p_head = p_head->getLink();
    if (IS_DEBUG)
    {
        cout << "next_payer" << endl;
    }

    while (p_head != NULL && (p_head->getMoney() < average_pay) == false)
    {
        if (IS_DEBUG)
        {
            cout << "next_payer" << endl;
        }
        p_head = p_head->getLink();
    }
    return p_head;
}



//QUESTION: what's the difference between const double& and double& const ?
// WRONG 
//void get_recipient_and_payer_heads(Node* p_head, Node*& p_recipient_head, Node*& p_payer_head, double& const average_pay)
void get_recipient_and_payer_heads(Node* p_head, Node*& p_recipient_head, Node*& p_payer_head, const double&  average_pay)
{
    p_recipient_head = NULL;
    p_payer_head = NULL;

    Node* p_current = p_head;

    //so hard to think about
    while (p_current != NULL && (p_recipient_head != NULL && p_payer_head != NULL) == false )
    {
        bool is_payer = p_current->getMoney() - average_pay < 0;
        bool is_recipient = p_current->getMoney() - average_pay > 0;

        if (is_payer && p_payer_head == NULL)
        {
            p_payer_head = p_current;
        }

        if (is_recipient && p_recipient_head == NULL)
        {
            p_recipient_head = p_current;
        }

        p_current = p_current->getLink();
    }


}



void print_nodes(Node* p_head)
{

    Node* p_current = p_head;

    while (p_current != NULL)
    {
        cout << "name: " << p_current->getName() << ", money: " << p_current->getMoney() << endl;
        p_current = p_current->getLink();
    }

}


namespace linkedlistofclasses
{
    Node::Node() : money(0), link(NULL)
    {
        //deliberately empty
    }

    Node::Node(double vmoney, string vname) : money(vmoney), name(vname), link(NULL)
    {
        //deliberately empty
    }

    Node::Node(double vmoney, string vname, Node* next) : money(vmoney), name(vname), link(next)
    {
        //deliberately empty
    }

    //Accessor and Mutator methods follow

    double Node::getMoney() const
    {
        return money;
    }


    string Node::getName() const
    {
        return name;
    }


    Node* Node::getLink() const
    {
        return link;
    }

    void Node::setMoney(double vmoney)
    {
        money =vmoney;
    }

    
    void Node::setName(string vname)
    {
        name = vname;
    }

    void Node::setLink(Node* next)
    {
        link = next;
    }
} //linkedlistofclasses
//Node.cpp