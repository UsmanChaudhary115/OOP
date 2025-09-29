#define _CRT_SECURE_NO_WARNINGS
#include"Schedular.h"
#include<iostream>
#include<ctime>
using namespace std;
//void Schedular::showAll()
//{
//	for (int i = 0; i < noOfTasks; i++)
//	{	
//		{
//			Date date = taskList[i].getDate();
//			Time time = taskList[i].getTime();
//			String str;
//			str.concatEqual(taskList[i].getMessage());
//			cout << "Date: ";
//			date.printFormat3();
//			cout << '\n';
//			cout << "Time: ";
//			time.printTwelveHoursFormat();
//			cout << '\n';
//			cout << "Task Message: ";
//			str.display();
//			cout << '\n';
//		}
//	}
//}
bool Schedular::areSameDate(Date dateToBeCompared, Date sourceDate)const
{
	bool status = false;
	if (dateToBeCompared.getDay() == sourceDate.getDay() && dateToBeCompared.getMonth() == sourceDate.getMonth() && dateToBeCompared.getYear() == sourceDate.getYear())
	{
		status = true;
	}
	return status;
}
Schedular::Schedular() 
{
	capacity = 0;
	noOfTasks = 0;
	taskList = nullptr;
}
void Schedular::addTask(const Task& t)
{
	if (/*taskList == nullptr ||*/ noOfTasks == capacity)
	{
		if (taskList == nullptr)
		{
			reSize(1);
		}
		else
		{
			int size = capacity * 2;
			reSize(size);
		}
	}
	taskList[noOfTasks].setTask(t.getDate(), t.getTime(), t.getMessage());
	noOfTasks++;
}
void Schedular::displayTask(const Date& d)const
{
	for (int i = 0; i < noOfTasks; i++)
	{
		if (taskList[i].getDate().areSameDates(d))
		{
			Date date = taskList[i].getDate();
			Time time = taskList[i].getTime();
			String str;
			str.concatEqual(taskList[i].getMessage());
			cout << "Date: ";
			date.printFormat3();
			cout << '\n';
			cout << "Time: ";
			time.printTwelveHoursFormat();
			cout << '\n';
			cout << "Task Message: ";
			str.display();
			cout << '\n';
		}
	}
}
void Schedular::displayTodayTask()const
{
	time_t t = time(NULL);
	tm curTime = *localtime(&t);
	displayTask(Date(curTime.tm_mday, (curTime.tm_mon + 1), (curTime.tm_year + 1900)));
}
Schedular::~Schedular()
{
	if(taskList != nullptr)
	{
		delete[] taskList;
		taskList = nullptr;
		capacity = 0;
		noOfTasks = 0;
	}
}
void Schedular::reSize(int size)
{
	if (size <= 0)
	{
		this->~Schedular();
	}
	else
	{
		Task* ptr = new Task[size];
		int noOfTasksPresent = noOfTasks;
		if(noOfTasksPresent)
		{
			if (noOfTasksPresent < (size))
			{
				for (int i = 0; i < noOfTasksPresent; i = i + 1)
				{
					ptr[i].setTask(taskList[i].getDate(), taskList[i].getTime(), taskList[i].getMessage());
				}
			}
			else
			{
				for (int i = 0; i <= size; i = i + 1)
				{
					ptr[i].setTask(taskList[i].getDate(), taskList[i].getTime(), taskList[i].getMessage());
				}
			}
		}
		if(taskList!=nullptr)
		{
			this->~Schedular();
			noOfTasks = noOfTasksPresent;
		}
		capacity = size;
		taskList = ptr;
		ptr = nullptr;
	}
}