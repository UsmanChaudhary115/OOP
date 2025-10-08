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
	Array(const Array&); //copy Constructor
	~Array();
	bool isEmpty() const;
	int getElement(int)const;
	void display()const;
	int& getset(int);
	int getCapacity()const;
	void reSize(int);
	void sort(); // additional function
};
#endif