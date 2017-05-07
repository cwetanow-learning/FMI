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

