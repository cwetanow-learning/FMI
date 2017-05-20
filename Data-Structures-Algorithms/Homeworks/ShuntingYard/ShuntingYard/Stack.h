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
class Stack
{
public:
	Stack(int capacity = 8);
	~Stack();

public:
	void Push(Type item);
	Type Pop();
	Type& Peek();
	void Clear();
	bool IsEmpty();
	int GetSize();

private:
	Type *data;
	int head;
	int size;
	int capacity;
	void Resize();
};
