#include "weapon.h"

Weapon::Weapon(int level, double percentStat) : Treasure(level,percentStat)
{

}

string Weapon::getName() const
{
	return Treasure::getName() + "weapon";
}