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
