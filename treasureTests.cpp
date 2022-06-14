#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "treasure.h"

TEST_SUITE("Treasure")
{
	TEST_CASE("Default Constructor")
	{
		Treasure t;
		CHECK(t.getXCoordinate() == -1);
		CHECK(t.getYCoordinate() == -1);
		CHECK(t.getPercentStat() == 20);
	}

	TEST_CASE("Constructor with parameters")
	{
		Treasure t(3, 3, 5,30);
		CHECK(t.getXCoordinate() == 3);
		CHECK(t.getYCoordinate() == 3);
		CHECK(t.getPercentStat() == 38);
	}

	TEST_CASE("Get percent stat")
	{
		Treasure t(1, 1, 3);
		CHECK(t.getPercentStat() == 24);
	}

	TEST_CASE("Level up")
	{
		Treasure t(1, 1, 3);
		t.levelUp();
		t.levelUp();
		t.levelUp();
		CHECK(t.getPercentStat() == 30);
	}
}