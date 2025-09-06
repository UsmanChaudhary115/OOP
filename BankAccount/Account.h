#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
	double balance;
public:
	Account(double=0);
	void credit(double);
	void debit(double);
	double getBalance();
};
#endif // !ACCOUNT_H
