/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 2
* @compiler VC>
*
*/

#include "stdafx.h"
#include "DynamicArray.h"

template<typename Type>
DynamicArray<Type>::DynamicArray(int capacity)
{
	this->capacity = capacity;
	this->data = new Type[this->capacity];
	this->size = 0;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(DynamicArray const & other)
{
	this->capacity = other->capacity;
	this->size = other->size;
	this->data = new Type[other->capacity];

	for (size_t i = 0; i < other->size; i++)
	{
		this->data[i] = other->data[i];
	}
}

template<typename Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(DynamicArray const & other)
{
	return new DynamicArray<Type>(other);
}

template<typename Type>
DynamicArray<Type>::~DynamicArray()
{
	this->Clear();
}

template<typename Type>
int DynamicArray<Type>::Count()
{
	return this->size;
}

template<typename Type>
void DynamicArray<Type>::Clear()
{
	delete[] this->data;
	this->data = NULL;
	this->size = 0;
	this->capacity = 4;
}

template<typename Type>
void DynamicArray<Type>::Add(Type& item)
{
	++this->size;

	if (this->size == this->capacity)
	{
		Resize();
	}

	this->data[this->size - 1] = item;
}

template<typename Type>
void DynamicArray<Type>::Insert(Type& item, int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::invalid_argument("index out of range");
	}

	++this->size;
	if (this->size == this->capacity)
	{
		Resize();
	}

	for (int i = this->size; i > index; i--)
	{
		this->data[i] = this->data[i - 1];
	}

	this->data[index] = item;
}

template<typename Type>
Type & DynamicArray<Type>::ElementAt(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::invalid_argument("index out of range");
	}

	return this->data[index];
}

template<typename Type>
int DynamicArray<Type>::IndexOf(Type data)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == data)
		{
			return i;
		}
	}

	return -1;
}

template<typename Type>
bool DynamicArray<Type>::Contains(Type & item)
{
	for (int i = 0; i < this->size; i++)
	{
		if (&this->data[i] == data)
		{
			return true;
		}
	}

	return false;
}

template<typename Type>
void DynamicArray<Type>::RemoveAt(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::invalid_argument("index out of range");
	}

	for (int i = index; i < this->size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	--this->size;
}

template<typename Type>
void DynamicArray<Type>::Remove(Type & item)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == item)
		{
			this->RemoveAt(i);
			break;
		}
	}
}

template<typename Type>
void DynamicArray<Type>::Resize()
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
