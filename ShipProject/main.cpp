#include"BattleShip.h"
#include"CargoShip.h"
#include"CruiseShip.h"
int main()
{
	Ship** p = new Ship * [4];
	p[0] = new Ship(String("Diago"),String("2002"));
	p[1] = new BattleShip(String("Diago"), String("2002"),100);
	p[2] = new CargoShip(String("Diago"), String("2002"),1000);
	p[3] = new CruiseShip(String("Diago"), String("2002"),500);
	p[0]->print();
	cout << '\n'; 
	p[1]->print();
	cout << '\n'; 
	p[2]->print();
	cout << '\n'; 
	p[3]->print();
	cout << '\n';
	return 0;
}