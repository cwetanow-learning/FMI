/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 5
* @compiler VC>
*
*/

#include "stdafx.h"
#include "Tree.h"

template<typename T>
Tree<T>* Tree<T>::operator=(Tree<T> other)
{
	this->root = other.root;
	return this;
}

template<typename T>
Tree<T>::Tree()
{
	root = NULL;
}

template<typename T>
bool Tree<T>::Insert(T data)
{
	return Add(root, data);
}

template<typename T>
bool Tree<T>::Contains(T data)
{
	Node<T>* current = root;

	while (current)
	{
		if (data == current->value)
		{
			return true;
		}

		if (data < current->value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return false;
}

template<typename T>
void Tree<T>::Traverse(std::vector<T>& list)
{
	this->Traverse(this->root, list);
}

template<typename T>
bool Tree<T>::Add(Node<T>*& n, T data)
{
	if (n == NULL)
	{
		n = new Node<T>(data);
		return true;
	}

	if (data < n->value)
	{
		bool result = Add(n->left, data);

		return result;
	}
	else if (n->value < data)
	{
		bool result = Add(n->right, data);

		return result;
	}

	return false;
}

template<typename T>
void Tree<T>::Traverse(Node<T>* node, std::vector<T>& list)
{
	if (node == NULL)
	{
		return;
	}

	this->Traverse(node->left, list);
	
	list.push_back(node->value);
	
	this->Traverse(node->right, list);
}
