#include"Set.h"
#include"Integers.h"
#include<iostream>
using namespace std;
int main()
{
	Set A;
	A.insert(1);
	A.insert(2);
	A.insert(3);
	A.displayPowerSet();
	return 0;
}