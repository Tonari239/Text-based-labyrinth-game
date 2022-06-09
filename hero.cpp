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

void Battle(Hero& hero,Monster& monster)
{
	double initialHealth = hero.getHealth();
	double initialMana = hero.getMana();
	int heroAttacksFirst = Utilities::generateRandom(); // 1 ->	hero, 0 -> dragon
	if (heroAttacksFirst)
	{
		while (hero.getHealth()>0 && monster.getHealth() > 0)
		{
			hero.attack(monster);
			monster.attack(hero);
		}
	}
	else
	{
		while (hero.getHealth() > 0 && monster.getHealth() > 0)
		{
			monster.attack(hero);
			hero.attack(monster);
		}
	}
	
	if (monster.getHealth() <= 0)
	{
		cout << "Victory!" <<endl;
		double healthToRestore = hero.getHealth() + initialHealth * 1 / 2;
		if (healthToRestore >= initialHealth)
		{
			hero.setHealth(initialHealth);
		}
		else
		{
			hero.restoreStatsAfterBattle(initialHealth, initialMana, 1.0 / 2);
		}

	}
	else if (hero.getHealth()<=0)
	{
		cout << "You lost! :("<<endl;
		throw - 1; // will catch this in main and end program
	}
	
}

int Hero::chooseAttackMethod() const
{
	return 0;
}

const Inventory& Hero::getInventory() const
{
	return mInventory;
}



void Hero::restoreStatsAfterBattle(double initialHealth, double initialMana, double percentToRecover)
{

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