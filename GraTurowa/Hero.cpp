#include "Hero.h"

using namespace std;
using namespace sf;

void Pokaz(Hero *wsk)
{
	wsk->showHeroStats();
}

Hero::Hero(){}

/*Hero::Hero(string name, float attack, float attackM, int range, float healPoints, float armor, float resistance, float heal, float mobility)
{
	cout << "Nazwa: " << name << endl;
	cout << "==============="				<< endl;
	cout << "Atak Fizyczny: " << attack		<< endl;
	cout << "Atak Magiczny: " << attackM	<< endl;
	cout << "Zasieg:        " << range		<< endl;
	cout << "Zycie:         " << healPoints << endl;
	cout << "Pancerz:       " << armor		<< endl;
	cout << "Odpornosc:     " << resistance << endl;
	cout << "Leczenie:      " << heal		<< endl;
	cout << "Mobilnosc:     " << mobility << endl << endl;
}*/

Warrior::Warrior(){}

void Warrior::showHeroStats()
{
	cout << "Nazwa: " << name << endl;
	cout << "===============" << endl;
	cout << "Atak Fizyczny: " << attack << endl;
	cout << "Atak Magiczny: " << attackM << endl;
	cout << "Zasieg:        " << range << endl;
	cout << "Zycie:         " << healPoints << endl;
	cout << "Pancerz:       " << armor << endl;
	cout << "Odpornosc:     " << resistance << endl;
	cout << "Leczenie:      " << heal << endl;
	cout << "Mobilnosc:     " << mobility << endl << endl;
}