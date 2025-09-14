#include"String.h"
#include"Date.h"
String operator+(const char* ref, String& x)
{
	String s{ ref };
	return (s + x);
}
istream& operator>>(istream& is, String& str)
{
	str.~String();
	str.data = new char[1];
	str.size = 1;
	str.data[0] = '\0';
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		str.reSize(str.getLength() + 1);
		str.data[str.size - 2] = ch;
		str.data[str.size - 1] = '\0';
	}
	return is;
}
ostream& operator<<(ostream& os, const String& str)
{
	if (str.data != nullptr && str.size != 0)
		os << str.data;
	return os;
}
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
int String::getStringLength(const char* const array)const
{
	int length = 0;
	while (array[length] != '\0')
	{
		length = length + 1;
	}
	return length;
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
		if (l == 0)
		{
			return;
		}
		size = l + 1;
		data = new char[size];
		copyString(data, str);
	}
}
String& String::operator=(const String& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~String();
	size = ref.size;
	data = new char[size];
	copyString(data, ref.data);
	return *this;
}
String::String(const String& s) :String()
{
	if ((s.isEmpty()))
	{
		return;
	} 
	this->data = s.data;
}
String::String(const Date& date)
{
	*this = date.getDateInFormat1();
}
String::~String()
{
	if (isEmpty())
	{
		size = 0;
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;
}
bool String::isEmpty() const
{
	return (data == nullptr) ? true : false;
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
char& String::operator[](int index)
{
	if (index <= (size - 2) && index >= 0 && !(isEmpty()))
	{
		char& c = data[index];
		return c;
	}
	exit(0);
}
const char& String::operator[](const int index) const
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
	exit(0);
}
int String::getSize() const
{
	if (!(isEmpty()))
	{
		return size;
	}
	return 0;
}
void String::display()const
{
	if (!(isEmpty()))
	{
		cout << data;
	}
}
int String::find(const String& subStr, const int start = 0) const
{
	int startingBit = -1;
	if (!(isEmpty()) && !(subStr.isEmpty()))
	{
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
	}
	return startingBit;
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
		size = getLength() + 1;
	}
}
void String::remove(int index, int count)
{
	if (!(isEmpty()) && count > 0 && index >= 0 && count <= getLength())
	{
		int destinationArrayLength = getLength();
		if ((index + count) <= destinationArrayLength)
		{
			for (int i = index; i <= destinationArrayLength; i = i + 1)
			{
				data[i] = data[i + count];
			}
		}
	}
}
int String::replace(const String& old, const String& newSubStr)
{
	int count = 0;
	if (!(isEmpty()) && !(old.isEmpty()) && !(newSubStr.isEmpty()))
	{
		int lengthOfOldString = old.getLength(), lengthOfNewString = newSubStr.getLength();
		int diff = lengthOfNewString - lengthOfOldString;
		for (int j = 0; j <= getLength(); j = j + 1)
		{
			int i = find(old, j);
			if (i >= 0)
			{
				j = i + lengthOfNewString - 1;
				count = count + 1;
				remove(i, lengthOfOldString);
				reSize(getSize() + diff + 1);
				insert(i, newSubStr);
			}
		}
	}
	return count;
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
			return;
		}
	}
	size = capacity + 1;
	data = new char[size];
	data[0] = '\0';
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
	else
	{
		return 2;
	}
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
	else
	{
		String b;
		return b;
	}
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
	else
	{
		String b;
		return b;
	}
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
				} {
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
String String::operator+(const String& s2)const
{
	String s;
	if (!(isEmpty()) && !(s2.isEmpty()))
	{
		int lengthOfCallingObject = getLength();
		int requiredSize = lengthOfCallingObject + s2.getLength() + 1;
		char* temp = new char[requiredSize];
		copyString(temp, data);
		copyString(temp, s2.data, lengthOfCallingObject);
		s.data = temp;
		temp = nullptr;
		s.size = requiredSize;
		return s;
	}
	else if (s2.isEmpty() && !(isEmpty()))
	{
		char* temp = new char[size];
		copyString(temp, data);
		s.data = temp;
		s.size = size;
		temp = nullptr;
		return s;
	}
	else if (isEmpty() && !(s2.isEmpty()))
	{
		char* temp = new char[s2.size];
		copyString(temp, s2.data);
		s.data = temp;
		s.size = size;
		temp = nullptr;
		return s;
	}
	else
	{
		return s;
	}
}
void String::operator+=(const String& s2)
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
		}
		else
		{
			copyString(data, s2.data, lengthOfCallingObject);
		}
	}
	if (isEmpty())
	{
		data = new char[s2.getLength() + 1];
		copyString(data, s2.data);
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
void String::reverseWords()
{
	if (!(isEmpty()))
	{
		int i = 0;

		while (data[i] != '\0')
		{
			bool status = false, conditionStatus = true;
			int count = 0;
			int index = 0;
			String a{ '\0' };
			while (data[i] >= 'A' && data[i] <= 'Z' || data[i] >= 'a' && data[i] <= 'z')
			{
				if (conditionStatus)
				{
					conditionStatus = false;
					index = i;
				}
				status = true;
				String tempPlace{ data[i] };
				a.insert(0, tempPlace);
				i = i + 1;
				count++;
			}
			if (status)
			{
				remove(index, (count));
				insert(index, a);
			}
			i = i + 1;
		}
	}
}
void String::changeToNewCharSet(String cs)
{
	if (!isEmpty() && !cs.isEmpty())
	{
		String abc{ "abcdefghijklmnopqrstuvwxyz" };
		for (int i = 0; i < (size - 1); i++)
		{
			int index = -1;
			bool status = false;
			for (int j = 0; j < 26 && !status; j++)
			{
				if (data[i] == abc.data[j])
				{
					index = j;
					status = true;
				}
			}
			if (status)
			{
				data[i] = cs.data[index];
			}
		}
	}
}
bool String::isDelimiter(int delimiterStringLength, char* temp, int place)
{
	bool delimiterStatus = false;
	for (int j = 0; j < delimiterStringLength; j = j + 1)
	{
		if (data[place] == temp[j])
		{
			delimiterStatus = true;
		}
	}
	return delimiterStatus;
}
String String::tokenzie(String s)
{
	if (getLength() == 1 && isDelimiter(1, data, 0))
	{
		remove(0);
		String a;
		return a;
	}
	else
	{
		int delimiterStringLength = s.getLength();
		String a{ '\0' };
		int index = 0;
		while (isDelimiter(delimiterStringLength, s.data, index))
		{
			index = index + 1;
		}
		bool delimiterStatus = false;
		while (data[index] != '\0' && !delimiterStatus)
		{
			if (isDelimiter(delimiterStringLength, s.data, index))
			{
				delimiterStatus = true;
			}
			else
			{
				a.insert(0, data[index]);
				index = index + 1;
			}
		}
		remove(0, index);
		a.reverse();
		return a;
	}
}