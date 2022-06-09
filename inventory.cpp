#include "inventory.h"

const Spell& Inventory::getSpell() const
{
	return mSpell;
}

const Armor& Inventory::getArmor() const
{
	return mArmor;
}

const Weapon& Inventory::getWeapon() const
{
	return mWeapon;
}


void Inventory::setSpell(const Spell& spell)
{
	mSpell = spell;
}

void Inventory::setArmor(const Armor& armor)
{
	mArmor = armor;
}

void Inventory::setWeapon(const Weapon& weapon)
{
	mWeapon = weapon;
}

Inventory::Inventory(Weapon weapon, Spell spell) : mWeapon(weapon), mSpell(spell)
{
	setArmor(Armor(0));
}

Inventory::Inventory(Weapon weapon, Spell spell, Armor armor)
{

}