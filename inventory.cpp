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

Inventory::Inventory(Weapon weapon, Spell spell) : mWeapon(weapon), mSpell(spell), mArmor(-1,-1,0.0)
{
	
}

Inventory::Inventory(Weapon weapon, Spell spell, Armor armor) :mWeapon(weapon), mSpell(spell),mArmor(armor)
{

}

ostream& operator<<(ostream& out, const Inventory& inventory)
{
	out << inventory.mWeapon;
	out << inventory.mSpell;
	out << inventory.mArmor;
	return out;
}
istream& operator>>(istream& in, Inventory& inventory)
{
	in >> inventory.mWeapon;
	in >> inventory.mSpell;
	in >> inventory.mArmor;
	return in;
}