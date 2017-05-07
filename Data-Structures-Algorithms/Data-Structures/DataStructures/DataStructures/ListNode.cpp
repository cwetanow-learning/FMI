#include "stdafx.h"
#include "ListNode.h"

template<class Type>
inline ListNode<Type>::ListNode(Type obj)
{
	this->element = obj;
	this->next = null;
}

template<class Type>
ListNode<Type>::ListNode(Type obj, ListNode previous)
{
	this->element = obj;
	this->next = null;

	previous.next = this;
}
