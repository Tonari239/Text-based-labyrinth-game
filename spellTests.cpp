#include "spell.h"
#include "doctest.h"

TEST_SUITE("Weapon")
{
	TEST_CASE("Default constructor")
	{
		Spell s;
		CHECK(s.getXCoordinate() == -1);
		CHECK(s.getYCoordinate() == -1);
		CHECK(s.getPercentStat() == 20);
		CHECK(s.getManaCost() == 5);

	}

	TEST_CASE("Constructor with parameters")
	{
		Spell s(1, 1, 3, 20,10);
		CHECK(s.getXCoordinate() == 1);
		CHECK(s.getYCoordinate() == 1);
		CHECK(s.getPercentStat() == 24);
		CHECK(s.getManaCost() == 10);

	}

	TEST_CASE("Get name")
	{
		Spell s;
		CHECK(s.getName() == "spell");
	}

	TEST_CASE("Get percent stat")
	{
		Spell s;
		CHECK(s.getPercentStat() == 20);
		Spell s2(1, 1, 1, 30);
		CHECK(s2.getPercentStat() == 30);

		s2.levelUp();
		CHECK(s2.getPercentStat() == 32);
	}

	TEST_CASE("level up")
	{
		Spell s;
		s.levelUp();
		CHECK(s.getPercentStat() == 22);
	}

	TEST_CASE("Get mana cost")
	{
		Spell s;
		CHECK(s.getManaCost() == 5);
	}
}