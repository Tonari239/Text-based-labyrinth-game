#include "gameEngine.h"

//format for map info:  <level> <monsters count> <treasures count> <rows> <columns>
MapInfo GameEngine::previousPreviousMapInfo = {1,2,2,10,10}; //  first base level
MapInfo GameEngine::previousMapInfo = {2,3,2,15,10}; // second base level


GameEngine::GameEngine(const Hero& hero) : mHero(hero), mMap(previousPreviousMapInfo)
{
	generateLevel();
}

void GameEngine::generateLevel()
{
	generateMap();
	positionHeroAtStart();
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
	mMap.setEntityOnMap(1, 1, 'H'); //Symbol of hero will be H
}

void  GameEngine::moveHero(string direction)
{
	if (direction != "left" && direction != "right" && direction != "up" && direction != "down")
	{
		cout <<"Invalid direction! No action taken.";
		return;
	}
	int xOldCoordinate = mHero.getXCoordinate();
	int yOldCoordinate = mHero.getYCoordinate();
	
	bool destIsWall;
	if (direction == "left")
	{
		destIsWall = destinationIsWall(xOldCoordinate, yOldCoordinate - 1);
		if (!destIsWall)
		{
			actOnDirection(xOldCoordinate, yOldCoordinate - 1);
			mMap.markCellAsVisited(xOldCoordinate, yOldCoordinate);
		}
		
	}
	else if (direction == "right")
	{
		destIsWall = destinationIsWall(xOldCoordinate, yOldCoordinate +1);
		if (!destIsWall)
		{
			actOnDirection(xOldCoordinate, yOldCoordinate + 1);
			mMap.markCellAsVisited(xOldCoordinate, yOldCoordinate);
		}
	}
	else if (direction == "up")
	{
		destIsWall = destinationIsWall(xOldCoordinate-1, yOldCoordinate);
		if (!destIsWall)
		{
			actOnDirection(xOldCoordinate-1, yOldCoordinate);
			mMap.markCellAsVisited(xOldCoordinate, yOldCoordinate);
		}
	}
	else if (direction == "down")
	{
		destIsWall = destinationIsWall(xOldCoordinate, yOldCoordinate - 1);
		if (!destIsWall)
		{
			actOnDirection(xOldCoordinate+1, yOldCoordinate);
			mMap.markCellAsVisited(xOldCoordinate, yOldCoordinate);
		}
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
		mHero.levelUp();
		generateLevel();
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
		return;
	}
	else if (mHero.getCurrentLevel() == 2)
	{
		mMap = Map(previousMapInfo);
	}
	else
	{
		mMap = Map(previousPreviousMapInfo, previousMapInfo);
		updatePreviousMapInfo(mMap);
	}
}

void GameEngine::actOnDirection(int nextXCoordinate,int nextYCoordinate)
{
	mHero.setCoordinates(nextXCoordinate, nextYCoordinate);
	determineAction(mHero.getXCoordinate(), mHero.getYCoordinate());
	mMap.mGrid.setCellValue(nextXCoordinate, nextYCoordinate, 'H');
	
}

void GameEngine::visualizeMap() const
{
	system("CLS");
	mMap.visualize();
}
