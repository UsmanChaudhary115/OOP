#include"Ship.h"
Ship::Ship(): nameOfShip(),BuiltYear()
{}
Ship::Ship(const String& ref1,const String& ref2): nameOfShip(ref1),BuiltYear(ref2)
{}
void Ship::print()
{
	cout << "Ship`s Name: " << nameOfShip << '\n';
	cout << "Built Year: " << BuiltYear << '\n';
}
String Ship::getNameOfShip()
{
	return nameOfShip;
}
String Ship::getBuiltYear()
{
	return BuiltYear;
}