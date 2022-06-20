#include "spell.h"


Spell::Spell(int x, int y, int level) : Treasure(x, y, level), mManaCost(5)
{

}


double Spell::getManaCost() const
{
	return mManaCost;
}

string Spell::getName() const
{
	return "spell";
}


Spell* Spell::clone() const
{
	return new Spell(*this);
}
