#ifndef __SPELL_H
#define __SPELL_H

#include "treasure.h"

class Spell :virtual public Treasure
{
	double mManaCost;
public:
	Spell(int x=-1,int y=-1, double percentStat=20, double manaCost=5, int level = 1);
	Spell(int x = -1, int y = -1, int level = 1);
	double getManaCost() const;
	string getName() const override;
	virtual Spell* clone() const override;

	friend ostream& operator<<(ostream& out, const Spell& spell);
	friend istream& operator>>(istream& in, Spell& spell);
};


#endif