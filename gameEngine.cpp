#include "gameEngine.h"


MapInfo GameEngine::previousPreviousMapInfo = {1,2,2,10,10}; // first base level
MapInfo GameEngine::previousMapInfo = {2,3,2,15,10}; // second base level


GameEngine::GameEngine(const Hero& hero) : mHero(hero)
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

void GameEngine::generateLevel()
{
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
	mMap.setEntityOnMap(1, 1, '@');
}

void  GameEngine::moveHero()
{

}