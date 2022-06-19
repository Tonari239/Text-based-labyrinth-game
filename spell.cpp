#include "spell.h"



double Spell::getManaCost() const
{
	return mManaCost;
}

Spell::Spell(int x,int y, double percentStat, double manaCost, int level)
	:Treasure(x,y,level, percentStat),mManaCost(manaCost)
{

}

Spell::Spell(int x, int y, int level) : Treasure(x, y, level)
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

ostream& operator<<(ostream& out, const Spell& spell)
{
	out << spell.mXCoordinate << spell.mYCoordinate << spell.getPercentStat();
	return out;
}

istream& operator>>(istream& in, Spell& spell)
{
	double percentStat;
	in >> spell.mXCoordinate >> spell.mYCoordinate >> percentStat >> spell.mManaCost;
	spell.setPercentStat(percentStat);
	return in;
}