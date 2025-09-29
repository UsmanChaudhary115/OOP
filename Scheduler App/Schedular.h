#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include"Task.h"
class Schedular
{
	Task* taskList;
	int noOfTasks;
	int capacity;
	bool areSameDate(Date dateToBeCompared, Date sourceDate)const;
public:
	Schedular();
	~Schedular();
	//void showAll();
	void addTask(const Task&);
	void displayTask(const Date& d = Date(1, 1, 1500))const;
	void displayTodayTask()const;
	void reSize(int);
};
#endif // !SCHEDULER_H
