#ifndef __INVENTORY_H
#define __INVENTORY_H

#include "spell.h"
#include "armor.h"
#include "weapon.h"

class Inventory
{
	Weapon mWeapon;
	Spell mSpell;
	Armor mArmor;


public:
	Inventory(Weapon weapon, Spell spell); 
	Inventory(Weapon weapon, Spell spell, Armor armor);
	const Spell& getSpell() const;
	const Armor& getArmor() const;
	const Weapon& getWeapon() const;

	void setSpell(const Spell& spell);
	void setArmor(const Armor& armor);
	void setWeapon(const Weapon& weapon);
	
};

#endif