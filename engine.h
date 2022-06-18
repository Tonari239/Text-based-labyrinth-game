#ifndef __ENGINE_H
#define __ENGINE_H

#include "gameEngine.h"
#include "fileManager.h"

class Engine
{
	GameEngine gameEngine;
	FileManager manager;

	void printHelp() const;
	void instantiateGameEngine();
public:
	Engine(GameEngine gameEngine);
	void run();
};

#endif