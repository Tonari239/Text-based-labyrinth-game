#include "doctest.h"
#include "monster.h"
#include "hero.h"

TEST_SUITE("Monster")
{
	TEST_CASE("Default constructor")
	{
		Monster m;
		CHECK(m.getXCoordinate() == -1);
		CHECK(m.getYCoordinate() == -1);
		CHECK(m.getScaleDefensePercent() == 15);
	}

	TEST_CASE("Constructor with parameters")
	{
		Monster m(3, 3, 3);
		CHECK(m.getXCoordinate() == 3);
		CHECK(m.getYCoordinate() == 3);
		CHECK(m.getScaleDefensePercent() == 25);
	}

	TEST_CASE("Getters")
	{
		Monster m;
		CHECK(m.getPower() == 25);
		CHECK(m.getMana() == 25);
		CHECK(m.getHealth() == 50);
		CHECK(m.getSpellPower() == 25);
		CHECK(m.getScaleDefensePercent() == 15);

		m.levelUp();
		CHECK(m.getPower() == 35);
		CHECK(m.getMana() == 35);
		CHECK(m.getHealth() == 60);
		CHECK(m.getScaleDefensePercent() == 20);
	}

	TEST_CASE("Setters")
	{
		Monster m;
		m.setHealth(6);
		m.setSpellPower(3);
		m.setMana(300);
		m.setPower(5);
		CHECK(m.getHealth() == 6);
		CHECK(m.getSpellPower() == 3);
		CHECK(m.getMana() == 300);
		CHECK(m.getPower() == 5);
	
		m.setMana(-3);
		CHECK(m.getMana() == 0);
	}

	TEST_CASE("Check initial stats")
	{
		Monster m;
		CHECK(m.getHealth() == 50);
		CHECK(m.getPower() == 25);
		CHECK(m.getMana() == 25);
		CHECK(m.getSpellPower() == 25);
	}

	TEST_CASE("Level up")
	{
		Monster m;
		m.levelUp();
		m.levelUp();
		m.levelUp();
		CHECK(m.getScaleDefensePercent() == 30);
		CHECK(m.getHealth() == 80);
	}


	TEST_CASE("Attack")
	{
		Hero h((Race)1);
		Monster m;
		m.attack(h);
		CHECK(h.getHealth() != 50);
	}

	TEST_CASE("SetPower throws exception")
	{
		Monster m;
		CHECK_THROWS(m.setPower(-3));
	}

	TEST_CASE("Cast spell")
	{
		Monster m;
		double damage = m.castSpell(m.getSpell());
		CHECK(m.getMana()==20);
		CHECK(damage != 0);
	}

	TEST_CASE("Physical attack without weapon")
	{
		Monster m;
		double damage = m.physicalAttack(nullptr);
		CHECK(damage != 0);
	}

	TEST_CASE("Take damage")
	{
		Monster m;
		double expectedDamage = (85.0/100)*20;
		CHECK(m.takeDamage(20, 15)==expectedDamage);
		CHECK(m.getHealth() !=50 );
		
		CHECK(m.getHealth() == 50-expectedDamage);
	}

	TEST_CASE("Take damage throws exception when taking negative damage")
	{
		Monster m;
		CHECK_THROWS(m.takeDamage(-10,15));
	}

}