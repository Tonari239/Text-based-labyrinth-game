#include "monster.h"


Monster::Monster(int x,int y,int level) :BaseCreature(x,y),mSpell(x,y,level), mScaleDefensePercent(15)
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


void Monster::setInitialStats()
{
	mPower = 25;
	mMana = 25;
	mHealth = 50;
	mSpellPower = 25;
}


void Monster::attack(Hero& hero)
{
	double mana = getMana();
	double spellCost = getSpell().getManaCost();
	bool canCastASpell = (mana >= spellCost);
	double damageToTake = 0;

	if (canCastASpell)
	{
		srand(time(NULL));
		bool castsASpell = rand() % 2;;
		if (castsASpell)
		{
			damageToTake = castSpell(getSpell());
			cout << "Monster cast a spell and inflicted ";
		}
		else
		{
			damageToTake = physicalAttack(nullptr);
			cout <<"Monster attacked physically and inflicted ";
		}
		
	}
	else
	{
		damageToTake = physicalAttack(nullptr);
		cout << "Monster attacked physically and inflicted ";
	}
	double takenDamage = hero.takeDamage(damageToTake, hero.getInventory().getArmor().getPercentStat());
	cout << takenDamage << " damage." << endl;
}

void Monster::levelUp()
{
	setPower(getPower() + 10);
	setMana(getMana() + 10);
	setHealth(getHealth() + 10);
	mScaleDefensePercent += 5;
	mSpell.levelUp();
}


ostream& operator<<(ostream& out, const Monster& monster)
{
	//monster stats
	out << monster.mXCoordinate << ' ' << monster.mYCoordinate
		<< ' ' << monster.mHealth << ' ' << monster.mMana << ' ' << monster.mPower << ' ' << monster.mSpellPower
		<< ' ' <<monster.mScaleDefensePercent <<endl;

	//monster spell
	out << monster.mSpell;
	return out;
}

istream& operator>>(istream& in, Monster& monster)
{
	//monster stats
	in >> monster.mXCoordinate >> monster.mYCoordinate
		>> monster.mHealth >> monster.mMana >> monster.mPower >> monster.mSpellPower
		>> monster.mScaleDefensePercent;
	

	//monster spell
	in >> monster.mSpell;
	return in;

}

