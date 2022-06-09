#ifndef __MONSTER_H
#define __MONSTER_H

#include "spell.h"
#include "baseCreature.h"
#include "hero.h"

class Hero;
class Monster :public BaseCreature
{
	double mScaleDefensePercent=15;
	Spell mSpell;
public:
	Monster(int level=1); // TODO: utochni si kak shte sazdavash chudovishtata
	double getScaleDefensePercent() const;
	const Spell& getSpell() const;
	void levelUp() override;
	void attack(Hero& hero);
};

#endif