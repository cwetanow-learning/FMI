#pragma once
#include "ListNode.h"

template <class Type>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	int Count();
	void Add(Type element);
	void RemoveAt(int index);
	void Remove(Type element);
	int IndexOf(Type element);
	Type* ElementAt(int index);

	bool Contains(Type element);
	bool IsEmpty();

	void Clear();

private:
	ListNode* head;
	ListNode* tail;
	int count;
};

