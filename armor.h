#ifndef __ARMOR_H
#define __ARMOR_H

#include "treasure.h"

class Armor :virtual public Treasure
{
public:
	Armor(int level = 1, double percentStat = 20);
	string getName() const override;
};


#endif