/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task
* @compiler VC>
*
*/

#include "stdafx.h"
#include "DynamicQueue.h"

template<class Type>
inline DynamicQueue<Type>::DynamicQueue(int capacity)
{
	this->capacity = capacity;
	this->data = new Type[this->capacity];
	this->head = -1;
	this->tail = 0;
	this->size = 0;
}

template<class Type>
DynamicQueue<Type>::~DynamicQueue()
{
	Clear();
}

template<class Type>
void DynamicQueue<Type>::Enqueue(Type item)
{
	if (this->size == this->capacity)
	{
		Resize();
	}

	if (this->IsEmpty())
	{
		ZeroHeadTail();
	}

	this->data[this->tail] = item;
	this->size++;
	this->tail = (this->tail + 1 % this->capacity);
}

template<class Type>
Type DynamicQueue<Type>::Dequeue()
{
	if (this->size == 0)
	{
		throw std::invalid_argument("queue is empty");
	}

	this->size--;
	int headIndex = this->head;

	this->head = (this->head + 1) % this->capacity;
	return this->data[headIndex];
}

template<class Type>
void DynamicQueue<Type>::Clear()
{
	delete[] this->data;
	this->data = NULL;
	this->size = 0;
	this->capacity = 4;
	this->head = -1;
	this->tail = 0;
}

template<class Type>
bool DynamicQueue<Type>::IsEmpty()
{
	return this->size == 0;
}

template<class Type>
int DynamicQueue<Type>::GetSize()
{
	return this->size;
}

template<class Type>
void DynamicQueue<Type>::Resize()
{
	this->capacity *= 2;
	Type* newData = new Type[this->capacity];

	for (size_t i = 0; i < this->size; i++)
	{
		int index = (i + this->head) % this->size;
		newData[i] = this->data[index];
	}

	this->head = 0;
	this->tail = this->size;

	delete[] data;

	this->data = newData;
}

template<class Type>
void DynamicQueue<Type>::ZeroHeadTail()
{
	this->head = 0;
	this->tail = 0;
}
