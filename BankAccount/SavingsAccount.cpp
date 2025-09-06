#include"SavingsAccont.h"
#include<iostream>
using namespace std;
SavingsAccount::SavingsAccount(double b, double rate):Account(b)
{
	if (rate >= 0)
	{
		interestRate = rate;
	}
	else
	{
		interestRate = 0;
		cout << "Invalid Interest Rate" << '\n';
	}
}
double SavingsAccount::calculateInterest()
{
	return (interestRate * getBalance())/ 100.0;
}