#ifndef Integer_H
#define Integer_H
class Array
{
	int* data;
	int capacity;
	//bool isValidIndex(int);
	void copyIntegerArray(int* const, const int* const, int);
public:
	Array();
	/*Array(int);*/
	Array(int, ...);
	Array(const Array&);
	~Array();
	void display();
	int& operator[](int);
	const int& operator[](int) const;
	int getCapacity();
	void reSize(int);
	void sort(); // additional function
	int binarySearch(int);
};
#endif