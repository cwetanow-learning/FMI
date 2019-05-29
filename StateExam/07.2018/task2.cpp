#include <iostream>
#include <sstream>

using namespace std;

struct TernaryTree
{
public:
    char character;

    TernaryTree* leftChild;
    TernaryTree* middleChild;
    TernaryTree* rightChild;

    TernaryTree(char character)
    {
        this->character=character;
        this->leftChild=NULL;
        this->middleChild=NULL;
        this->rightChild=NULL;
    }
};

int findTreeDepth(TernaryTree* tree, int currentDepth)
{
    if(tree == NULL)
    {
        return currentDepth;
    }

    int leftDepth = findTreeDepth(tree->leftChild, currentDepth+1);
    int middleDepth = findTreeDepth(tree->middleChild, currentDepth+1);
    int rightDepth = findTreeDepth(tree->rightChild, currentDepth+1);

    if(leftDepth > middleDepth)
    {
        return leftDepth > rightDepth ? leftDepth : middleDepth;
    }
    else
    {
        return middleDepth > rightDepth ? middleDepth : middleDepth;
    }
}

void printTreeLevel(TernaryTree* tree, int level, int currentLevel)
{
    if(tree == NULL)
    {
        return;
    }

    if(level==currentLevel)
    {
        cout << tree->character << ' ';
    }
    else
    {
        printTreeLevel(tree->leftChild,level,currentLevel+1);
        printTreeLevel(tree->middleChild,level,currentLevel+1);
        printTreeLevel(tree->rightChild,level,currentLevel+1);
    }
}

void readLast(TernaryTree* tree)
{
    int depth = findTreeDepth(tree, 1);

    printTreeLevel(tree,depth,1);
}

string serializeTree(TernaryTree* tree)
{
    if(tree == NULL)
    {
        return "*";
    }

    string left="(";
    string space=" ";
    string right=")";
    return left + tree->character + space + serializeTree(tree->leftChild) +space + serializeTree(tree->middleChild)+ space + serializeTree(tree->rightChild) + right;
}

void serialize(TernaryTree* tree, string filePath)
{
    string serialized = serializeTree(tree);

    cout << serialized << endl;
}

int main()
{
    TernaryTree* root = new TernaryTree('b');

    root->leftChild = new TernaryTree('x');
    root->leftChild->leftChild = new TernaryTree('p');
    root->leftChild->middleChild = new TernaryTree('q');
    root->leftChild->rightChild= new TernaryTree('r');
    root->leftChild->rightChild->leftChild = new TernaryTree('c');
    root->leftChild->rightChild->rightChild = new TernaryTree('a');

    root->middleChild= new TernaryTree('y');
    root->middleChild->rightChild= new TernaryTree('s');
    root->middleChild->rightChild->middleChild= new TernaryTree('t');

    readLast(root);

    return 0;
}
