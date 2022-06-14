#include "armor.h"

Armor::Armor(int x,int y, int level, double percentStat) :Treasure(x,y,level,percentStat) 
{

}

string Armor::getName() const
{
	return "armor";
}

Armor* Armor::clone() const
{
	return new Armor(*this);
 }