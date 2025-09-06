#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"Account.h"
class SavingsAccount :public Account
{
	double interestRate;
public:
	SavingsAccount(double, double = 0);
	double calculateInterest();
};
#endif // !SAVINGSACCOUNT_H
