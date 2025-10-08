#ifndef	SET_H
#define SET_H 
#include"Integers.h"
class Set
{
	Array data;
	int noOfElements;
	int getCommonElementsCount(const Set&)const;
	bool areSetsEqual(Set&)const;
public:
	Set(int cap = 0) :data(cap)
	{
		noOfElements = 0;
	}
	void insert(int element);
	void remove(int element);
	void print()const;
	int getCardinality()const;
	bool isMember(int val)const;
	int isSubSet(Set s2)const;
	void reSize(int newCapacity);
	Set calcUnion(const Set& s2)const;
	Set calcIntersection(const Set& s2)const;
	Set calcDifference(const Set& s2)const;
	Set calcSymmetricDifference(const Set& s2)const;
	void displayPowerSet()const;
};
#endif