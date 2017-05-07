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
template<class T>
class Queue
{
public:

	Queue(int d = 2); //constructor 
	~Queue(void); //destructor
	void enqueue(T*); //enqueue (to push)
	T* dequeue(); //dequeue (to pop)
	T* front(); //the front element
	bool empty(); //is empty?
	bool full(); //is full?

private:

	int back; //the last element in the queue
	T* *arr; //dynamic array
	int size; //current size of the queue array
	static const int SIZE = 10; //size increment step size  
	int D; //max number of children for a parent>=2 
		   //copy constructor and assignment are hidden to protect 
	Queue(const Queue &);
	const Queue & operator=(const Queue &);

	//utility functions to fix the heap
	//when an element added or removed 
	void reheapup(int root, int bottom); //fix heap upward
	void reheapdown(int root, int bottom); //fix heap downward
	void swap(T* & a, T* & b); //swap f. needed by reheapup/down functions

}; //end class