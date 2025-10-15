#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include"Ship.h"
class CargoShip:public Ship
{
	int cargoCapacity;
public:
	CargoShip(const String&, const String&, int = 0);
	void print();
};
#endif // !CARGOSHIP_H
