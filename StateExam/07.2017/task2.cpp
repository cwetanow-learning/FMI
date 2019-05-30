#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
    Node* next;
    int value;

    Node(int value)
    {
        this->value=value;
        this->next=NULL;
    }

    Node(int value, Node* previous)
    {
        this->value=value;
        this->next=NULL;
        previous->next = this;
    }
};

struct List
{
    int count;
    Node* root;

    List()
    {
        this->count=0;
        this->root = NULL;
    }

    void add(int value)
    {
        if(this->count==0)
        {
            this->root = new Node(value);
        }
        else
        {
            Node* current = this->root;

            while(current->next != NULL)
            {
                current=current->next;
            }

            Node* newElement = new Node(value,current);
        }

        this->count++;
    };

    void addSorted(int value)
    {
        if(this->count==0)
        {
            this->root = new Node(value);
        }
        else
        {
            if(this->root->value > value)
            {
                Node* newNode = new Node(value);
                newNode->next=this->root;

                this->root = newNode;
                return;
            }

            Node* current = this->root;
            while(current->next != NULL && current->value < value)
            {
                current = current->next;
            }

            Node* next = current->next;

            Node* newElement = new Node(value, current);
            newElement->next = next;
        }

        this->count++;
    }
};

List* sortList(List* list)
{
    List* newList= new List();

    Node* current = list->root;

    while(current != NULL)
    {
        newList->addSorted(current->value);
        current= current->next;
    }

    return newList;
}

int main()
{
    List* list = new List();
    list->add(5);
    list->add(2);
    list->add(11);
    list->add(52);
    list->add(1);

    list=  sortList(list);

    Node* current = list->root;
    while(current!=NULL)
    {
        cout << current->value << " ";
        current=current->next;
    }

    return 0;
}
