#ifndef CHECKINGACCOUNT_H
#define	CHECKINGACCOUNT_H
#include"Account.h"
class CheckingAccount :public Account
{
	double feeAmount;
public:
	CheckingAccount(double,double);
	void credit(double);
	void debit(double);
};
#endif // !CHECKINGACCOUNT_H
