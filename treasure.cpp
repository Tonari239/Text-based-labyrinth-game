#include "treasure.h"

double Treasure::getPercentStat() const
{
	return mPercentStat;
}



void Treasure::levelUp()
{
	mPercentStat += 2;
}

Treasure::Treasure(int x,int y,int level, double percentStat) :BaseEntity(x,y),mPercentStat(percentStat)
{
	for (int i = 1; i < level; i++)
	{
		levelUp();
	}
}

string Treasure::getName() const
{
	return "";
}

 Treasure* Treasure::clone() const
{
	 return new Treasure(*this);
}