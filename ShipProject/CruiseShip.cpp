#include"CruiseShip.h"
CruiseShip::CruiseShip(const String& ref1, const String& ref2, int n) :Ship(ref1, ref2)
{
	maxNumberOfPassengers = n;
}
void CruiseShip::print()
{
	cout << "Ship`s Name: " << getNameOfShip() << '\n';
	cout << "Built Year: " << getBuiltYear() << '\n';
	cout << "Maximum Number of Passengers: " << maxNumberOfPassengers << '\n';
}