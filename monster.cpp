#include "monster.h"
#include "utilities.h"

Monster::Monster(int x,int y,int level) :BaseCreature(x,y),mSpell(x,y,level)
{
	setInitialStats();
	for (int i = 1; i < level; i++)
	{
		levelUp();
	}
}

double Monster::getScaleDefensePercent() const
{
	return mScaleDefensePercent;
}

const Spell& Monster::getSpell() const
{
	return mSpell;
}

void Monster::attack(Hero& hero)
{
	double mana = getMana();
	double spellCost = getSpell().getManaCost();
	bool canCastASpell = (mana >= spellCost);
	double damageToTake = 0;

	if (canCastASpell)
	{
		bool castsASpell = Utilities::generateRandom();
		damageToTake = castsASpell ? castSpell(getSpell()) : physicalAttack(nullptr);
	}
	else
	{
		damageToTake = physicalAttack(nullptr);
	}
	hero.takeDamage(damageToTake, hero.getInventory().getArmor().getPercentStat());
}

void Monster::levelUp()
{
	setPower(getPower() + 10);
	setMana(getMana() + 10);
	setHealth(getHealth() + 10);
	mScaleDefensePercent += 5;
	mSpell.levelUp();
}

void Monster::setInitialStats()
{
	mPower = 25;
	mMana = 25;
	mHealth = 50;
	mSpellPower = 25;
}