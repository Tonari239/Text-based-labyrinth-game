#ifndef __SPELL_H
#define __SPELL_H

#include "treasure.h"

class Spell :virtual public Treasure
{
	double mManaCost;
public:
	Spell(int level = 1, double percentStat=10, double manaCost=5);
	double getManaCost() const;
};


#endif