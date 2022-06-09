#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H

#include "hero.h"
#include "map.h"
class GameEngine
{
	Hero mHero;
	Map mMap;

	static MapInfo previousMapInfo;
	static MapInfo previousPreviousMapInfo;

	void positionHeroAtStart();
public:
	GameEngine(const Hero& hero);
	void moveHero();
	void generateLevel();
	static void updatePreviousMapInfo(Map currentMap);

};

#endif