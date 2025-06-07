#include<iostream>
#include<stdarg.h>
#include"Integers.h"
using namespace std;
//Array::Array(int cap = 0) 
//{
//	if (cap <= 0)
//	{
//		data = nullptr;
//		capacity = 0;
//	}
//	else
//	{
//		data = new int[cap];
//		capacity = cap;
//	}
//}
void Array::copyIntegerArray(int* const destinationArray, const int* const sourceArray, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		destinationArray[i] = sourceArray[i];
	}
}
Array::Array()
{
	data = nullptr;
	capacity = 0;
}
Array::Array(int size = 0,...) //:Array()
{
	va_list list;
	va_start(list, size);
	data = new int[size];
	capacity = size;
	for (int i = 0; i <  size; i = i + 1)
	{
		data[i] = va_arg(list, int);
	}
	va_end(list);
}
Array::Array(const Array& i2)
{
	if (i2.data != nullptr)
	{
		capacity = i2.capacity;
		data = new int[capacity];
		copyIntegerArray(data, i2.data, capacity);
	}
}
Array::~Array()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = 0;
}
void Array::display()
{
	if (data != nullptr)
	{
		for (int i = 0; i < capacity; i = i + 1)
		{
			cout << data[i] ;
			if (i < (capacity - 1))
			{
				cout << ", ";
			}
		}
	}
}
int& Array::operator[](int index)
{
	if (data != nullptr && index >= 0 && index < capacity)
	{
		int& a = data[index];
		return a;
	}
	exit(0);
}
const int& Array::operator[](int index) const
{
	if (data != nullptr && index >= 0 && index < capacity)
	{
		const int& a = data[index];
		return a;
	}
}
int Array::getCapacity()
{
	if (data != nullptr)
	{
		return capacity;
	}
	exit(0);
}
void Array::reSize(int newCapacity)
{
	if (data != nullptr)
	{
		if (newCapacity <= 0)
		{
			this->~Array();
		}
		else
		{
			int* temp = new int[newCapacity];
			if (newCapacity >= capacity)
			{
				copyIntegerArray(temp, data, capacity);
			}
			else
			{
				copyIntegerArray(temp, data, newCapacity);
			}
			this->~Array();
			data = temp;
			capacity = newCapacity;
		}
	}
}
void Array::sort()	// additional function
{
	for (int i = 0; i < capacity; i = i + 1)
	{
		int minIndex = i;
		for (int j = i; j < capacity; j = j + 1)
		{
			if (data[minIndex] > data[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
        	{
            		int temp = data[i];
            		data[i] = data[minIndex];
            		data[minIndex] = temp;
        	}
	}
}
int Array::binarySearch(int key)		//Only works with Sorted arrays
{
	if (data != nullptr)
	{
		int lowerLimit = 0;
		int upperLimit = capacity;
		int middle = upperLimit / 2;
		while (lowerLimit <= upperLimit)
		{
			if (data[middle] == key)
			{
				return middle;
			}
			else if (key > data[middle])
			{
				lowerLimit = middle + 1;
			}
			else
			{
				upperLimit = middle - 1;
			}
			middle = (upperLimit + lowerLimit) / 2;
		}
	}
	return -1;
}