#include "baseCreature.h"


double BaseCreature::getMana() const
{
	return mMana;
}

double BaseCreature::getHealth() const
{
	return mHealth;
}

double BaseCreature::getPower() const
{
	return mPower;
}

void BaseCreature::takeDamage(double damage, double defensePercentBonus)
{
	if (damage <= 0)
	{
		throw "Invalid operation, damage taken cannot be non-positive!";
	}
	mHealth -= (100-defensePercentBonus) *damage;
}

void BaseCreature::setMana(double mana)
{
	if (mana <= 0)
	{
		mMana = 0;
	}
	else
	{
		mMana = mana;
	}
	
}

void BaseCreature::setHealth(double health)
{
	if (health <= 0)
	{
		mHealth = 0;
	}
	else
	{
		mHealth = health;
	}
	
}

void BaseCreature::setPower(double power)
{
	if (power < 0)
	{
		throw "Power cannot be negative value!";
	}
	mPower = power;
}

double BaseCreature::castSpell(const Spell& spell)
{
	double damageToTake = getPower() + getPower() * spell.getPercentStat() / 100; // adding the bonus
	mMana -= spell.getManaCost();
	return damageToTake;
}

double BaseCreature::physicalAttack(Weapon* weapon) const
{
	double damageToTake = 0;
	if (weapon == nullptr)
	{
		damageToTake = getPower(); // adding the bonus
	}
	else
	{
		damageToTake = getPower() + getPower() * (*weapon).getPercentStat() / 100; // adding the bonus
	}
	
	return damageToTake;
}