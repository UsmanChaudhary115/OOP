#ifndef DATE_H
#define DATE_H
#include"String.h"
class Date
{
	static const int daysInMonth[13];
	int day;
	int month;
	int year;
	bool isLeapYear()const;
	static String monthNames[12];
	int getValidDays();
	bool isValidDate(int d, int m, int y)const;
	void increment(int& i);
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void printFormat1()const;
	void printFormat2()const;
	void printFormat3()const;
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	bool areSameDates(Date);
	String getDateInFormat1()const;
	String getDateInFormat2()const;
	String getDateInFormat3()const;
	String toString(long long int)const;
	operator String();
};
#endif 
