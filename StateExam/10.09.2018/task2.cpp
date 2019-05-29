#include <iostream>
#include <fstream>>
#include <cmath>

using namespace std;

struct ListNode
{
public :
    ListNode(int value)
    {
        this->value=value;
        this->kPositionsAhead=NULL;
    }

    ListNode(int value, ListNode* previous)
    {
        this->value=value;

        previous->next = this;
    }

    int value;

    ListNode* next;
    ListNode* kPositionsAhead;
};

struct List
{
public:
    int count;
    int k;
    ListNode* root;
    ListNode* last;

    List()
    {
        this->count = 0;
        this->k = 0;
    }

    add(int value)
    {
        if(this->count == 0)
        {
            this->root = new ListNode(value);
            this->last = this->root;
        }
        else
        {
            this->last= new ListNode(value, this->last);
        }

        this->count++;
    }

    setKthPointers()
    {
        this->k = ceil(sqrt(this->count));

        ListNode* current=this->root->next;
        ListNode* kthPrevious = this->root;

        for(int i=1; i<this->count; i++)
        {
            if(i%k == 0)
            {
                kthPrevious->kPositionsAhead = current;
                kthPrevious = current;
            }

            current = current->next;
        }
    }

    bool contains(int number)
    {
        ListNode* current=this->root;

        while(current->value < number)
        {
            if(current->kPositionsAhead != NULL && current->kPositionsAhead->value<number )
            {
                current= current->kPositionsAhead;
            }
            else
            {
                current=current->next;
            }
        }

        return current->value == number;
    }
};

List* constructList(string input)
{
    int number=0;

    List* list = new List();

    for(int i =0; i < input.length(); i++)
    {
        if(input[i]==' ')
        {
            list->add(number);
            number=0;
        }
        else
        {
            number = number*10 + (input[i]-'0');
        }
    }

    list->add(number);


    list->setKthPointers();

    return list;
}

bool member(List* list, int number)
{
    return list->contains(number);
}

List* readList(char* filePath)
{
    ifstream file(filePath);

    if(file)
    {
        string line;
        getline(file, line);

        return constructList(line);
    }
}

int main()
{
    List* list = constructList("1 2 3 4 5 6 7 8 9");

    cout << list->contains(5) << endl;

    return 0;
}
