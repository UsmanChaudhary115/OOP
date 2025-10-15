#ifndef CRUISESHIP_H
#define	CRUISESHIP_H
#include"Ship.h"
class CruiseShip:public Ship
{
	int maxNumberOfPassengers;
public:
	CruiseShip(const String&, const String&, int = 0);
	void print();
};
#endif // !CRUISESHIP_H
