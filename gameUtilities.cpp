#include "gameUtilities.h"
#include <time.h>

#include <iostream>

Treasure* GameUtilities::generateTreasure(int level)
{
	srand(time(NULL));
	int num = rand() % 3;
	if (num==0)
	{
		return new Spell(level);
	
	}
	else if (num==1)
	{
		return new Armor(level);
	}
	else
	{
		return new Weapon(level);
	}
}