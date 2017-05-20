/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 1
* @compiler VC>
*
*/

//#include "stdafx.h"
#include "Stack.h"

template<typename Type>
inline Stack<Type>::Stack(int capacity = 8)
{
	this->capacity = capacity;
	this->data = new Type[this->capacity];
	this->head = -1;
	this->size = 0;
}

template<typename Type>
Stack<Type>::~Stack()
{
	this->Clear();
}

template<typename Type>
void Stack<Type>::Push(Type item)
{
	++this->size;
	if (this->size == this->capacity)
	{
		Resize();
	}

	++this->head;
	this->data[this->head] = item;
}

template<typename Type>
Type Stack<Type>::Pop()
{
	if (IsEmpty())
	{
		throw std::invalid_argument("stack is empty");
	}

	Type result = this->data[this->head];

	--this->head;
	--this->size;

	return result;
}

template<typename Type>
Type & Stack<Type>::Peek()
{
	if (IsEmpty())
	{
		throw std::invalid_argument("stack is empty");
	}

	return this->data[this->head];
}

template<typename Type>
void Stack<Type>::Clear()
{
	delete[] this->data;
	this->data = NULL;
	this->size = 0;
	this->capacity = 4;
	this->head = -1;
}

template<typename Type>
bool Stack<Type>::IsEmpty()
{
	return head == -1 ? true : false;
}

template<typename Type>
int Stack<Type>::GetSize()
{
	return this->size;
}

template<typename Type>
void Stack<Type>::Resize()
{
	this->capacity *= 2;
	Type* newData = new Type[this->capacity];

	for (size_t i = 0; i < this->size; i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;

	this->data = newData;
}
