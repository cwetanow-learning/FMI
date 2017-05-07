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

#include "ListNode.cpp"

template<typename T>
class SortedLinkedList
{
public:
	SortedLinkedList();
	T* Add(T value);
	ListNode<T>* getHead();

	int count;
private:
	ListNode<T>* head;
	ListNode<T>* tail;
};