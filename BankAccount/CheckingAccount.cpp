#include"CheckingAccount.h"
#include<iostream>
using namespace std;
CheckingAccount::CheckingAccount(double b, double f):Account(b)
{
	if (f > 0)
	{
		feeAmount = f;
	}
	else
	{
		feeAmount = 0;
		cout << "Invalid Interest Rate" << '\n';
	}
}
void CheckingAccount::credit(double b)
{
	Account::credit(b - feeAmount);
}
void CheckingAccount::debit(double b)
{
	Account::debit(b + feeAmount);
}