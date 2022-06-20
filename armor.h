#ifndef __ARMOR_H
#define __ARMOR_H

#include "treasure.h"

class Armor :virtual public Treasure
{
public:
	Armor(int x = -1, int y = -1, int level = 1);
	string getName() const override;
	virtual Armor* clone() const override;
};


#endif