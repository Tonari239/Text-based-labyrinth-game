#ifndef __ENGINE_H
#define __ENGINE_H

#include "gameEngine.h"
#include "GameFileManager.h"
#include <conio.h>
#define MAX_LENGTH 1024
#define ADMIN_PASSWORD "123"

class Engine
{
	GameEngine gameEngine;


	void enterPassword(char* input, char encryptChar);
	bool authorize(const char* pass);
	void printHelp() const;
	bool checkForBackUpFile(string fileName) const;
public:
	Engine(GameEngine gameEngine);
	
	void run();
};

#endif