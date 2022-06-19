#include "treasure.h"

double Treasure::getPercentStat() const
{
	return mPercentStat;
}



void Treasure::levelUp()
{
	mPercentStat += 2;
}

Treasure::Treasure(int x,int y,double percentStat, int level) :BaseEntity(x,y),mPercentStat(percentStat)
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

ostream& operator<<(ostream& out, const Treasure& treasure)
{
	out  << treasure.mXCoordinate << treasure.mYCoordinate << treasure.mPercentStat;
	return out;
}

istream& operator>>(istream& in, Treasure& treasure)
{
	in >> treasure.mXCoordinate >> treasure.mYCoordinate >> treasure.mPercentStat;
	return in;
}

Treasure::Treasure(int x, int y, int level) :BaseEntity(x,y),mPercentStat(20)
{
	for (int i = 1; i < level; i++)
	{
		levelUp();
	}
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