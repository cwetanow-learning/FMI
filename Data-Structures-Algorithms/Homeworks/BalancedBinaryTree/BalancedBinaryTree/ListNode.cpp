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
#include "ListNode.h"

template<typename T>
ListNode<T>::ListNode(T value)
{
	this->value = value;
	this->next = NULL;
}

template<typename T>
ListNode<T>::ListNode(T value, ListNode * prev)
{
	this->value = value;
	prev->next = this;
	this->next = NULL;
}
