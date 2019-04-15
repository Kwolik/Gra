#pragma once
#include <SFML/Graphics.hpp>

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <cmath>

using namespace std;

class Hero
{
private:
	string name;
	float attack;
	float attackM;
	int	range;
	float healPoints;
	float armor;
	float resistance;
	float heal;
	float mobility;

public:
	//Hero(string name, float attack, float attackM, int range, float healPoints, float armor, float resistance, float heal, float mobility);
	Hero();
	virtual void showHeroStats() = 0;
};
void Pokaz(Hero *wsk);

class Warrior : public Hero
{
private:
	string name = "Wojownik";
	float attack		= 325;
	float attackM		= 0;
	int	range			= 1;
	float healPoints	= 1200;
	float armor			= 100;
	float resistance	= 50;
	float heal			= 0;
	float mobility		= 4;
public:
	Warrior();
	virtual void showHeroStats();
};

class Archer : public Hero
{
private:
	string name = "Lucznik";
	float attack		= 225;
	float attackM		= 0;
	int	range			= 5;
	float healPoints	= 750;
	float armor			= 50;
	float resistance	= 50;
	float heal			= 0;
	float mobility		= 7;
public:
	Archer();
	virtual void showHeroStats();
};

class Crossbowman : public Hero
{
private:
	string name = "Kusznik";
	float attack		= 375;
	float attackM		= 0;
	int	range			= 6;
	float healPoints	= 800;
	float armor			= 75;
	float resistance	= 50;
	float heal			= 0;
	float mobility		= 2;
public:
	Crossbowman();
	virtual void showHeroStats();
};

class Mage : public Hero
{
private:
	string name = "Mag";
	float attack		= 0;
	float attackM		= 375;
	int	range			= 3;
	float healPoints	= 600;
	float armor			= 50;
	float resistance	= 125;
	float heal			= 100;
	float mobility		= 3;
public:
	Mage();
	virtual void showHeroStats();
};

class Paladin : public Hero
{
private:
	string name = "Paladyn";
	float attack		= 200;
	float attackM		= 150;
	int	range			= 1;
	float healPoints	= 850;
	float armor			= 100;
	float resistance	= 75;
	float heal			= 50;
	float mobility		= 4;
public:
	Paladin();
	virtual void showHeroStats();
};

class Berserker : public Hero
{
private:
	string name = "Berserker";
	float attack		= 375;
	float attackM		= 0;
	int	range			= 1;
	float healPoints	= 750;
	float armor			= 75;
	float resistance	= 25;
	float heal			= 0;
	float mobility		= 5;
public:
	Berserker();
	virtual void showHeroStats();
};

class Knight : public Hero
{
private:
	string name = "Rycerz";
	float attack		= 250;
	float attackM		= 0;
	int	range			= 1;
	float healPoints	= 1250;
	float armor			= 125;
	float resistance	= 50;
	float heal			= 0;
	float mobility		= 2;
public:
	Knight();
	virtual void showHeroStats();
};

class Necromance : public Hero
{
private:
	string name = "Nekromanta";
	float attack		= 175;
	float attackM		= 137.5;
	int	range			= 2;
	float healPoints	= 500;
	float armor			= 50;
	float resistance	= 100;
	float heal			= 100;
	float mobility		= 3;
public:
	Necromance();
	virtual void showHeroStats();
};

class Zombie : public Hero
{
private:
	string name = "Zombie";
	float attack = 250;
	float attackM = 75;
	int	range = 1;
	float healPoints = 500;
	float armor = 50;
	float resistance = 75;
	float heal = 0;
	float mobility = 5;
public:
	Zombie();
	virtual void showHeroStats();
};
