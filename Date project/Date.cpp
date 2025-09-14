#include<iomanip>
#include"Date.h"
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
String Date::monthNames[12] = { "January","Febrary","March","April","May","June","July","August","September","October","November","December" };
Date::operator String()
{
	return getDateInFormat1();
}
void Date::increment(int& i)
{
	i = i + 1;
}
String Date::toString(long long int num)const
{
	String s;
	s.setNumber(num);
	return s;
}
bool Date::isValidDate(int d, int m, int y)const
{
	bool status = true;
	int validDays = daysInMonth[m];
	if (m == 2)
	{
		if (((y % 100 == 0) && (y % 400 == 0)) || ((y % 4 == 0) && (y % 100 != 0)))
		{	//checking if it is Leap
			validDays++;
		}
	}
	if (d <= 0 || d > validDays)
	{
		status = false;
	}
	return status;
}
int Date::getValidDays()
{
	int validDays = daysInMonth[month];
	if (isLeapYear() && month == 2)
	{
		validDays++;
	}
	return validDays;
}
bool Date::isLeapYear()const
{
	bool leapYearStatus = false;
	if (((year % 100 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		leapYearStatus = true;
	}
	return leapYearStatus;
}
bool Date::Date::areSameDates(Date d)
{
	bool status = false;
	if (day == d.getDay() && month == d.getMonth() && year == d.getYear())
	{
		status = true;
	}
	return status;
}
Date::Date() :day(14), month(10), year(2019)
{ }
Date::Date(int comingDay, int comingMonth, int comingYear) :Date()
{
	setDate(comingDay, comingMonth, comingYear);
}
void Date::setDay(int comingDay)
{
	int validDays = getValidDays();
	if (comingDay > 0 && comingDay <= validDays)
	{
		day = comingDay;
	}
}
void Date::setMonth(int comingMonth)
{
	if (comingMonth >= 1 && comingMonth <= 12)
	{
		month = comingMonth;
	}
}
void Date::setYear(int comingYear)
{
	if (comingYear >= 1500 && comingYear <= 3000)
	{
		year = comingYear;
	}
}
void Date::setDate(int comingDay, int comingMonth, int comingYear)
{
	setYear(comingYear);
	setMonth(comingMonth);
	setDay(comingDay);
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
void Date::incDay(int incrementInDay)
{
	day = day + incrementInDay;
	int validDays = getValidDays();
	while (day > validDays)
	{
		day = day - validDays;
		increment(month);
		if (month > 12)
		{
			incYear();
			month = month - 12;
		}
		validDays = getValidDays();
	}
}
void Date::incMonth(int incrementInMonth)
{
	month = month + incrementInMonth;
	if (month > 12)
	{
		int inc = month / 12;
		month = month % 12;
		incYear(inc);
	}
	int validDays = getValidDays();
	if (day > validDays)
	{
		day = day % validDays;
		increment(month);
	}
}
void Date::incYear(int incrementInYear)
{
	if ((year + incrementInYear) >= 1500 && (year + incrementInYear) <= 3000)
	{
		year = year + incrementInYear;
	}
}
void Date::printFormat1()const
{
	/*if (month < 10)
	{
		cout << '0';
	}
	cout << month << '/';		WithOut IOMANIP
	if (day < 10)
	{
		cout << '0';
	}
	cout << day << '/' << year;*/


	cout.fill('0');
	cout << setw(2) << right << month << '/' << setw(2) << day << '/' << year; //using IOMANIP
}
void Date::printFormat2()const
{
	/*if (day < 10)
	{
		cout << '0';	withOutIOMANIP
	}
	cout << day << ", " << year;*/

	//monthNames[month - 1].display();
	cout << monthNames[month - 1];
	cout << ' ';
	cout.fill('0');
	cout << setw(2) << right << day << ", " << year;
}
void Date::printFormat3()const
{
	/*if (day < 10)
	{
		cout << '0';	withOutIOMANIP
	}*/


	cout.fill('0');
	cout << setw(2) << right << day << '-';
	for (int i = 0; i < 3; i = i + 1)
	{
		cout << monthNames[month - 1][i];
	}
	cout << '-' << year;
}
String Date::getDateInFormat1()const
{
	/*String date;
	String slash = '/';
	String d;
	date.setNumber(month);
	if (month < 10)
	{
		String zero = "0";
		date.insert(0, zero);
	}
	date.insert(date.getLength(), slash);
	d.setNumber(day);
	if (day < 10)
	{
		String zero = "0";
		d.insert(0, zero);
	}
	date.insert(date.getLength(), d);
	date.insert(date.getLength(), slash);
	d.setNumber(year);
	date.insert(date.getLength(), d);
	return date;*/


	String date;
	date.reSize(10);
	if (month < 10)
	{
		date += ("0");
	}
	date += (toString(month));
	date += ("/");
	if (day < 10)
	{
		date += ("0");
	}
	date += (toString(day));
	date += ("/");
	date += (toString(year));
	return date;
}
String Date::getDateInFormat2()const
{
	/*String date = monthNames[month - 1];
	String space = ' ';
	String comma = ',';
	date.insert(date.getLength(), space);
	String d;
	d.setNumber(day);
	if (day < 10)
	{
		String zero = "0";
		d.insert(0, zero);
	}
	date.insert(date.getLength(), d);
	date.insert(date.getLength(), comma);
	date.insert(date.getLength(), space);
	d.setNumber(year);
	date.insert(date.getLength(), d);
	return date;*/


	String date = monthNames[month - 1];
	date += (" ");
	if (day < 10)
	{
		date += ("0");
	}
	date += (toString(day));
	date += (", ");
	date += (toString(year));
	return date;
}
String Date::getDateInFormat3()const
{
	/*String hjyphen = '-';
	String date;
	date.setNumber(day);
	if (day < 10)
	{
		String zero = "0";
		date.insert(0, zero);
	}
	date.insert(date.getLength(), hjyphen);
	for (int i = 0; i < 3; i = i + 1)
	{
		String m = monthNames[month - 1].at(i);
		date.insert(date.getLength(), m);
	}
	date.insert(date.getLength(), hjyphen);
	String y;
	y.setNumber(year);
	date.insert(date.getLength(), y);
	return date;*/


	String date;
	if (day < 10)
	{
		date += ("0");
	}
	date += (toString(day));
	date += ("-");
	for (int i = 0; i < 3; i = i + 1)
	{
		date += (monthNames[month - 1][i]);
	}
	date += ("-");
	date += (toString(year));
	return date;
}