#include <iostream>
#include <sstream>

using namespace std;

template<class TYPE>
struct ListNode
{
public :
    ListNode(TYPE value)
    {
        this->value=value;
        this->next = NULL;
    }

    ListNode(TYPE value, ListNode* previous)
    {
        this->value=value;
        this->next = NULL;
        previous->next = this;
    }

    TYPE value;

    ListNode<TYPE>* next;
};

template<class TYPE>
struct List
{
public:
    int count;
    ListNode<TYPE>* root;

    List()
    {
        this->count=0;
    }

    void add(TYPE value)
    {
        if(this->count == 0)
        {
            this->root = new ListNode<TYPE>(value);
        }
        else
        {
            ListNode<TYPE>* current = this->root;

            while(current->next != NULL)
            {
                current=current->next;
            }

            ListNode<TYPE>* node = new ListNode<TYPE>(value,current);
        }

        this->count++;
    }
};

List<int>* sortLists(List<List<int>*>* lists)
{
    List<int>* list = new List<int>();

    ListNode<List<int>*>* currentList = lists->root;

    while(currentList != NULL)
    {
        ListNode<int>* currentNode = currentList->value->root;

        while(currentNode != NULL)
        {
            list->add(currentNode->value);

            currentNode=currentNode->next;
        }

        currentList=currentList->next;
    }

    bool isSorted = false;
    while(!isSorted)
    {
        isSorted=true;

        ListNode<int>* current = list->root;

        while(current->next != NULL)
        {
            if(current->next->value < current->value)
            {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;

                isSorted=false;
            }

            current=current->next;
        }
    }

    return list;
}

int main()
{
    List<int>* list1 = new List<int>();

    list1->add(6);
    list1->add(4);
    list1->add(2);

    List<int>* list2 = new List<int>();
    list2->add(1);
    list2->add(3);
    list2->add(5);

    List<List<int>*>* list = new List<List<int>*>();
    list->add(list1);
    list->add(list2);

    List<int>* sorted = sortLists(list);
    ListNode<int>* current = sorted->root;

    while(current != NULL)
    {
        cout << current->value << ' ';
        current=current->next;
    }



    return 0;
}
