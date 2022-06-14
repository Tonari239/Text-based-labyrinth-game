#include "spell.h"



double Spell::getManaCost() const
{
	return mManaCost;
}

Spell::Spell(int x,int y, int level, double percentStat, double manaCost) 
	:Treasure(x,y,level, percentStat),mManaCost(manaCost)
{

}

string Spell::getName() const
{
	return "spell";
}

Spell* Spell::clone() const
{
	return new Spell(*this);
}