#include "spell.h"
#include "doctest.h"

TEST_SUITE("Spell")
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
		Spell s(1, 1, 3);
		CHECK(s.getXCoordinate() == 1);
		CHECK(s.getYCoordinate() == 1);
		CHECK(s.getPercentStat() == 24);
		CHECK(s.getManaCost() == 5);

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
		Spell s2(1, 1, 2);
		CHECK(s2.getPercentStat() == 22);

		s2.levelUp();
		CHECK(s2.getPercentStat() == 24);
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