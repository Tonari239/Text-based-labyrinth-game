#include "doctest.h"
#include "inventory.h"

TEST_SUITE("Inventory")
{
	TEST_CASE("Constructor with weapon and spell")
	{
		Weapon weapon(1, 1, 2);
		Spell spell(3, 1, 1);
		Inventory inv(weapon, spell);

		CHECK(inv.getSpell().getXCoordinate() == 3);
		CHECK(inv.getSpell().getXCoordinate() == 1);
		CHECK(inv.getWeapon().getPercentStat() == 22);
	}

	TEST_CASE("Cosntructor with all treasures")
	{
		Weapon weapon(1, 1, 2);
		Spell spell(3, 1, 1);
		Armor armor(4, 1, 3);
		Inventory inv(weapon, spell,armor);

		CHECK(inv.getSpell().getXCoordinate() == 3);
		CHECK(inv.getSpell().getXCoordinate() == 1);
		CHECK(inv.getWeapon().getPercentStat() == 22);
		CHECK(inv.getArmor().getXCoordinate() == 4);
		CHECK(inv.getArmor().getPercentStat() == 24);
	}

	TEST_CASE("Setters")
	{
		Weapon weapon(1, 1, 2);
		Spell spell(3, 1, 1);
		Inventory inv(weapon, spell);

		Armor armor(4, 1, 3);
		inv.setArmor(armor);

		CHECK(inv.getArmor().getXCoordinate() == 4);
		CHECK(inv.getArmor().getPercentStat() == 24);
	}
}