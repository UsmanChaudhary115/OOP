#include"Account.h"
#include<iostream>
using namespace std;
Account::Account(double b)
{
	if (b > 0)
	{
		balance = b;
	}
	else
	{
		balance = 0;
		cout << "Initial Balance was Invalid!" << '\n';
	}
}
void Account::credit(double b)
{
	if (b > 0)
	{
		balance = balance + b;
	}
}
void Account::debit(double b)
{
	if ((balance - b) >= 0)
	{
		balance = balance - b;
	}
}
double Account::getBalance()
{
	return balance;
}