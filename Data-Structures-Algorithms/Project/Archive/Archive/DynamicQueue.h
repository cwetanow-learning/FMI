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

#pragma once
template<class Type>
class DynamicQueue
{
public:
	DynamicQueue(int capacity = 8);
	~DynamicQueue();
	
	void Enqueue(Type item);
	Type Dequeue();
	void Clear();
	bool IsEmpty();
	int GetSize();

private:
	Type* data;
	int capacity;
	int head;
	int tail;
	int size;

	void Resize();
	void ZeroHeadTail();
};

