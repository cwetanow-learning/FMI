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
#include "Node.h"


template<typename T>
Node<T>::Node(T val)
{
	value = val;

	left = NULL;
	right = NULL;
}

template<typename T>
Node<T>::Node()
{
	this->left = NULL;
	this->right = NULL;
}
