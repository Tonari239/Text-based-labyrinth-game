#ifndef __WEAPON_H
#define __WEAPON_H

#include "treasure.h"

class Weapon :virtual public Treasure
{
public:
	Weapon(int level=1,double percentStat = 20);
	string getName() const override;
};


#endif