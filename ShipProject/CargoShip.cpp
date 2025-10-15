#include"CargoShip.h"
CargoShip::CargoShip(const String& ref1, const String& ref2, int c) : Ship(ref1, ref2)
{
	cargoCapacity = c;
}
void CargoShip::print()
{
	cout << "Ship`s Name: " << getNameOfShip() << '\n';
	cout << "Ship`s Cargo Capacity: " << cargoCapacity << '\n';
}