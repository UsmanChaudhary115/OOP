#include"SavingsAccont.h"
#include"CheckingAccount.h"
#include<iostream>
using namespace std;
int main() {
	SavingsAccount s(1000, 2);
	CheckingAccount c(1000, 1);
	s.debit(100);
	c.debit(100);
	s.credit(100);
	c.credit(100);
	cout << "Savings Account Interest: " << s.calculateInterest();
	cout << "\nSavings Account Balance: " << s.getBalance();
	cout << "\nChecking Account Balance: " << c.getBalance();
	
	return 0;
}