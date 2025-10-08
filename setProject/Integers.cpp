#include<iostream>
#include<stdarg.h>
#include"Integers.h"
using namespace std;
void Array::copyIntegerArray(int* const destinationArray, const int* const sourceArray, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		destinationArray[i] = sourceArray[i];
	}
}
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
int Array::getElement(int index)const
{
	if(index >= 0 && index < capacity)
	{
		int a = data[index];
		return a;
	}
	exit(0);
}
bool Array::isEmpty() const
{
	return (data == nullptr) ? true : false;
}
Array::Array()
{
	data = nullptr;
	capacity = 0;
}
Array::Array(int size=0,...) //:Array()
{
	if (size == 0)
	{
		data = nullptr;
		capacity = 0;
	}
	else
	{
		va_list list;
		va_start(list, size);
		data = new int[size];
		capacity = size;
		for (int i = 0; i < size; i = i + 1)
		{
			data[i] = va_arg(list, int);
		}
		va_end(list);
	}
}
Array::Array(const Array& i2) //:Array()
{
	if (i2.data != nullptr)
	{
		capacity = i2.capacity;
		data = new int[capacity];
		copyIntegerArray(data, i2.data, capacity);
	}
	else
	{
		data = nullptr;
		capacity = 0;
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
void Array::display()const
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
int& Array::getset(int index)
{
	if (data != nullptr && index >= 0 && index < capacity)
	{
		int& a = data[index];
		return a;
	}
	exit(0);
}
int Array::getCapacity()const
{
	return capacity;
}
void Array::reSize(int newCapacity)
{
	//if (data != nullptr)
	{
		if (newCapacity <= 0)
		{
			this->~Array();
		}
		/*else if (newCapacity == 1)
		{
			data = new int[1];
			capacity = 1;
		}*/
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
		int lowNumber = data[i];
		for (int j = i; j < capacity; j = j + 1)
		{
			if (lowNumber > data[j])
			{
				lowNumber = data[j];
				int number = data[i];
				data[i] = lowNumber;
				data[j] = number;
			}
		}
	}
}