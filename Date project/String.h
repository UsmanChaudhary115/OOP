#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class Date;
class String
{
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& str);
	friend String operator+(const char*, String&);
	char* data;
	int size;
	int getStringLength(const char* const array) const;
	void copyString(char* const destinationArray, const char const* sourceArray, int counter = 0) const;
	void shiftBits(const int destinationArrayLength, const int startingPoint, const int sourceArrayLength);
	void populatingArray(const char* const sourceKey, const int startingPoint, const int sourceKeyLength);
	int getNumberLength(long long int);
	bool isDelimiter(int, char*, int);
public:
	String();
	String(const char);
	String(const char*);
	String(const String&);
	String(const Date&);
	~String();
	String& operator=(const String&);
	operator int();
	void input();
	char& operator[](const int);
	const char& operator[](const int) const;
	bool isEmpty() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String&, const int) const;
	void insert(const int, const String&);
	void remove(const int, const int = 1);
	int replace(const String&, const String&);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	void shrink();
	int compare(const String&) const;
	String left(const int);
	String right(const int);
	long long int convertToInteger()const;
	float convertToFloat()const;
	String operator+(const String&) const;
	void operator+=(const String&);
	void setNumber(const long long int);
	void reverseWords();
	void changeToNewCharSet(String cs);
	String tokenzie(String);
};
#endif // !STRING_H
