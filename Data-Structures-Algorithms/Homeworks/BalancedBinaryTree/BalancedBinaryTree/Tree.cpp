/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 4
* @compiler VC>
*
*/

#include "stdafx.h"
#include "Tree.h"

template<typename T>
Tree<T>::Tree()
{
	root = NULL;
}

template<typename T>
Tree<T>::Tree(Node<T>* root)
{
	this->root = root;
}

template<typename T>
int Tree<T>::GetSize()
{
	return Size(root);
}

template<typename T>
int Tree<T>::GetHeight()
{
	return Height(root);
}

template<typename T>
T* Tree<T>::Find(T data)
{
	Node<T>* current = root;

	while (current)
	{
		if (data == current->value)
		{
			return &current->value;
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

	return NULL;
}

template<typename T>
bool Tree<T>::Insert(T data)
{
	return Add(root, data);
}

template<typename T>
bool Tree<T>::Remove(T data)
{
	return Remove(root, data);
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
Node<T>* Tree<T>::GetLeftmost(Node<T>*& n)
{
	if (!n->left)
	{
		Node<T>* current = n;
		n = n->right;
		return current;
	}

	Node<T>* leftmost = GetLeftmost(n->left);
	return leftmost;
}

template<typename T>
bool Tree<T>::Remove(Node<T>*& n, T data)
{
	if (!n)
	{
		return false;
	}

	if (data < n->value)
	{
		bool result = Remove(n->left, data);
		return result;
	}

	if (n->value < data)
	{
		bool result = Remove(n->right, data);
		return result;
	}

	if (!n->right)
	{
		Node<T>* left = n->left;
		delete n;
		n = left;
	}
	else
	{
		Node<T>* left = GetLeftmost(n->right);
		left->left = n->left;
		left->right = n->right;
		delete n;
		n = left;
	}

	return true;
}
