#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = NULL;
    }
    ~LinkedList() {};
    void addNode(int val);
    void sortList();
    void display();
private:
    Node* head;
};

void LinkedList::addNode(int val)
{
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void LinkedList::sortList()
{
    Node* i = head;
    while (i != NULL)
    {
        Node *j=i;
        int smallest=i->data, temp;
        Node *smallestP=i;
        while (j != NULL)
        {
            if(j->data < smallest)
            {
                smallest = j->data;
                smallestP=j;
            }
            j=j->next;
        }
        temp = i->data;
        i->data=smallest;
        smallestP->data=temp;
        i=i->next;
    }
}

void LinkedList::display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    LinkedList* list = new LinkedList();
    int t,num;
    cout << "Enter total: ";
    cin>>t;
    cout << "Enter numbers: ";
    for(int i=0; i<t; i++)
    {
        cin>>num;
        list->addNode(num);
    }
    cout << "Linked list: ";
    list->display();
    list->sortList();
    cout << "Sorted linked list: ";
    list->display();
    delete list;
    return 0;
}
