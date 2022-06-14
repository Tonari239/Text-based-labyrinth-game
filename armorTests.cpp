#include "armor.h"
#include "doctest.h"

TEST_SUITE("Armor")
{
	TEST_CASE("Default constructor")
	{
		Armor a;
		CHECK(a.getXCoordinate() == -1);
		CHECK(a.getYCoordinate() == -1);
		CHECK(a.getPercentStat() == 20);
		
	}

	TEST_CASE("Constructor with parameters")
	{
		Armor a(1,1,3,20);
		CHECK(a.getXCoordinate() == 1);
		CHECK(a.getYCoordinate() == 1);
		CHECK(a.getPercentStat() == 24);

	}

	TEST_CASE("Get name")
	{
		Armor a;
		CHECK(a.getName() == "armor");
	}

	TEST_CASE("Get percent stat")
	{
		Armor a;
		CHECK(a.getPercentStat() == 20);
		Armor a2(1, 1, 1, 30);
		CHECK(a2.getPercentStat() == 30);
	}

	TEST_CASE("level up")
	{
		Armor a;
		a.levelUp();
		CHECK(a.getPercentStat() == 22);
	}
}