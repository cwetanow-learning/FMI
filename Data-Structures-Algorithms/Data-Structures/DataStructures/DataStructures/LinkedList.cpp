#include "stdafx.h"
#include "LinkedList.h"
#include "ListNode.h"

template<class Type>
inline LinkedList<Type>::LinkedList()
{
	this->count = 0;
	this->head = NULL;
	this->tail = NULL;
}

template<class Type>
LinkedList<Type>::~LinkedList()
{
	this->Clear();
}

template<class Type>
int LinkedList<Type>::Count()
{
	return this->count;
}

template<class Type>
void LinkedList<Type>::Add(Type element)
{
	if (this->IsEmpty())
	{
		this->head = new ListNode(element);
		this->tail = this->head;
	}
	else
	{
		this->tail = new ListNode(element, this->tail);
	}

	this->count++;
}

template<class Type>
void LinkedList<Type>::RemoveAt(int index)
{
	if (index < 0 || index >= this->count)
	{
		throw std::invalid_argument("index is invalid");
	}

	int current = 0;
	ListNode* currentNode = this->head;
	ListNode* prevNode = NULL;

	while (current < index)
	{
		prevNode = currentNode;
		currentNode = prevNode.next;

		current++;
	}

	this->count--;

	if (this->IsEmpty())
	{
		this.head = NULL;
	}
	else if (prevNode == NULL)
	{
		this->head = currentNode.next;
	}
	else
	{
		prevNode.next = currentNode.next;
	}

	ListNode* last = NULL;
	if (this.head != NULL)
	{
		last = this.head;
		while (last != null)
		{
			last = last.next;
		}
	}
	this->tail = last;
}

template<class Type>
inline bool LinkedList<Type>::Contains(Type element)
{
	int indexOfEl = this->IndexOf(element);

	return indexOfEl != -1;
}


