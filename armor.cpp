#include "armor.h"

Armor::Armor(int x, int y, int level) : Treasure(x, y, level)
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