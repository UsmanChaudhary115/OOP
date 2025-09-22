#ifndef STRING_H
#define STRING_H
class String
{
	char* data;
	int size;
	int getStringLength(const char* const array) const;
	void copyString(char* const destinationArray, const char const* sourceArray, int counter = 0) const;
	void shiftBits(const int destinationArrayLength, const int startingPoint, const int sourceArrayLength);
	void populatingArray(const char* const sourceKey, const int startingPoint, const int sourceKeyLength);
	int getNumberLength(long long int);
public:
	String();
	String(const char);
	String(const char*);
	String(const String&);
	~String();
	void input();
	char& at(const int);
	const char& at(const int) const;
	bool isEmpty() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String&, const int) const;
	void insert(const int, const String&);
	void remove(const int, const int);
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
	String concatinate(const String&) const;
	void concatEqual(const String&);
	void setNumber(const long long int);
};

#endif // !STRING_H
