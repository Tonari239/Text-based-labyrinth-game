#include "treasure.h"



Treasure::Treasure(int x, int y, int level) :BaseEntity(x, y)
{
	if (level == 0)
	{
		mPercentStat = 0;
	}
	else
	{
		mPercentStat = 20;
	}
	for (int i = 1; i < level; i++)
	{
		levelUp();
	}
}


string Treasure::getName() const
{
	return "";
}

double Treasure::getPercentStat() const
{
	return mPercentStat;
}


void Treasure::setPercentStat(double percentStat)
{
	if (percentStat < 20)
	{
		mPercentStat = 20;
	}
	else
	{
		mPercentStat = percentStat;
	}

}

void Treasure::levelUp()
{
	mPercentStat += 2;
}

Treasure* Treasure::clone() const
{
	 return new Treasure(*this);
}


ostream& operator<<(ostream& out, const Treasure& treasure)
{
	out  << treasure.mXCoordinate <<' ' << treasure.mYCoordinate << ' ' << treasure.mPercentStat;
	return out;
}

istream& operator>>(istream& in, Treasure& treasure)
{
	int level;
	in >> treasure.mXCoordinate >> treasure.mYCoordinate >> level;
	treasure.mPercentStat = 20;
	for (int i = 1; i < level; i++)
	{
		treasure.levelUp();
	}
	return in;
}



