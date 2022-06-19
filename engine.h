#ifndef __ENGINE_H
#define __ENGINE_H

#include "gameEngine.h"
#include "GameFileManager.h"

class Engine
{
	GameEngine gameEngine;

	void printHelp() const;
	void instantiateGameEngine();
public:
	Engine(GameEngine gameEngine);
	
	void run();
};

#endif