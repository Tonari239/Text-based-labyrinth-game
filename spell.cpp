#include "spell.h"



double Spell::getManaCost() const
{
	return mManaCost;
}

Spell::Spell(int level, double percentStat, double manaCost) 
	:Treasure(level, percentStat),mManaCost(manaCost)
{

}

string Spell::getName() const
{
	return "spell";
}