#include "weapon.h"

Weapon::Weapon(int x,int y, int level, double percentStat) : Treasure(x,y,level,percentStat)
{

}

string Weapon::getName() const
{
	return "weapon";
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}