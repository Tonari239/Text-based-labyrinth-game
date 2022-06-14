#ifndef __BASE_CREATURE_H
#define __BASE_CREATURE_H

#include "baseEntity.h"
#include "weapon.h"
#include "spell.h"

class BaseCreature :public BaseEntity
{
protected:
	double mMana;
	double mHealth;
	double mPower;
	double mSpellPower;
	

public:
	BaseCreature(int x = -1, int y = -1);
	double getMana() const;
	double getHealth() const;
	double getPower() const;
	double getSpellPower() const;

	void setMana(double mana);
	void setHealth(double health);
	void setPower(double power);
	void setSpellPower(double spellPower);

	double takeDamage(double damage, double defensePercentBonus);

	double castSpell(const Spell& spell);
	double physicalAttack(Weapon* weapon) const;
	

	
};

#endif