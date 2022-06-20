#include "gameUtilities.h"
#include <time.h>
#include <iostream>


Treasure* GameUtilities::generateTreasure(int x,int y,int level)
{
	srand(time(NULL));
	int num = rand() % 3;
	if (num==0)
	{
		return new Spell(x,y,level);
	}
	else if (num==1)
	{
		return new Armor(x, y,level);
	}
	else
	{
		return new Weapon(x, y,level);
	}
}


