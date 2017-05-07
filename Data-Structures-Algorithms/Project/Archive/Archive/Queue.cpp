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
#include "Queue.h"


// constructor (creates a new queue) 
template<class T>
Queue<T>::Queue(int d)
{
	if (d < 2) d = 2; //min a 2-heap is supported
	D = d;
	back = 0;
	size = SIZE;
	arr = new T*[size];
}

// is queue empty?
template<class T>
bool Queue<T>::empty() 
{
	return (back <= 0);
}

// is queue full?
template<class T>
bool Queue<T>::full() 
{
	return (back >= size);
}

// the front element of the queue 
template<class T>
T* Queue<T>::dequeue()
{
	if (empty())
	{
		cerr << "deq error! exiting..." << endl;
		exit(1);
	}

	T* rval = arr[0];
	arr[0] = arr[back - 1]; //the element in the back moved to front
	--back;
	reheapdown(0, back - 1); //reheapdown called to fix the order back 
	return rval;
}

// a copy of the front element is returned but the queue is not changed
template<class T>
T* Queue<T>::front()
{
	if (empty())
	{
		cerr << "deq error! exiting..." << endl;
		exit(1);
	}

	return arr[0];
}

// a new element to put in the queue
template<class T>
void Queue<T>::enqueue(T* foo)
{
	if (full()) //if the array is full then make it larger
	{
		int nsize = size + SIZE; //the size of the new array
		T* *narr = new T*[nsize]; //new array
		for (int i = 0;i < size;++i) //copy old array to the new one
			narr[i] = arr[i];
		delete[] arr; //delete reserved old array mem
		arr = narr; //pointer update
		size = nsize; //size update
	}

	//the new element added to the back of the queue
	//and the reheapup called to fix the order back
	arr[back++] = foo; //arr[back]=foo;++back;
	reheapup(0, back - 1);
}

// this is a recursive function to fix back the order in the queue
// upwards after a new element added back (bottom) of the queue 
template<class T>
void Queue<T>::reheapup(int root, int bottom)
{
	int parent; //parent node (in the virtual tree) of the bottom element

	if (bottom > root)
	{
		parent = (bottom - 1) / D;

		//compare the two node and if the order is wrong then swap them
		//and make a recursive call to continue upward in the virtual tree
		//until the whole tree heap order is restored   
		if (*arr[parent] > *arr[bottom])
		{
			swap(arr[parent], arr[bottom]);
			reheapup(root, parent);
		}
	}
}

// this is a recursive function to fix back the order in the queue
// downwards after a new element added front (root) of the queue 
template<class T>
void Queue<T>::reheapdown(int root, int bottom)
{
	int minchild, firstchild, child;

	firstchild = root*D + 1; //the position of the first child of the root

	if (firstchild <= bottom) //if the child is in the queue
	{
		minchild = firstchild; //first child is the min child (temporarily)

		for (int i = 2;i <= D;++i)
		{
			child = root*D + i; //position of the next child
			if (child <= bottom) //if the child is in the queue
			{
				//if the child is less than the current min child
				//then it will be the new min child
				if (*arr[child] < *arr[minchild])
				{
					minchild = child;
				}
			}
		}

		//if the min child found is less then the root(parent node)
		//then swap them and call reheapdown() recursively and
		//continue to fix the order in the virtual tree downwards
		if (*arr[root] > *arr[minchild])
		{
			swap(arr[root], arr[minchild]);
			reheapdown(minchild, bottom);
		}
	}
}

// the values of 2 variables will be swapped
template<class T>
void Queue<T>::swap(T* &a, T* &b)
{
	T* c = a;
	a = b;
	b = c;
}

// destructor (because default dest. does not erase the array)
template<class T>
Queue<T>::~Queue(void)
{
	delete[] arr;
}