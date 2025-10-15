#ifndef BATTLESHIP_H
#define	BATTLESHIP_H
#include"Ship.h"
class BattleShip :public Ship
{
	int totalMissiles;
public:
	BattleShip(const String&, const String&,int = 0);
	void print();
};
#endif // !BATTLESHIP_H
