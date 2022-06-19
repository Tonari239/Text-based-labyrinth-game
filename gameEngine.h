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
	void collectTreasure(int x, int y);
	void determineactOnDirectionion(int x,int y);
	bool destinationIsWall(int x,int y) const;
	bool destinationIsTreasure(int x,int y) const;
	bool destinationIsMonster(int x,int y) const;
	bool destinationIsExit(int x,int y) const;
	void act(int x, int y);

public:
	GameFileManager mGameFileManager;

	GameEngine(const Hero& hero);
	void moveHero(string direction);
	void generateLevel();
	void updatePreviousMapInfo(Map currentMap);
	void visualizeMap() const;
	void actOnDirection(int xOldCoordinate, int yOldCorodinate, int xNewCoordinate, int yNewCoordinate,int initialLevel);
	
	void restoreSession(string backUpFile);
	void saveSession(string backUpFile);

	friend class Engine;
};

#endif