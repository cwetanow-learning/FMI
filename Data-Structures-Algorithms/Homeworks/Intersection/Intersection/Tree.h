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

#pragma once
#include "Node.cpp"

#include <vector>

template<typename T>
class Tree
{
public:
	Tree<T>* operator=(Tree<T> other);

	Tree();

	bool Insert(T data);
	bool Contains(T data);

	void Traverse(std::vector<T>& list);

private:
	Node<T>* root;

	bool Add(Node<T>*& n, T data);

	void Traverse(Node<T>* node, std::vector<T>& list);
};