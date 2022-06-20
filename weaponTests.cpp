#include "weapon.h"
#include "doctest.h"

TEST_SUITE("Weapon")
{
	TEST_CASE("Default constructor")
	{
		Weapon w;
		CHECK(w.getXCoordinate() == -1);
		CHECK(w.getYCoordinate() == -1);
		CHECK(w.getPercentStat() == 20);

	}

	TEST_CASE("Constructor with parameters")
	{
		Weapon w(1, 1, 3);
		CHECK(w.getXCoordinate() == 1);
		CHECK(w.getYCoordinate() == 1);
		CHECK(w.getPercentStat() == 24);

	}

	TEST_CASE("Get name")
	{
		Weapon w;
		CHECK(w.getName() == "weapon");
	}

	TEST_CASE("Get percent stat")
	{
		Weapon w;
		CHECK(w.getPercentStat() == 20);
		Weapon w2(1, 1, 2);
		CHECK(w2.getPercentStat() == 22);
	}

	TEST_CASE("level up")
	{
		Weapon w;
		w.levelUp();
		CHECK(w.getPercentStat() == 22);
	}
}