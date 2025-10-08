#include<iostream>
#include"Set.h"
#include"Integers.h"
using namespace std;
int Set::getCommonElementsCount(const Set& s2)const		//Private function,
{														//it gives count of common elements in calling Set Object
	int count = 0;										// and in coming Set object
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		for (int j = 0; j < s2.noOfElements; j = j + 1)
		{
			if (data.getElement(i) == s2.data.getElement(j))
			{
				count = count + 1;
			}
		}
	}
	return count;
}
bool Set::areSetsEqual(Set &s2)const		//Private function,
{											//it gives status of equality of the calling Set object
	bool status = false;					// and the coming Set object
	Set A = calcUnion(s2);
	Set B = calcIntersection(s2);
	if (A.getCardinality() == B.getCardinality())
	{
		status = true;
	}
	return status;
}
void Set::insert(int element)
{
	if (!(isMember(element)) && !data.isEmpty())
	{
		if (noOfElements < data.getCapacity())
		{
			data.getset(noOfElements) = element;
			noOfElements++;
		}
		else
		{
			data.reSize(noOfElements * 2);				
			data.getset(noOfElements) = element;
			noOfElements++;
		}
	}
	if (data.isEmpty())
	{
		data.reSize(1);								//If set is Empty, it'll be ReSized to one Size
		data.getset(noOfElements) = element;
		noOfElements++;
	}
}
void Set::print()const
{
	cout << '{';
	for (int i = 0; i < noOfElements; i = i + 1)
	{
		cout << data.getElement(i);
		if (i < (noOfElements - 1))
		{
			cout << ", ";
		}
	}
	cout << '}';
}
bool Set::isMember(int val)const
{
	bool status = false;
	if(!data.isEmpty())
	{
		for (int i = 0; i < noOfElements; i++)
		{
			if (val == data.getElement(i))
			{
				status = true;
			}
		}
	}
	return status;
}
void Set::reSize(int newCapacity)
{
	data.reSize(newCapacity);
}
void Set::remove(int element)
{
	if (!data.isEmpty() && isMember(element))
	{
		for (int i = 0, j = 0; i < noOfElements; i++)
		{
			if(element != data.getElement(i))
			{
				data.getset(j) = data.getElement(i);
				j++;
			}
		}
		noOfElements--;
	}
}
int Set::getCardinality()const
{
	return noOfElements;	//returning No.Of Elements present in the Set.
}
Set Set::calcUnion(const Set& s2)const
{
	if(!data.isEmpty() && !s2.data.isEmpty())
	{
		int count = getCommonElementsCount(s2);
		Set unionSet{ (noOfElements + s2.noOfElements - count) };
		
		for (int i = 0; i < noOfElements; i = i + 1)
		{															// proper calculation for calculating Union
			unionSet.insert(data.getElement(i));					// is being done here
		}
		for (int k = 0; k < s2.noOfElements; k = k + 1)
		{
			bool status = true;
			for (int j = 0; j < noOfElements; j = j + 1)
			{
				if (s2.data.getElement(k) == data.getElement(j))
				{
					status = false;
				}
			}
			if (status)
			{
				unionSet.insert(s2.data.getElement(k));
			}
		}
		return unionSet;
	}
	else if (data.isEmpty() && s2.data.isEmpty())
	{
		// "BothEmpty", Union will be an empty Set.
		Set unionSet;
		return unionSet;
	}
	else if(data.isEmpty())
	{ 
		// "Calling object is Empty", Union will comprises only on the elements of 
		// coming Set object
		Set unionSet{ s2.noOfElements };
		for (int i = 0; i < s2.noOfElements; i = i + 1)
		{
			unionSet.insert(s2.data.getElement(i));
		}
		return unionSet;
	}
	else
	{
		// "Coming Object is Empty", Union will comprises only on the elements of 
		// calling Set object
		Set unionSet{ noOfElements };						
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			unionSet.insert(data.getElement(i));
		}
		return unionSet;
	}
}
Set Set::calcIntersection(const Set& s2)const
{
	if(!data.isEmpty() && !s2.data.isEmpty())
	{
		int count = getCommonElementsCount(s2);
		Set intersectionSet{ count };
		for (int i = 0, k = 0; i < noOfElements; i = i + 1)
		{														// proper calculation for calculating Intersection
			for (int j = 0; j < s2.noOfElements; j = j + 1)		// is being done here
			{
				if (data.getElement(i) == s2.data.getElement(j))
				{
					intersectionSet.insert(data.getElement(i));
					k = k + 1;
				}
			}
		}
		return intersectionSet;
	}
	else
	{
		Set intersectionSet;		// If any set is empty, intersection will be an empty Set.
		return intersectionSet;
	}
}
Set Set::calcDifference(const Set& s2)const
{
	if(!data.isEmpty() && !s2.data.isEmpty())
	{
		int count = getCommonElementsCount(s2);
		Set difference{ (noOfElements - count) };
		for (int i = 0; i < noOfElements; i = i + 1)	// proper calculation for calculating difference
		{												// is being done here
			bool status = false;
			for (int j = 0; j < s2.noOfElements; j = j + 1)
			{
				if (data.getElement(i) == s2.data.getElement(j))
				{
					status = true;
				}
			}
			if (!status)
			{
				difference.insert(data.getElement(i));
			}
		}
		return difference;
	}
	else if (s2.data.isEmpty())	// if coming set object is empty then returning object will
	{                           // comprises on all the elements of calling object
		Set difference{noOfElements};
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			difference.insert(data.getElement(i));
		}
		return difference;
	}
	else					// if calling set object is empty then returning object
	{						// will be empty
		Set difference;
		return difference;
	}
}
Set Set::calcSymmetricDifference(const Set& s2)const
{
	Set A = calcDifference(s2);						// This Statement is doing "A - B"
	Set B = s2.calcDifference(*this);				// This Statement is doing "B - A"
	Set symmetricDifference = A.calcUnion(B);		// This Statement is doing "(A - B) U (B - A)"
	return symmetricDifference;
}
int Set::isSubSet(Set s2)const
{
	int response=0;
	
	if ((data.isEmpty() && s2.data.isEmpty()) || areSetsEqual(s2))
	{
		response = 2;		// if both sets are empty Or Same then they are improper Sub Sets of each other.
	}
	else if (s2.data.isEmpty())
	{
		response = -1;		// if coming Set object is empty, then Coming object is sub set of Calling object.
	}
	else if (data.isEmpty())
	{
		response = 1;		// if Calling Set object is empty, then Calling object is sub set of Coming object.	
	}
	else
	{
		bool status = false;
		int count = 0;
		for (int i = 0; i < s2.noOfElements && !status; i++)
		{													// Checking if the Coming Set object is sub set of 
			for (int j = 0; j < noOfElements; j++)			// Calling Set Object
			{											
				if (s2.data.getElement(i) == data.getElement(j))
				{
					count++;
				}
			}
			if (count == s2.noOfElements)
			{
				response = -1;
				status = true;
			}
		}
		if(!status)
		{
			count = 0;
			for (int i = 0; i < noOfElements && !status; i++)
			{												// Checking if the Calling Set object is sub set of 
				for (int j = 0; j < s2.noOfElements; j++)	// Coming Set Object, It'll work only if above 
				{											// condition does`nt come up true.
					if (data.getElement(i) == s2.data.getElement(j))
					{
						count++;
					}
				}
				if (count == noOfElements)
				{
					response = 1;
					status = true;
				}
			}
		}
	} 
	return response;
}
void Set::displayPowerSet()const
{
	//int countOfLoopIteratons = (MyMath::calPower(2, noOfElements)) - 1;
	cout << '{';
	cout << "{}";
	int a = 0;
	for (int i = 0; i < getCardinality(); i++)
	{
		cout << ", ";
		Set s;
		s.insert(data.getElement(i));
		s.print();
	}
	/*while (countOfLoopIteratons)
	{
		while()
		countOfLoopIteratons--;
	}*/
	cout << '}';
}