#include "spell.h"


Spell::Spell(int x, int y, double percentStat, int level)
	:Treasure(x, y, level, percentStat), mManaCost(5)
{

}

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

ostream& operator<<(ostream& out, const Spell& spell)
{
	out << spell.mXCoordinate << ' ' << spell.mYCoordinate <<' '<< spell.getPercentStat() <<' '<< spell.mManaCost;
	return out;
}

istream& operator>>(istream& in, Spell& spell)
{
	double percentStat;
	in >> spell.mXCoordinate >> spell.mYCoordinate >> percentStat >> spell.mManaCost;
	spell.setPercentStat(percentStat);
	return in;
}