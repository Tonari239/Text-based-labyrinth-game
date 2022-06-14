#ifndef __WEAPON_H
#define __WEAPON_H

#include "treasure.h"

class Weapon :virtual public Treasure
{
public:
	Weapon(int x=-1,int y=-1, int level=1,double percentStat = 20);
	string getName() const override;
	virtual Weapon* clone() const override;
};


#endif