#include "doctest.h"
#include "treasureContainer.h"
#include "spell.h"
#include "weapon.h"
#include "armor.h"

TEST_SUITE("Test container")
{
	TEST_CASE("Default constructor")
	{
		TreasureContainer tc;
		CHECK(tc.getCount() == 0);
		tc.addTreasure(Spell());
		CHECK(tc.getCount() == 1);
	}

	TEST_CASE("Copy constructor")
	{
		TreasureContainer tc1(4);
		tc1.addTreasure(Spell());
		tc1.addTreasure(Armor());
		tc1.addTreasure(Weapon());
		tc1.addTreasure(Spell());
		tc1.addTreasure(Spell());

		TreasureContainer tc2(tc1);
		CHECK(tc2.getAt(3)->getName() == tc1.getAt(3)->getName());
		CHECK(tc2.getAt(1)->getXCoordinate() == tc1.getAt(1)->getXCoordinate());
		CHECK(tc2.getCount() == tc1.getCount());
	}

	TEST_CASE("Operator = ")
	{
		TreasureContainer tc1(4);
		tc1.addTreasure(Spell());
		tc1.addTreasure(Armor());
		tc1.addTreasure(Weapon());
		tc1.addTreasure(Spell());
		tc1.addTreasure(Spell());

		TreasureContainer tc2;
		tc2 = tc1;
		CHECK(tc2.getAt(3)->getName() == tc1.getAt(3)->getName());
		CHECK(tc2.getAt(1)->getXCoordinate() == tc1.getAt(1)->getXCoordinate());
		CHECK(tc2.getCount() == tc1.getCount());
	}

	TEST_CASE("Add treasure")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		CHECK(tc1.getCount() == 1);
		tc1.addTreasure(Armor());
		tc1.addTreasure(Weapon());
		tc1.addTreasure(Spell());
		tc1.addTreasure(Spell());

		CHECK(tc1.getCount() == 5);
		CHECK(tc1.getAt(1)->getName() == "armor");
	}

	TEST_CASE("Remove treasure on index")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		CHECK(tc1.getCount() == 1);
		tc1.addTreasure(Armor());
		tc1.addTreasure(Weapon());
		tc1.addTreasure(Spell());
		tc1.addTreasure(Spell());

		CHECK(tc1.getAt(0)->getName() == "spell");
		tc1.removeIndex(0);
		CHECK(tc1.getAt(0)->getName() != "spell");
	}

	TEST_CASE("Remove treasure on index throws exception when index out of bound")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		CHECK_THROWS(tc1.removeIndex(-1));
		CHECK_THROWS(tc1.removeIndex(2));
	}

	TEST_CASE("Remove treasure on index throws exception when collection is empty")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		tc1.removeIndex(0);
		CHECK_THROWS(tc1.removeIndex(0));
	}


	TEST_CASE("Get treasure at index")
	{
		Spell spell;
		TreasureContainer tc1;
		tc1.addTreasure(spell);
		CHECK(tc1.getAt(0)->getName() == spell.getName());
	}

	TEST_CASE("Get treasure at index throws exception when out of bounds")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		CHECK_THROWS(tc1.getAt(-1));
		CHECK_THROWS(tc1.getAt(31));
	}

	TEST_CASE("Operator []")
	{
		TreasureContainer tc1;
		tc1.addTreasure(Spell());
		CHECK(tc1.getCount() == 1);
		tc1.addTreasure(Armor());
		tc1.addTreasure(Weapon());
		tc1.addTreasure(Spell());
		tc1.addTreasure(Spell());

		Treasure* t = new Treasure(tc1[1]);
		CHECK(t != nullptr);
		CHECK_THROWS(tc1[10]);
		CHECK_THROWS(tc1[-1]);
		delete t;
	}

}