#include"BattleShip.h"
BattleShip::BattleShip(const String& ref1, const String& ref2,int n):Ship(ref1,ref2)
{
	totalMissiles = n;
}
void BattleShip::print()
{
	cout << "Ship`s Name: " << getNameOfShip() << '\n';
	cout << "Missiles` Capacity: " << totalMissiles << '\n';
}