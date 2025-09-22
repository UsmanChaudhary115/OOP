#include"MyMath.h"
#include"String.h"
int MyMath::calDivisor(int num)
{
	int div = 1;
	while ((num / 10) != 0)
	{
		div = div * 10;
		num = num / 10;
	}
	return div;
}
int MyMath::calNumberLength(int num)
{
	int lengthCount = 0;
	while (num)
	{
		num = num / 10;
		lengthCount = lengthCount + 1;
	}
	return lengthCount;
}
float MyMath::calPower(int num, int pow)
{
	float powerSum = 1;
	if (pow > 0)
	{
		for (int counter = 1; counter <= pow; counter = counter + 1)
		{
			powerSum = powerSum * num;
		}
	}
	else
	{
		pow = pow * -1;
		int sum = 1;
		for (int counter = 1; counter <= pow; counter = counter + 1)
		{
			sum = sum * num;
		}
		powerSum = 1.0 / sum;
	}
	return powerSum;
}
int MyMath::calGCD(int numerator, int denomenator)
{
	if (numerator < denomenator)
	{
		numerator = numerator + denomenator;
		denomenator = numerator - denomenator;
		numerator = numerator - denomenator;
	}
	int remainder = 1;
	while (remainder)
	{
		remainder = numerator % denomenator;
		numerator = denomenator;
		denomenator = remainder;
	}
	return numerator;
}
String MyMath::toString(long long int num)
{
	String a;
	a.setNumber(num);
	return a;
}
long long int MyMath::toInteger(String str)
{
	int a;
	a = str.convertToInteger();
	return a;
}