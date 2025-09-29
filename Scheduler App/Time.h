#ifndef TIME_H
#define TIME_H
class Time
{
	int hour;
	int minute;
	int second;
	void resetTime(int h = 12, int m = 0, int s = 0);
public:
	Time();
	Time(int h, int m, int s);
	void setTime(int h, int m, int s);
	void setHours(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour();
	int getMinute();
	int getSecond();
	void incHour(int increment = 1);
	void incMin(int increment = 1);
	void incSec(int increment = 1);
	void printTwentyFourHoursFormat();
	void printTwelveHoursFormat();
};
#endif // !TIME_H
