#ifndef __GAME_UTILITIES_H
#define __GAME_UTILITIES_H

#include "spell.h"
#include "armor.h"
#include "weapon.h"

class GameUtilities
{
public:
	static Treasure* generateTreasure(int level);
};

#endif