#ifndef __HERO_H
#define __HERO_H


#include <iostream>


#include "inventory.h"
#include "monster.h"
class Monster;

using namespace std;

enum Race
{
	HUMAN=0,
	MAGE,
	WARRIOR
};

class Hero :public BaseCreature
{
private:
	Race mRace;
	int mCurrentLevel;
	Inventory mInventory;

	
	void initializeRaceStats();
	int chooseAttackMethod() const;
	void restoreStatsAfterBattle(double initialHealth, double initialMana, double percentToRecover);
	void distributeStats();
protected:
public:
	Hero(Race race);
	bool battle(Monster& monster);
	void attack(Monster& monster);
	const Inventory& getInventory() const;
	void levelUp() override;
	int getCurrentLevel() const;
	void setCoordinates(int x, int y);
	void takeTreasure(const Treasure& treasure);

	friend ostream& operator<<(ostream& out, const Hero& hero);
	friend istream& operator>>(istream& in,Hero& hero);
	
};


#endif