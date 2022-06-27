#include "gameEngine.h"
#include <string>


GameEngine::GameEngine(const Hero& hero) :previousPreviousMapInfo(1, 2, 2, 10, 10), previousMapInfo(2, 3, 2, 15, 10), mHero(hero), mMap(previousPreviousMapInfo), filesCount(0)
{
	generateLevel();
}

void GameEngine::generateLevel()
{
	generateMap();
	positionHeroAtStart();
	++filesCount;
	string fileName = "gameFile" +std::to_string(filesCount) + (string)".txt";
	saveSession(fileName);
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
	mHero.setCoordinates(xCoordinate, yCoordinate);
	mMap.setEntityOnMap(xCoordinate, yCoordinate, 'H'); //Symbol of hero will be H
}

void  GameEngine::moveHero(string direction)
{
	int initialLevel = mHero.getCurrentLevel();
	bool isNotLevelledUp = true;
	if (direction != "left" && direction != "right" && direction != "up" && direction != "down")
	{
		cout <<"Invalid direction! No action taken.";
		return;
	}
	int oldXCoordinate = mHero.getXCoordinate();
	int oldYCoordinate = mHero.getYCoordinate();
	if (direction == "left")
	{
		actOnDirection(oldXCoordinate, oldYCoordinate, oldXCoordinate, oldYCoordinate - 1, initialLevel);
	}
	else if (direction == "right")
	{
		actOnDirection(oldXCoordinate, oldYCoordinate, oldXCoordinate, oldYCoordinate +1, initialLevel);
	}
	else if (direction == "up")
	{
		actOnDirection(oldXCoordinate, oldYCoordinate, oldXCoordinate - 1, oldYCoordinate, initialLevel);
	}
	else if (direction == "down")
	{
		actOnDirection(oldXCoordinate, oldYCoordinate, oldXCoordinate + 1, oldYCoordinate, initialLevel);
	} 
}

void GameEngine::actOnDirection(int oldXCoordinate, int oldYCoordinate, int newXCoordinate, int newYCoordinate,int initialLevel)
{
	bool destIsWall = destinationIsWall(newXCoordinate,newYCoordinate);
	if (!destIsWall)
	{
		act(newXCoordinate,newYCoordinate);
		bool isNotLevelledUp = mHero.getCurrentLevel() == initialLevel;
		if (isNotLevelledUp)
		{
			mMap.markCellAsVisited(oldXCoordinate, oldYCoordinate);
		}
	}
}

void GameEngine::determineActOnDirection(int xCoordinate,int yCoordinate)
{
	if (destinationIsTreasure(xCoordinate, yCoordinate))
	{
		system("CLS");
		collectTreasure(x,y);
	}
	else if (destinationIsMonster(xCoordinate, yCoordinate))
	{
		try
		{
			int monsterIndex = mMap.getMonsterIndexByCoordinates(xCoordinate, yCoordinate);
			bool fightResult = mHero.battle(mMap.mMonsters[monsterIndex]);
			if (fightResult) // 1 if hero wins
			{
				mMap.mMonsters.erase(mMap.mMonsters.begin() + monsterIndex);
				--mMap.mMonstersCount;
				mMap.setEntityOnMap(xCoordinate, yCoordinate, '.'); // monster is no longer on cell
			}
		}
		catch (int)
		{
			throw - 1; // will catch this in main and end program;
		}
		
	}
	if (destinationIsExit(xCoordinate, yCoordinate))
	{
		mHero.levelUp();
		generateLevel();
	}
}

void GameEngine::collectTreasure(int xCoordinate, int yCoordinate)
{
	int treasureIndex = mMap.getTreasureIndexByCoordinates(xCoordinate, yCoordinate);
	mHero.takeTreasure(*mMap.mTreasures.getAt(treasureIndex));
	mMap.mTreasures.removeIndex(treasureIndex);
}

bool GameEngine::destinationIsWall(int xCoordinate, int yCoordinate) const
{
	return mMap.getCell(xCoordinate, yCoordinate).getSymbol() == '#';
}

bool GameEngine::destinationIsTreasure(int xCoordinate, int yCoordinate) const
{
	return mMap.getCell(xCoordinate, yCoordinate).getSymbol() == 'T';
}

bool GameEngine::destinationIsMonster(int xCoordinate, int yCoordinate) const
{
	return mMap.getCell(xCoordinate, yCoordinate).getSymbol() == 'M';
}

bool GameEngine::destinationIsExit(int xCoordinate, int yCoordinate) const
{
	return xCoordinate == mMap.getRows() - 2 && yCoordinate == mMap.getCols() - 1;
}

void GameEngine::generateMap()
{
	int level = mHero.getCurrentLevel();
	if (level == 1)
	{
		mMap = Map(previousPreviousMapInfo);
	}
	else if (level == 2)
	{
		mMap = Map(previousMapInfo);
	}
	else
	{
		mMap = Map(previousPreviousMapInfo, previousMapInfo);
		updatePreviousMapInfo(mMap);
	}
}

void GameEngine::act(int nextXCoordinate,int nextYCoordinate)
{
	int currentLevel = mHero.getCurrentLevel();
	mHero.setCoordinates(nextXCoordinate, nextYCoordinate);
	determineActOnDirection(mHero.getXCoordinate(), mHero.getYCoordinate());
	int newLevel = mHero.getCurrentLevel();
	if (currentLevel == newLevel)
	{
		mMap.mGrid.setCellValue(nextXCoordinate, nextYCoordinate, 'H');
		int manaPointRestoredPerMove = 1;
		mHero.restoreManaPoint(manaPointRestoredPerMove);
	}
}

void GameEngine::visualizeMap() const
{
	system("CLS");
	mMap.visualize();

	cout << endl;
	cout << endl;
	cout << "Health: " << mHero.getHealth() << endl;
	cout << "Mana: " << mHero.getMana() << endl;

}

void GameEngine::restoreSession(string backUpFile)
{
	ifstream file(backUpFile);
	file >> mHero;
	file >> mMap;
	if (file)
	{
		file.close();
	}
}

void GameEngine::saveSession(string backUpFile)
{
	ofstream file(backUpFile);
	file << mHero;
	file << mMap;
	if (file)
	{
		file.close();
	}
	file.close();
}

