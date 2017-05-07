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

#pragma once
#include "Node.cpp"

template<typename T>
class Tree
{
public:
	Tree();
	Tree(Node<T>* root);

	int GetSize();
	int GetHeight();

	T* Find(T data);
	bool Insert(T data);
	bool Remove(T data);
	bool Contains(T data);

private:
	Node<T>* root;

	bool Add(Node<T>*& n, T data);

	Node<T>* GetLeftmost(Node<T>*& n);

	bool Remove(Node<T>*& n, T data);
};