#include "hero.h"


Hero::Hero(Race race) :mInventory(Weapon(0, 0, mCurrentLevel), Spell(0, 0, mCurrentLevel), Armor(0, 0, 0)), mRace(race), mCurrentLevel(1)
{
	initializeRaceStats();
}

int Hero::getCurrentLevel() const
{
	return mCurrentLevel;
}

const Inventory& Hero::getInventory() const
{
	return mInventory;
}

void Hero::setCoordinates(int x, int y)
{
	mXCoordinate = x;
	mYCoordinate = y;
}


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
	maxMana = mMana;
	mSpellPower = mMana;
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
		 
		if (castsASpell)
		{
			damageToTake = castSpell(spell);
			cout << "You cast a spell and inflict ";
		}
		else
		{
			damageToTake = physicalAttack(weapon);
			cout << "You attack physically and inflict ";
		}
	}
	else
	{
		cout << "Current mana is " << mana << " while spell costs " << spellCost << ". Attacking physically instead." << endl;
		damageToTake = physicalAttack(weapon);
	}
	delete weapon;
	double takenDamage = monster.takeDamage(damageToTake, monster.getScaleDefensePercent()); 
	cout << takenDamage << " damage." << endl;
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
	setSpellPower(getMana());
	setPower(getPower() + power);
	setHealth(getHealth() + health);
	maxMana += mana;
}

bool Hero::battle(Monster& monster)
{
	system("CLS");
	double initialHealth = getHealth();
	double initialMana = getMana();
	srand(time(NULL));
	int heroAttacksFirst = rand() % 2; // 1 ->	hero, 0 -> dragon
	if (heroAttacksFirst)
	{
		
		while (getHealth()>0 && monster.getHealth() > 0)
		{
			cout << "You attack first!" << endl;
			cout << "Your health: " << getHealth() << endl;
			cout <<"Monster health: " <<monster.getHealth() << endl <<endl;
			attack(monster);
			if (monster.getHealth() <= 0)
			{
				break;
			}
			monster.attack(*this);
			
		}
	}
	else
	{
		
		cout << "Monster attacks first!" << endl;
		while (getHealth() > 0 && monster.getHealth() > 0)
		{
			cout << "Your health: " << getHealth() << endl;
			cout << "Monster health: " << monster.getHealth() << endl <<endl;
			monster.attack(*this);
			if (getHealth() <= 0)
			{
				break;
			}
			attack(monster);
		}
	}
	
	if (monster.getHealth() <= 0)
	{
		double restoredHealth = getHealth() + initialHealth * 1.0 / 2;
		if (restoredHealth >= initialHealth)
		{
			setHealth(initialHealth);
			restoreManaPoint(1.0 / 2 * mMana);
		}
		else
		{
			restoreStatsAfterBattle(initialHealth, initialMana, 1.0 / 2);
		}
		return 1;
	}
	else if (mHealth<=0)
	{
		cout << "You lost! :("<<endl;
		throw - 1; // will catch this in game engine
	}
	
}

int Hero::chooseAttackMethod() const
{
	cout << "Choose your attack type!" << endl;
	cout << "\'0\' for physical attack or \'1\' for spell" << endl;
	int choice;
	cin >> choice;
	while (choice!=0 && choice!=1)
	{
		cin >> choice;
	}
	
	return choice;
}

void Hero::restoreStatsAfterBattle(double initialHealth, double initialMana, double percentToRecover)
{
	double restoredHealth = getHealth() + initialHealth * percentToRecover;
	double restoredMana = getMana() + initialMana * percentToRecover;
	setHealth(restoredHealth);
	setMana(restoredMana);
}

void Hero::restoreManaPoint(double point)
{
	if (mMana+point <= maxMana)
	{
		mMana += point;
	}
	else
	{
		mMana = maxMana;
	}
	
}

void Hero::takeTreasure(const Treasure& treasure)
{
	cout << "You found " << treasure.getName() << ". Would you like to keep it?: y/n" << endl;
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
			
			mInventory.setSpell(Spell(treasure.getXCoordinate(), treasure.getYCoordinate(), mCurrentLevel));
		}
		else if (treasure.getName() == "weapon")
		{
			mInventory.setWeapon(Weapon(treasure.getXCoordinate(), treasure.getYCoordinate(), mCurrentLevel));
		}
		else
		{
			mInventory.setArmor(Armor(treasure.getXCoordinate(),treasure.getYCoordinate(),mCurrentLevel));
		}
	}

}


ostream& operator<<(ostream& out, const Hero& hero)
{
	//hero stats
	out << hero.mCurrentLevel << ' ' << hero.mRace << ' ' << hero.mXCoordinate << ' ' << hero.mYCoordinate
		<< ' ' << hero.mHealth << ' ' << hero.mMana << ' ' << hero.mPower << ' ' << hero.mSpellPower <<' ' <<hero.maxMana << endl;

	//hero inventory
	out << hero.mInventory;
	return out;
}

istream& operator>>(istream& in, Hero& hero)
{
	//hero stats
	int race;
	in >> hero.mCurrentLevel >> race >> hero.mXCoordinate >> hero.mYCoordinate
		>> hero.mHealth >> hero.mMana >> hero.mPower >> hero.mSpellPower >>hero.maxMana;
	hero.mRace = (Race)race;

	//hero inventory
	in >> hero.mInventory;
	return in;

}

