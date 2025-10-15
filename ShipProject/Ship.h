#ifndef SHIP_H
#define	SHIP_H
#include"String.h"
class Ship
{
	String nameOfShip;
	String BuiltYear;
public:
	Ship();
	Ship(const String&, const String&);
	virtual void print();
	String getNameOfShip();
	String getBuiltYear();
};
#endif // !SHIP_H
