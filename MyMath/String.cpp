#include<iostream>
#include"String.h"
using namespace std;
int String::getNumberLength(long long int num)
{
	int lengthCount = 0;
	while (num)
	{
		num = num / 10;
		lengthCount = lengthCount + 1;
	}
	return lengthCount;
}
int String::getStringLength(const char* const array)const
{
	int length = 0;
	while (array[length] != '\0')
	{
		length = length + 1;
	}
	return length;
}
void String::copyString(char* const destinationArray, const char const* sourceArray, int counter) const
{
	int i = 0;
	while (sourceArray[i] != '\0')
	{
		destinationArray[counter] = sourceArray[i];
		counter = counter + 1;
		i = i + 1;
	}
	destinationArray[counter] = '\0';
}
void String::populatingArray(const char* const sourceKey, const int startingPoint, const int sourceKeyLength)
{
	for (int i = startingPoint, j = 0; j < sourceKeyLength; i = i + 1, j = j + 1)
	{
		data[i] = sourceKey[j];
	}
}
void String::shiftBits(const int destinationArrayLength, const int startingPoint, const int sourceArrayLength)
{
	int tempSize = size + sourceArrayLength + 2;
	char* ptr = new char[tempSize];
	copyString(ptr, data);
	this->~String();
	data = ptr;
	size = tempSize;
	ptr = nullptr;
	for (int i = destinationArrayLength - 1; i >= startingPoint; i = i - 1)
	{
		data[i + sourceArrayLength] = data[i];
	}
}
bool String::isEmpty() const
{
	return (data == nullptr) ? true : false;
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c) :String()
{
	if (c == '\0')
	{
		size = 1;
		data = new char[size];
		data[0] = c;
	}
	else
	{
		size = 2;
		data = new char[size];
		data[0] = c;
		data[1] = '\0';
	}
}
String::String(const char* str) :String()
{
	if (str != nullptr)
	{
		int l = getStringLength(str);
		size = l + 1;
		data = new char[size];
		copyString(data, str);
	}
}
String::String(const String& s)
{
	if ((s.isEmpty()))
	{
		return;
	}
	/*if (!(isEmpty()))
	{
		cout << "Hello";
		this->~String();
	}*/
	int requiredSize = s.getLength();
	requiredSize = requiredSize + 1;
	data = new char[requiredSize];
	copyString(data, s.data);
	size = requiredSize;
}
String::~String()
{
	delete[]data;
	data = nullptr;
	size = 0;
}
void String::input()
{
	this->~String();
	data = new char[1];
	size = 1;
	data[0] = '\0';
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		reSize(getLength() + 1);
		data[size - 2] = ch;
		data[size - 1] = '\0';
	}
}
char& String::at(const int index)
{
	if (index <= (size - 2) && index >= 0 && !(isEmpty()))
	{
		char& c = data[index];
		return c;
	}
	exit(0);
}
const char& String::at(const int index) const
{
	if (index <= (size - 2) && index >= 0 && !(isEmpty()))
	{
		const char& c = data[index];
		return c;
	}
	exit(0);
}
int String::getLength() const
{
	if (!(isEmpty()))
	{
		int l = getStringLength(data);
		return l;
	}
}
int String::getSize() const
{
	if (!(isEmpty()))
	{
		return size;
	}
	exit(0);
}
void String::display()const
{
	if (!(isEmpty()))
	{
		cout << data;
		return;
	}
	exit(0);
}
int String::find(const String& subStr, const int start = 0) const
{
	if (!(isEmpty()) && !(subStr.isEmpty()))
	{
		int startingBit = -1;
		bool status = false;
		int counter = start;
		while (this->data[counter] != '\0' && !status)
		{
			int i = 0;
			if (this->data[counter] == subStr.data[i])
			{
				i = i + 1;
				counter = counter + 1;
				while (this->data[counter] != '\0' && this->data[counter] == subStr.data[i])
				{
					counter = counter + 1;
					i = i + 1;
				}
			}
			if (getStringLength(subStr.data) == i)
			{
				startingBit = counter - i;
				status = true;
			}
			counter = counter + 1;
		}
		return startingBit;
	}
	exit(0);
}
void String::insert(const int index, const String& subStr)
{
	if (!(isEmpty()) && !(subStr.isEmpty()))
	{
		int sourceArrayLength = subStr.getLength();
		int destinationArrayLength = getSize();
		if (index <= destinationArrayLength)
		{
			shiftBits(destinationArrayLength, index, sourceArrayLength);
			populatingArray(subStr.data, index, sourceArrayLength);
		}
	}
	return;
}
void String::remove(int index, int count)
{
	if (!(isEmpty()) && (count > 0) && (index >= 0))
	{
		int destinationArrayLength = getLength();
		if ((index + count) <= destinationArrayLength)
		{
			for (int i = index + count; i <= destinationArrayLength; i = i + 1)
			{
				data[i - count] = data[i];
			}
		}
	}
	return;
}
int String::replace(const String& old, const String& newSubStr)
{
	if (!(isEmpty()) && !(old.isEmpty()) && !(newSubStr.isEmpty()))
	{
		int count = 0;
		char* temp = nullptr;
		int diff = newSubStr.getLength() - old.getLength();
		for (int j = 0; j <= getLength(); j = j + 1)
		{
			int i = find(old, j);
			if (i >= 0)
			{
				j = i + newSubStr.getLength() - 1;
				count = count + 1;
				reSize(getSize() + diff + 1);
				remove(i, old.getLength());
				insert(i, newSubStr);
			}
		}
		return count;
	}
	exit(0);
}
void String::trimRight()
{
	if (!(isEmpty()))
	{
		int l = getLength();
		while ((l > 0) && (data[l - 1] == ' ' || data[l - 1] == '\n' || data[l - 1] == '\t'))
		{
			l--;
		}
		data[l] = '\0';
	}
}
void String::trimLeft()
{
	if (!(isEmpty()))
	{
		int i = 0, j = 0;
		bool status = true;
		while (data[i] != '\0' && status)
		{
			if ((data[0] == ' ') || (data[0] == '\n') || (data[0] == '\t'))
			{
				remove(0);
			}
			else
			{
				status = false;
			}
		}
	}
}
void String::trim()
{
	if (!(isEmpty()))
	{
		trimRight();
		trimLeft();
	}
}
void String::makeUpper()
{
	if (!(isEmpty()))
	{
		int i = 0;
		while (data[i] != '\0')
		{
			if (data[i] != ' ' && data[i] >= 'a' && data[i] <= 'z')
			{
				data[i] = data[i] + ('A' - 'a');
			}
			i++;
		}

	}
}
void String::makeLower()
{
	if (!(isEmpty()))
	{
		int i = 0;
		while (data[i] != '\0')
		{
			if (data[i] != ' ' && data[i] >= 'A' && data[i] <= 'Z')
			{
				data[i] = data[i] - ('A' - 'a');
			}
			i++;
		}
	}
}
void String::reverse()
{
	if (!(isEmpty()))
	{
		int l = getLength();
		l--;
		char ch;
		for (int i = 0; i <= (l / 2); i = i + 1)
		{
			ch = data[i];
			data[i] = data[l - i];
			data[l - i] = ch;
		}

		/*int l = getLength();
		int tempSize = size;
		char* ptr;
		ptr = new char[tempSize];
		int i = 0;
		while (data[i] != '\0')
		{
			ptr[l - 1] = data[i];
			l--;
			i++;
		}
		ptr[i] = '\0';
		this->~String();
		data = ptr;
		ptr = nullptr;
		size = tempSize;*/
	}
}
void String::reSize(int capacity)
{
	if (!(isEmpty()))
	{
		if (capacity <= 0)
		{
			this->~String();
		}
		else
		{
			char* ptr = new char[capacity + 1];
			int originalStringLength = getLength();
			if (originalStringLength == capacity)
			{
				//If capacity == existing capacity, no need to reSize.
				return;
			}
			if (originalStringLength < (capacity))
			{
				for (int i = 0; data[i] != '\0'; i = i + 1)
				{
					ptr[i] = data[i];
				}
				ptr[originalStringLength] = '\0';
			}
			else
			{
				for (int i = 0; i <= capacity; i = i + 1)
				{
					ptr[i] = data[i];
				}
				ptr[capacity] = '\0';
			}
			this->~String();
			size = capacity + 1;
			data = ptr;
			ptr = nullptr;
		}
	}
}
void String::shrink()
{
	if (!(isEmpty()))
	{
		int l = getLength();
		reSize(l);
	}
}
int String::compare(const String& s2)const
{
	if (!(isEmpty()) && !(s2.isEmpty()))
	{
		int value = 0, i = 0;
		bool status = true;
		while (data[i] != '\0' && s2.data[i] != '\0' && status)
		{
			if (data[i] == s2.data[i])
			{
				i = i + 1;
			}
			else
			{
				if (data[i] > s2.data[i])
				{
					value = 1;
				}
				else
				{
					value = -1;
				}
				status = false;
			}
		}
		if (value == 0)
		{
			if (getLength() > s2.getLength())
			{
				value = 1;
			}
			else if (getLength() < s2.getLength())
			{
				value = -1;
			}
			else
			{
				value = 0;
			}
		}
		return value;
	}
	exit(0);
}
String String::left(const int count)
{
	if (!(isEmpty()) && count <= getLength() && count >= 0)
	{
		char* temp = new char[count + 1];
		for (int i = 0; i < count; i = i + 1)
		{
			temp[i] = data[i];
		}
		temp[count] = '\0';
		String s;
		s.data = temp;
		temp = nullptr;
		s.size = count + 1;
		return s;
	}
	exit(0);
}
String String::right(const int count)
{
	int l = getLength();
	if (!(isEmpty()) && count <= l && count >= 0)
	{
		char* temp = new char[count + 1];
		copyString(temp, &data[(l - count)]);
		String s;
		s.data = temp;
		temp = nullptr;
		s.size = count + 1;
		return s;
	}
	exit(0);
}
long long int String::convertToInteger()const
{
	if (!(isEmpty()))
	{
		bool negativeStatus = false, stringValidityStatus = true;
		//negativeStatus checks if coming string carrying negative number.
		//stringValidityStatus checks if the string is valid.
		long long int number = 0;
		int lengthOfString = getLength();
		for (int i = 0; i < lengthOfString && stringValidityStatus; i = i + 1)
		{
			char ch = data[i];
			if (i == 0)
			{
				if (ch == '-')
				{
					negativeStatus = true;
				}
				else if (ch == '+' || (ch >= '0' && ch <= '9'))
				{
					if (ch >= '0' && ch <= '9')
					{
						number = number + ch - '0';
					}
				}
				else
				{
					stringValidityStatus = false;
				}
			}
			else
			{
				if (ch >= '0' && ch <= '9')
				{
					number = (number * 10) + ch - '0';
				}
				else
				{
					stringValidityStatus = false;
				}
			}
		}
		if (negativeStatus)
		{
			number = number * -1;
		}
		if (stringValidityStatus)
		{
			return number;
		}
	}
	exit(0);
}
float String::convertToFloat()const
{
	if (!(isEmpty()))
	{
		int div = 1;
		bool negativeStatus = false, stringValidityStatus = true, statusForDiv = false;
		//negativeStatus checks if coming string carrying negative number.
		//stringValidityStatus checks if the string is valid.
		//statusForDiv is a flag for checking position of point. 
		float number = 0;
		for (int i = 0; i < getLength() && stringValidityStatus; i = i + 1)
		{
			char ch = data[i];
			if (i == 0)
			{
				if (ch == '-')
				{
					negativeStatus = true;
				}
				else if (ch == '+' || (ch >= '0' && ch <= '9'))
				{
					if (ch >= '0' && ch <= '9')
					{
						number = number + ch - '0';
					}
				}
				else if (ch == '.')
				{
					statusForDiv = true;
				}
				else
				{
					stringValidityStatus = false;
				}
			}
			else
			{
				if (ch >= '0' && ch <= '9')
				{
					number = (number * 10) + ch - '0';
				}
				else if (ch == '.')
				{
					statusForDiv = true;
				}
				else
				{
					stringValidityStatus = false;
				}
			}
			if (statusForDiv)
			{
				div = div * 10;
			}
		}
		if (negativeStatus)
		{
			number = number * -1;
		}
		if (stringValidityStatus)
		{
			if (statusForDiv)
			{
				number = number / (div / 10);
			}
			return number;
		}
	}
	exit(0);
}
String String::concatinate(const String& s2)const
{
	if (!(isEmpty()) && !(s2.isEmpty()))
	{
		int lengthOfCallingObject = getLength();
		int requiredSize = lengthOfCallingObject + s2.getLength() + 1;
		char* temp = new char[requiredSize];
		copyString(temp, data);
		copyString(temp, s2.data, lengthOfCallingObject);
		String s;
		s.data = temp;
		temp = nullptr;
		s.size = requiredSize;
		return s;
	}
	exit(0);
}
void String::concatEqual(const String& s2)
{
	if (!(isEmpty()) && !(s2.isEmpty()))
	{
		int lengthOfCallingObject = getLength();
		int lengthOfComingObject = s2.getLength();
		if ((lengthOfCallingObject + lengthOfComingObject) > (size - 1))
		{
			int newSize = (lengthOfCallingObject + lengthOfComingObject + 1);
			reSize(newSize);
			copyString(data, s2.data, lengthOfCallingObject);
			/*char* temp = new char[newSize];
			copyString(temp, data);
			copyString(temp, s2.data, lengthOfCallingObject);
			this->~String();
			data = temp;
			temp = nullptr;
			size = newSize;*/
		}
		else
		{
			copyString(data, s2.data, lengthOfCallingObject);
		}
	}
}
void String::setNumber(const long long int num)
{
	this->~String();
	int i = 0;
	long long int num2 = num;
	bool isMinusStatus = false;
	int numberLength = getNumberLength(num);
	if (num == 0)
	{
		size = 2;
		data = new char[size];
		data[0] = '0';
	}
	else if (num > 0)
	{
		size = numberLength;
		size = size + 1;
		data = new char[size];
	}
	else
	{
		isMinusStatus = true;
		size = numberLength;
		size = size + 2;
		data = new char[size];
		num2 = num2 * -1;
	}
	while (i < numberLength)
	{
		char a = num2 % 10 + '0';
		data[i] = a;
		num2 = num2 / 10;
		i++;
	}
	if (isMinusStatus)
	{
		data[i] = '-';
	}
	data[size - 1] = '\0';
	reverse();
}
