#include "gameUtilities.h"
#include <time.h>

#include <iostream>

Treasure GameUtilities::generateTreasure(int level)
{
	srand(time(NULL));
	int num = rand() % 3;
	if (num==0)
	{
		return Spell(level);
	
	}
	else if (num==1)
	{
		return Armor(level);
	}
	else
	{
		return Weapon(level);
	}
}