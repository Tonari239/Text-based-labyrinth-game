#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H
#include "GameFileManager.h"

class GameEngine
{
	Hero mHero;
	
	int filesCount;

	//format for map info:  <level> <monsters count> <treasures count> <rows> <columns>
	MapInfo previousPreviousMapInfo; //  first base level
	MapInfo previousMapInfo; // second base level
	Map mMap;
	

	void positionHeroAtStart();
	void generateMap();
	void collectTreasure(int xCoordinate, int yCoordinate);
	void determineActOnDirection(int xCoordinate,int yCoordinate);
	bool destinationIsWall(int xCoordinate,int yCoordinate) const;
	bool destinationIsTreasure(int xCoordinate,int yCoordinate) const;
	bool destinationIsMonster(int xCoordinate,int yCoordinate) const;
	bool destinationIsExit(int xCoordinate,int yCoordinate) const;
	void act(int xCoordinate, int yCoordinate);

public:
	GameFileManager mGameFileManager;

	GameEngine(const Hero& hero);
	void moveHero(string direction);
	void generateLevel();
	void updatePreviousMapInfo(Map currentMap);
	void visualizeMap() const;
	void actOnDirection(int oldXCorodinate, int oldYCorodinate, int newXCoordinate, int newYCoordinate,int initialLevel);
	
	void restoreSession(string backUpFile);
	void saveSession(string backUpFile);

	friend class Engine;
};

#endif