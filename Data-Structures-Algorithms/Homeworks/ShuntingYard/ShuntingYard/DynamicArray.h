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

#pragma once

template<typename Type>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(DynamicArray const&);
	DynamicArray<Type>& operator=(DynamicArray const&);

	~DynamicArray();

public:
	int Count();
	void Clear();
	void Add(Type& item);
	void Insert(Type& item, int index);
	Type& ElementAt(int index);
	int IndexOf(Type data);
	bool Contains(Type& item);
	void RemoveAt(int index);
	void Remove(Type& item);

private:
	Type *data;
	int size;
	int capacity;
	void Resize();
};

