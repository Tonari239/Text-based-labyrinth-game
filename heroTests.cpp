#include "doctest.h"
#include "monster.h"
#include "hero.h"

TEST_SUITE("Hero")
{
	TEST_CASE("Constructor for human")
	{
		Hero h(Race::HUMAN);
		CHECK(h.getPower() == 30);
		CHECK(h.getMana() == 20);
		CHECK(h.getHealth() == 50);
		CHECK(h.getSpellPower() == 20);
	}

	TEST_CASE("Constructor for mage")
	{
		Hero h(Race::MAGE);
		CHECK(h.getPower() == 10);
		CHECK(h.getMana() == 40);
		CHECK(h.getHealth() == 50);
		CHECK(h.getSpellPower() == 40);
	}

	TEST_CASE("Constructor for warrion")
	{
		Hero h(Race::WARRIOR);
		CHECK(h.getPower() == 40);
		CHECK(h.getMana() == 10);
		CHECK(h.getHealth() == 50);
		CHECK(h.getSpellPower() == 10);
	}

	TEST_CASE("Level")
	{
		Hero h(Race::HUMAN);
		CHECK(h.getCurrentLevel() == 1);
	}

	TEST_CASE("Setters")
	{
		Hero h(Race::HUMAN);
		h.setHealth(6);
		h.setSpellPower(3);
		h.setMana(300);
		h.setPower(5);
		CHECK(h.getHealth() == 6);
		CHECK(h.getSpellPower() == 3);
		CHECK(h.getMana() == 300);
		CHECK(h.getPower() == 5);

		h.setCoordinates(3, 1);
		CHECK(h.getXCoordinate() == 3);
		CHECK(h.getYCoordinate() == 1);
	}


	TEST_CASE("SetPower throws exceptions")
	{
		Hero h(Race::HUMAN);
		CHECK_THROWS(h.setPower(-3));
	}

	TEST_CASE("Cast spell")
	{
		Hero h(Race::MAGE);
		double damage = h.castSpell(h.getInventory().getSpell());
		CHECK(h.getMana() == 35);
		CHECK(damage != 0);
	}

	TEST_CASE("Physical attack with weapon")
	{
		Hero h(Race::MAGE);
		Weapon* w = new Weapon(h.getInventory().getWeapon());
		double damage = h.physicalAttack(w);
		delete w;
		CHECK(damage != 0);
	}

	TEST_CASE("Take damage")
	{
		Hero h(Race::MAGE);
		double expectedDamage = 20;
		CHECK(h.takeDamage(20, 0) == expectedDamage);
		CHECK(h.getHealth() != 50);

		CHECK(h.getHealth() == 50 - expectedDamage);
	}

	TEST_CASE("Take damage throws exception when taking negative damage")
	{
		Hero h(Race::MAGE);
		CHECK_THROWS(h.takeDamage(-10, 15));
	}

	TEST_CASE("Restore mana points")
	{
		Hero h(Race::MAGE);
		h.restoreManaPoint(1);
		CHECK(h.getMana() == 40);
		h.setMana(10);
		CHECK(h.getMana() == 10);
		h.restoreManaPoint(5);
		CHECK(h.getMana() == 15);
	}
}