#include "armor.h"

Armor::Armor(int level, double percentStat) :Treasure(level,percentStat) // weapons improve as levels improve
{

}

string Armor::getName() const
{
	return Treasure::getName() + "armor";
}