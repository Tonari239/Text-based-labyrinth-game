#include "doctest.h"
#include "mapInfo.h"
#include "map.h"

TEST_SUITE("Map")
{ 
	//<level> <monsters count> <treasures count> <rows> <columns>
	
	MapInfo firstLevel = { 1, 2, 2, 10, 10 };
	MapInfo secondLevel = { 2,3,2,15,10 };

	TEST_CASE("Constructor with one MapInfo")
	{
		Map map(firstLevel);
		
		CHECK(map.getLevel() == 1);
		CHECK(map.getMonstersCount() == 2);
		CHECK(map.getTreasuresCount() == 2);
		CHECK(map.getCols() == 10);
		CHECK(map.getCols() == 10);
	}

	TEST_CASE("Constructor with two MapInfos")
	{
		
		Map map(firstLevel,secondLevel);

		CHECK(map.getLevel() == 3);
		CHECK(map.getMonstersCount() == 5);
		CHECK(map.getTreasuresCount() == 4);
		CHECK(map.getRows() == 25);
		CHECK(map.getCols() == 20);
	}

	TEST_CASE("Constructor with raw data")
	{
		Map map(1, 2, 2, 10, 10);

		CHECK(map.getLevel() == 1);
		CHECK(map.getMonstersCount() == 2);
		CHECK(map.getTreasuresCount() == 2);
		CHECK(map.getCols() == 10);
		CHECK(map.getCols() == 10);
	}

	TEST_CASE("Get level")
	{
		Map map(firstLevel);
		map.getLevel() == 1;
	}

	TEST_CASE("Set entity on map")
	{
		Map map(firstLevel);
		map.setEntityOnMap(3, 3, 'H');
		CHECK(map.getCell(3,3).getSymbol() == 'H');

	}

	TEST_CASE("Set entity on map throws exception when out of bounds")
	{
		Map map(firstLevel);
		CHECK_THROWS(map.setEntityOnMap(-3, 3, 'H'));
		CHECK_THROWS(map.setEntityOnMap(20, 3, 'H'));
	}

	TEST_CASE("Mark cell as visited")
	{
		Map map(firstLevel);
		map.markCellAsVisited(3, 3);
		CHECK(map.getCell(3, 3).hasBeenVisited() == true);

	}

	TEST_CASE("Mark cell as visited throws exception when out of bounds")
	{
		Map map(firstLevel);
		CHECK_THROWS(map.markCellAsVisited(-3, 3));

	}


	TEST_CASE("Get cell throws exception when out of bounds")
	{
		Map map(firstLevel);
		CHECK_THROWS(map.getCell(30, 3));
	}

	
	TEST_CASE("Get treasure index by coordinate throws exception when out of bounds")
	{
		Map map(firstLevel);
		CHECK_THROWS(map.getTreasureIndexByCoordinates(-3, 26));
	}

	TEST_CASE("Get monster index by coordinate throws exception when out of bounds")
	{
		Map map(firstLevel);
		CHECK_THROWS(map.getMonsterIndexByCoordinates(-3, 26));
	}
}