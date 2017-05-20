/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task
* @compiler VC>
*
*/

#include "stdafx.h"
#include "Tree.h"
#include<iomanip> //for width()
#define width_unit 5

//constructor
Tree::Tree(void)
{
	Node* N = new Node;
	root = N;
}

//recursive func to delete the whole tree
void Tree::chop(Node *N)
{
	if (N)
	{
		chop(N->left);
		chop(N->right);
		delete N;
	}
}

//destructor for tree objects
Tree::~Tree(void)
{
	chop(root);
}

unsigned int Tree::get_freq(void) const
{
	return root->frequency;
}

unsigned char Tree::get_char(void) const
{
	return root->character;
}

void Tree::set_freq(unsigned int f)
{
	root->frequency = f;
}

void Tree::set_char(unsigned char c)
{
	root->character = c;
}

Tree::Node* Tree::get_left(void) const
{
	return root->left;
}

Tree::Node* Tree::get_right(void) const
{
	return root->right;
}

void Tree::set_left(Node* N)
{
	root->left = N;
}

void Tree::set_right(Node* N)
{
	root->right = N;
}

Tree::Node* Tree::get_root(void) const
{
	return root;
}

bool Tree::operator==(const Tree & T) const
{
	return (root->frequency == T.root->frequency);
}

bool Tree::operator!=(const Tree & T) const
{
	return (root->frequency != T.root->frequency);
}

bool Tree::operator<(const Tree & T) const
{
	return (root->frequency < T.root->frequency);
}

bool Tree::operator>(const Tree & T) const
{
	return (root->frequency > T.root->frequency);
}

bool Tree::operator<=(const Tree & T) const
{
	return (root->frequency <= T.root->frequency);
}

bool Tree::operator>=(const Tree & T) const
{
	return (root->frequency >= T.root->frequency);
}

void Tree::GetBinaryString(Node * node, unsigned char character, string currentPath, string & result)
{
	if (node) 
	{
		if (!node->left && !node->right && node->character == character)
		{
			result = currentPath;
		}
		else
		{
			GetBinaryString(node->left, character, currentPath + "0", result);
			GetBinaryString(node->right, character, currentPath + "1", result);
		}
	}
}

bool Tree::GetCharacter(string binaryString, unsigned char & character)
{
	Node * current = root;
	for (unsigned int i = 0;i < binaryString.size();++i)
	{
		if (binaryString[i] == '0')
		{
			current = current->left;
		}

		if (binaryString[i] == '1')
		{
			current = current->right;
		}
	}

	bool found = false;

	if (!current->left && !current->right)
	{
		found = true;
		character = current->character;
	}

	return found;
}