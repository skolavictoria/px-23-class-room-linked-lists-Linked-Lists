#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
    private:
        int value;
        Node* next_member = nullptr;
    public:
        Node(int value) : value(value) {};
        void add_next_member(Node* ptr)
        {
            next_member = ptr;
        }
        int get_value()
        {
            return value;
        }
        Node* get_next_member()
        {
            return next_member;
        }
};

class LinkedList
{
    public:
        Node* first_elem = nullptr;
        LinkedList(Node* first_elem) : first_elem(first_elem) {};
        // Methods to implement
        void append()   // Add element to the end of the list
        {
            Node* member = first_elem;
            while(member->get_next_member() != nullptr)
            {
                member = member->get_next_member();
            }
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the value of the new member: (append)\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            int new_value;
            cin >> new_value;
            member->add_next_member(new Node(new_value));
        }
        void insert(int position) // Add element to the list at the given position
        {
            if (position == 0) {
            push();
            return;
            }

            Node* member = first_elem;
            for(int i = 0; i < position - 2; i++)
            {
            if (member->get_next_member() == nullptr) {
                cout << "Error" << endl;
                return;
            }
            member = member->get_next_member();
            }
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the value of the new member: (insert)\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            int new_value;
            cin >> new_value;

            Node* new_member = new Node(new_value);
            new_member->add_next_member(member->get_next_member());
            member->add_next_member(new_member);
        }
        void push()     // Add element to the beginning of the list
        {
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the value of the new member: (push to the beginning)\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            int new_value;
            cin >> new_value;
            Node* new_member = new Node(new_value);
            new_member->add_next_member(first_elem);
            first_elem = new_member;

        } 
        int pop() // Remove element from the beginning of the list and return it

        {
            int value = first_elem->get_value();
            Node* to_delete = first_elem;
            first_elem = first_elem->get_next_member(); 

            delete to_delete;
            cout << "First number value is: " << value << endl;
            return value;
        }  
        void remove(int position)   // Remove element from the list at the given position
        {
            Node* member = first_elem;
            for(int i = 0; i < position - 2; i++)
            {
                member = member->get_next_member();
            }
            Node* to_delete = member->get_next_member();
            member->add_next_member(to_delete->get_next_member());
            delete to_delete;
        }
        void print_list()
        {
            Node* member = first_elem;
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "| ";
            while(member != nullptr)
            {
                cout << member->get_value() << " | ";
                member = member->get_next_member();
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        void BubbleSort()
        {
            int Continue = 1;
            while(Continue != 0 )
            {
                Continue = 0;
                Node* MemberA = first_elem;
                Node* MemberB = first_elem->get_next_member();
                Node* PreviousMemberA = nullptr;
                Node* NextMemberB = MemberB->get_next_member();

                while(MemberB != nullptr)
                {
                    if(MemberA->get_value() > MemberB->get_value())
                    {
                        Continue = 1;
                        if(PreviousMemberA != nullptr)
                        {
                            PreviousMemberA->add_next_member(MemberB);
                        }
                        else
                        {
                            first_elem = MemberB;
                        }

                        MemberA->add_next_member(NextMemberB);
                        MemberB->add_next_member(MemberA);
                        PreviousMemberA = MemberB;
                        MemberB = NextMemberB;

                        if(NextMemberB != nullptr)
                        {
                            NextMemberB = NextMemberB->get_next_member();
                        }
                    }
                    else
                    {
                        PreviousMemberA = MemberA;
                        MemberA = MemberB;
                        MemberB = NextMemberB;
                        if(NextMemberB != nullptr)
                        {
                            NextMemberB = NextMemberB->get_next_member();
                        }
                    }
                }
            }
        }
        void reverse()
        {
            Node* previous = nullptr;
            Node* current = first_elem;
            Node* next = nullptr;
            while (current != nullptr)
            {
                next = current->get_next_member();
                current->add_next_member(previous);
                previous = current;
                current = next;
            }
            first_elem = previous;
        }
};

int GetRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    LinkedList llist1 = LinkedList(new Node(1));
    Node* member = llist1.first_elem;

    for(int i = 2; i < 26; i++) //List filling
    {
        member->add_next_member(new Node(GetRandomNumber(1, 100)));
        member = member->get_next_member();
    }

    int position;
    int value;
    int i = 1;
    while(i!=0){
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << " Choose the operation: 1 - append, 2 - insert, 3 - push, 4 - pop, 5 - remove, 6 - print list, 7 - sort, 8 - reverse, 9 - end" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
        int operation;
        cin >> operation;
        switch (operation)
        {
        case 1:
            llist1.append();
            break;
        case 2:
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the position to insert the new member: (insert)" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            position;
            cin >> position;
            llist1.insert(position);
            break;
        case 3:
            llist1.push();
            break;
        case 4:
            value = llist1.pop();
            break;
        case 5:
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the position to remove the member: (remove)" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
            position;
            cin >> position;
            llist1.remove(position);
            break;
        case 6:
            llist1.print_list();
            break;
        case 7:
            llist1.BubbleSort();
            break;
        case 8:
            llist1.reverse();
            break;
        case 9:
            i = 0;
            break;
        default:
            i = 0;
            cout << "Dolboeb kosoi :>" << endl;
            break;
        }
    }
    return 0;
}