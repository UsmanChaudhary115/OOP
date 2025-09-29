#include<iostream>
#include<iomanip>
#include"Time.h"
using namespace std;
void Time::resetTime(int h, int m, int s)
{
	if (h >= 0 && h <= 24)
	{
		hour = h;
	}
	else
	{
		hour = 12;
	}
	if (m >= 0 && m <= 59)
	{
		minute = m;
	}
	else
	{
		minute = 0;
	}
	if (s >= 0 && s <= 59)
	{
		second = s;
	}
	else
	{
		second = 0;
	}
}
Time::Time()
{
	resetTime();
}
Time::Time(int h, int m, int s)
{
	resetTime(h, m, s);
}
void Time::setTime(int h, int m, int s)
{
	setHours(h);
	setMinute(m);
	setSecond(s);
}
void Time::setHours(int h)
{
	if (h >= 0 && h <= 24)
	{
		hour = h;
	}
}
void Time::setMinute(int m)
{
	if (m >= 0 && m <= 59)
	{
		minute = m;
	}
}
void Time::setSecond(int s)
{
	if (s >= 0 && s <= 59)
	{
		second = s;
	}
}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}
int Time::getSecond()
{
	return second;
}
void Time::incHour(int increment)
{
	hour = hour + increment;
	hour = hour % 24;
}
void Time::incMin(int increment)
{
	minute = minute + increment;
	increment = minute / 60;
	minute = minute % 60;
	if (increment)
	{
		incHour(increment);
	}
}
void Time::incSec(int increment)
{
	second = second + increment;
	increment = second / 60;
	second = second % 60;
	if (increment)
	{
		incMin(increment);
	}
}
void Time::printTwentyFourHoursFormat()
{
	cout << setw(2) << setfill('0') << hour << ':' << setw(2) << minute << ':' << setw(2) << second;
}
void Time::printTwelveHoursFormat()
{
	int tempHour = hour, tempMinute = minute, tempSecond = second;
	if (tempHour == 24)
	{
		tempHour = 0;
	}
	if (tempHour > 11)
	{
		if (tempHour > 12)
		{
			tempHour = tempHour - 12;
		}
		cout << setw(2) << setfill('0') << tempHour << ':' << setw(2) << tempMinute << ':' << setw(2) << tempSecond << " PM";
	}
	else
	{
		if (tempHour == 0)
		{
			tempHour = 12;
		}
		cout << setw(2) << setfill('0') << tempHour << ':' << setw(2) << tempMinute << ':' << setw(2) << tempSecond << " AM";
	}
}