#include "gameEngine.h"


MapInfo GameEngine::previousPreviousMapInfo = {1,2,2,10,10}; // first base level
MapInfo GameEngine::previousMapInfo = {2,3,2,15,10}; // second base level


GameEngine::GameEngine(const Hero& hero) : mHero(hero)
{
	
}

void GameEngine::generateLevel()
{
	positionHeroAtStart();
	generateMap();
}

void GameEngine::updatePreviousMapInfo(Map currentMap)
{
	previousPreviousMapInfo = previousMapInfo;
	previousMapInfo = {currentMap.getLevel(),currentMap.getMonstersCount(),currentMap.getTreasuresCount(),currentMap.getRows(),currentMap.getCols() };
}

void  GameEngine::positionHeroAtStart()
{
	int xCoordinate = 1;
	int yCoordinate = 1;
	mHero.setCoordinates(1, 1);
	mMap.setEntityOnMap(1, 1, '@');
}

void  GameEngine::moveHero(string direction)
{
	if (direction != "left" && direction != "right" && direction != "up" && direction != "down")
	{
		cout <<"Invalid direction! No action taken.";
	}
	if (direction == "left")
	{
		actOnDirection(mHero.getXCoordinate() - 1, mHero.getYCoordinate());
	}
	else if (direction == "right")
	{
		actOnDirection(mHero.getXCoordinate() + 1, mHero.getYCoordinate());
	}
	else if (direction == "up")
	{
		actOnDirection(mHero.getXCoordinate(), mHero.getYCoordinate()-1);
	}
	else if (direction == "down")
	{
		actOnDirection(mHero.getXCoordinate(), mHero.getYCoordinate() + 1);
	}
	else
	{
		cout << "Invalid direction!";
		return;
	}
}

void GameEngine::determineAction(int x,int y)
{
	if (destinationIsTreasure(x, y))
	{
		collectTreasure(x,y);
	}
	else if (destinationIsMonster(x, y))
	{
		try
		{
			int monsterIndex = mMap.getMonsterIndexByCoordinates(x, y);
			bool result = mHero.battle(mMap.mMonsters[monsterIndex]);
			if (result)
			{
				mMap.mMonsters.erase(mMap.mMonsters.begin() + monsterIndex);
				mMap.setEntityOnMap(x, y, '.'); // monster is no longer on cell
			}
		}
		catch (int )
		{
			throw - 1; // will catch this in main and end program;
		}
		
	}
	else if (destinationIsExit(x, y))
	{

	}
}

void GameEngine::collectTreasure(int x, int y)
{
	int treasureIndex = mMap.getTreasureIndexByCoordinates(x, y);
	mHero.takeTreasure(mMap.mTreasures.getAt(treasureIndex));
	mMap.mTreasures.removeIndex(treasureIndex);
}

bool GameEngine::destinationIsWall(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == '#';
}

bool GameEngine::destinationIsTreasure(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == 'T';
}

bool GameEngine::destinationIsMonster(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == 'M';
}

bool GameEngine::destinationIsExit(int x, int y) const
{
	return x == mMap.getRows() - 2 && y == mMap.getCols() - 1;
}

void GameEngine::generateMap()
{
	if (mHero.getCurrentLevel() == 1)
	{
		mMap = Map(previousPreviousMapInfo);
	}
	else if (mHero.getCurrentLevel() == 2)
	{
		mMap = Map(previousMapInfo);
	}
	else
	{
		mMap = Map(previousPreviousMapInfo, previousMapInfo);
	}
}

void GameEngine::actOnDirection(int nextXCoordinate,int nextYCoordinate)
{
	if (!destinationIsWall(nextXCoordinate, nextYCoordinate))
	{
		mHero.setCoordinates(nextXCoordinate, nextYCoordinate);
		determineAction(mHero.getXCoordinate(), mHero.getYCoordinate());
	}
}