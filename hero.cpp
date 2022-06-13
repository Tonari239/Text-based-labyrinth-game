#include "hero.h"
#include "utilities.h"

void Hero::initializeRaceStats()
{
	if (mRace == 0)
	{
		mPower = 30;
		mMana = 20;
		mHealth = 50;
	}
	else if (mRace == 1)
	{
		mPower = 10;
		mMana = 40;
		mHealth = 50;
	}
	else
	{
		mPower = 40;
		mMana = 10;
		mHealth = 50;
	}
}

void Hero::attack(Monster& monster)
{
	double mana = getMana();
	double spellCost = getInventory().getSpell().getManaCost();
	bool canCastASpell = (mana >= spellCost);
	double damageToTake = 0;
	Spell spell = getInventory().getSpell();
	Weapon* weapon = new Weapon(getInventory().getWeapon());
	if (canCastASpell)
	{
		bool castsASpell = chooseAttackMethod();
		damageToTake = castsASpell ? castSpell(monster.getSpell()) : physicalAttack(weapon);
	}
	else
	{
		cout << "Current mana is " << mana << " while spell costs " << spellCost << ". Attacking physically instead." << endl;
		damageToTake = physicalAttack(weapon);
	}
	delete weapon;
	monster.takeDamage(damageToTake, monster.getScaleDefensePercent()); 
}

void Hero::levelUp()
{
	++mCurrentLevel;
	distributeStats();
}

void Hero::distributeStats()
{
	cout << "You leveled up! You have 30 points to distribute between power, health and mana!" << endl;
	cout << "Enter values for <Power> <Mana> <Health> accordingly:" << endl;
	int power, mana, health;
	cin >> power >> mana >> health;
	while (power+mana+health!=30)
	{
		cout << "Invalid values! Please try again." << endl;
		cin >> power >> mana >> health;
	}
	setMana(getMana() + mana);
	setPower(getPower() + power);
	setHealth(getHealth() + health);
}

bool Hero::battle(Monster& monster)
{
	double initialHealth = getHealth();
	double initialMana = getMana();
	int heroAttacksFirst = Utilities::generateRandom(); // 1 ->	hero, 0 -> dragon
	if (heroAttacksFirst)
	{
		while (getHealth()>0 && monster.getHealth() > 0)
		{
			attack(monster);
			monster.attack(*this);
		}
	}
	else
	{
		while (getHealth() > 0 && monster.getHealth() > 0)
		{
			monster.attack(*this);
			attack(monster);
		}
	}
	
	if (monster.getHealth() <= 0)
	{
		cout << "Victory!" <<endl;
		double restoredHealth = getHealth() + initialHealth * 1.0 / 2;
		if (restoredHealth >= initialHealth)
		{
			setHealth(initialHealth);
		}
		else
		{
			restoreStatsAfterBattle(initialHealth, initialMana, 1.0 / 2);
		}
		return 1;
	}
	else 
	{
		cout << "You lost! :("<<endl;
		throw - 1; // will catch this in game engine
	}
	
}

int Hero::chooseAttackMethod() const
{
	cout << "Choose your attack type!" << endl;
	cout << " \'0\' for physical attack or \'1\' for spell" << endl;
	char choice;
	cin >> choice;
	return choice;
}

const Inventory& Hero::getInventory() const
{
	return mInventory;
}

Hero::Hero(Race race) :mInventory(Weapon(),Spell()), mRace(race), mCurrentLevel(1)
{
	initializeRaceStats();
}

void Hero::restoreStatsAfterBattle(double initialHealth, double initialMana, double percentToRecover)
{
	double restoredHealth = getHealth() + initialHealth * percentToRecover;
	double restoredMana = getMana() + initialMana * percentToRecover;
	setHealth(restoredHealth);
	setMana(restoredMana);
}

int Hero::getCurrentLevel() const
{
	return mCurrentLevel;
}

void Hero::setCoordinates(int x, int y)
{
	mXCoordinate = x;
	mYCoordinate = y;
}

void Hero::takeTreasure(const Treasure& treasure)
{
	cout << "You found a " << treasure.getName() << " .Would you like to keep it?: y/n" << endl;
	char c;
	cin >> c;
	while (c!='y' && c!='n')
	{
		cout << "Invalid input!Try again." << endl;
		cin >> c;
	}
	if (c == 'n')
	{
		return;
	}
	else
	{
		if (treasure.getName() == "spell")
		{
			
			mInventory.setSpell(Spell(mCurrentLevel,treasure.getPercentStat()));
		}
		else if (treasure.getName() == "weapon")
		{
			mInventory.setWeapon(Weapon(mCurrentLevel, treasure.getPercentStat()));
		}
		else
		{
			mInventory.setArmor(Armor(mCurrentLevel, treasure.getPercentStat()));
		}
	}

}