#include<iostream>
#include"Integers.h"
using namespace std;
int main()
{
	Array a = {5,1,12,23,34,55};
	cout << a.binarySearch(34);
	return 0;
}