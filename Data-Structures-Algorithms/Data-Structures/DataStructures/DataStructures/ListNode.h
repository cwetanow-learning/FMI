#pragma once

template <class Type>
class ListNode
{
public:
	ListNode(Type obj);
	ListNode(Type obj, ListNode previous);

	Type element;
	ListNode next;
};

