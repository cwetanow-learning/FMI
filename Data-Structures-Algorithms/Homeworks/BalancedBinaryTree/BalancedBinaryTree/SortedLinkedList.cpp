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
#include "SortedLinkedList.h"

template<typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	this->head = NULL;
	this->count = 0;
}

template<typename T>
T* SortedLinkedList<T>::Add(T value)
{
	if (this->head == NULL)
	{
		this->head = new ListNode<T>(value);
		this->count++;
	}
	else
	{
		ListNode<T>* current = this->head;
		ListNode<T>* previous = NULL;

		while (current)
		{
			if (current->value < value)
			{
				previous = current;
				current = current->next;
				continue;
			}

			if (current->value == value)
			{
				return &current->value;
			}

			if (previous == NULL)
			{
				ListNode<T>* newNode = new ListNode<T>(value);
				newNode->next = current;
				this->head = newNode;
			}
			else
			{
				ListNode<T>* newNode = new ListNode<T>(value, previous);
				newNode->next = current;
			}

			this->count++;
			return NULL;
		}

		ListNode<T>* newNode = new ListNode<T>(value, previous);
		newNode->next = current;
		this->count++;
	}

	return NULL;
}

template<typename T>
ListNode<T>* SortedLinkedList<T>::getHead()
{
	return head;
}
