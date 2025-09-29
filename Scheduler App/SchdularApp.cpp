#include"SchdularApp.h"
#include"Schedular.h"
#include<iostream>
using namespace std;
void SchedularApp::showMainManu()
{
	cout << "Press \'1\' to add task" << '\n';
	cout << "Press \'2\' to display task(s)" << '\n';
	cout << "Press \'3\' to display today task(s)" << '\n';
	cout << "Press \'4\' to Exit" << '\n';
}
void SchedularApp::startApp()
{
	Schedular s;
	int input = 1;
	while(input != 4)
	{
		do
		{
			SchedularApp::showMainManu();
			cin >> input;
		} while (input <= 0 || input > 4);
		if (input == 1)
		{
			int a, b, c;
			cout << "Enter Date (Day (space) Month (space) Year): ";
			cin >> a >> b >> c;	// a is recieving Day, b is recieving Month, c is recieving Year
			Date date;
			date.setDate(a, b, c);
			cout << "Enter Time (Hours (space) Minutes (space) Seconds): ";
			cin >> a >> b >> c;	// Again a is recieving Hours, b is recieving Minutes, c is recieving Seconds for reuseability
			Time time;
			time.setTime(a, b, c);
			cout << "Enter Message: ";
			cin.ignore();
			String str;
			str.input();
			s.addTask(Task(date, time, str));	//Recall the concept of "NameLess Objects" 
		}
		else if (input == 2)
		{
			int a, b, c;
			cout << "Enter Date (Day (space) Month (space) Year): ";
			cin >> a >> b >> c;	// a is recieving Day, b is recieving Month, c is recieving Year
			s.displayTask(Date(a, b, c));
		}
		else if (input == 3)
		{
			s.displayTodayTask();
		}
		else
		{ 
			cout << "Exiting!";
		}
	}
}