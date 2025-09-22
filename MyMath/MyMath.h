#ifndef MATH_H
#define MATH_H
#include"String.h"
class MyMath
{
public:
	static int calDivisor(int);
	static int calNumberLength(int);
	static float calPower(int, int);
	static int calGCD(int, int);
	static String toString(long long int);
	static long long int toInteger(String);
};
#endif // !MATH_H
