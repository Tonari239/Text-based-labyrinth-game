#include "treasure.h"

double Treasure::getPercentStat() const
{
	return mPercentStat;
}

Treasure* Treasure::clone() const
{
	return new Treasure(*this);
}

void Treasure::levelUp()
{
	mPercentStat += 2;
}

Treasure::Treasure(int level, double percentStat) :mPercentStat(percentStat)
{
	for (int i = 0; i < level; i++)
	{
		levelUp();
	}
}