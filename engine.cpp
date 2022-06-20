#include "engine.h"
#include "inputFormatter.cpp"



Engine* Engine::mInstance = nullptr;

Engine::Engine(GameEngine engine) : gameEngine(engine)
{

}

Engine* Engine::getEngine(GameEngine engine)
{
	if (mInstance == nullptr)
	{
		mInstance = new Engine(engine);
	}
	return mInstance;
}

void Engine::free()
{
	delete mInstance;
}


bool Engine::checkForBackUpFile(string fileName) const
{
	ifstream file(fileName);
	bool fileExists=false;
	if (file)
	{
		fileExists = true;
	}

	try
	{
		file.close();
	}
	catch (const std::exception&)
	{

	}
	return fileExists;
}

void Engine::enterPassword(char* input, char encryptChar)
{
	char inputChar = '0';
	int counter = 0;
	while (inputChar != '\r')
	{
		inputChar = _getch(); // used with  #include <conio.h>
		if (inputChar == '\b' && counter != 0)
		{
			input[counter] = '\0';
			--counter;
			cout << "\b";
			cout << " "; // idea from https://stackoverflow.com/questions/3745861/how-to-remove-last-character-put-to-stdcout
			cout << "\b";
		}
		else if (inputChar != '\r')
		{
			input[counter] = inputChar;
			std::cout << encryptChar;
			++counter;
		}
	}
	input[counter] = '\0';
	cout << endl;
}

bool Engine::authorize(const char* pass)
{
	bool isAuthorized = false;
	cout << "Enter admin password:\n";
	char input[MAX_LENGTH];
	enterPassword(input, '*');
	if (strcmp(pass, input) != 0)
	{
		cout << "Wrong password! Operation failed\n";
		return isAuthorized;
	}
	isAuthorized = true;
	return isAuthorized;
}

void Engine::printHelp() const
{
	system("CLS");
	cout << "The following commands are supported: " << endl;
	cout << "open <file>             |opens <file> and enables user to make changes to map" << endl;
	cout << "close                   |closes currently opened file" << endl;
	cout << "save                    |saves currently opened file" << endl;
	cout << "saveas <file>           |saves currently opened file in <file>" << endl;
	cout << "help                    |prints this information" << endl;
	cout << "exit                    |exists program" << endl;
	cout << "<direction>             |moves hero in selected direction - \"right\",\"left\",\"up\",\"down\"" << endl;
	cout << "restore                 |restores level from previous session" << endl;
	cout << "visualize               |visualizes current map" << endl;
	cout << "generate                |generates new map after user enters admin password" << endl;
}

void Engine::run()
{
	
	string command;
	cin.ignore();
	gameEngine.visualizeMap();
	cout << endl;
	bool backUpFileExists = checkForBackUpFile("backup.txt");
	if (backUpFileExists)
	{
		cout << "Enter \"restore\" to restore previous session." <<endl;
	}
	
	cout << "Enter \"help\" to see available commands." << endl;
	while (true)
	{
		
		cout << endl;
		getline(std::cin, command);
		vector<string> splitCommands = InputFormatter::splitStringByDelimiter(command, ' ');
		if (splitCommands[0] == "help")
		{
			printHelp();
		}
		else if (splitCommands[0] == "open")
		{
			if (splitCommands.size() == 1)
			{
				cout << "No file name specified!" << endl;
			}
			else
			{
				gameEngine.mGameFileManager.open(splitCommands[1], gameEngine.mHero, gameEngine.mMap);
			}
		}
		else if (splitCommands[0] == "close")
		{
			gameEngine.mGameFileManager.close();
		}
		else if (splitCommands[0] == "save")
		{
			gameEngine.mGameFileManager.save(gameEngine.mHero,gameEngine.mMap);
		}
		else if (splitCommands[0] == "saveas")
		{
			if (splitCommands.size() == 1)
			{
				cout << "No file name specified!" << endl;
			}
			else
			{
				gameEngine.mGameFileManager.saveAs(splitCommands[1], gameEngine.mHero, gameEngine.mMap);
			}
			
		}
		else if (splitCommands[0] == "exit")
		{
			if (gameEngine.mGameFileManager.getUnsavedChanges())
			{
				cout << "Would you like to save unsaved changes? y/n" << endl;
				char c;
				do
				{
					cin >> c;
				} while (c!='y' && c!='n');
				if (c == 'y')
				{
					gameEngine.mGameFileManager.save(gameEngine.mHero, gameEngine.mMap);
				}
				else if (c == 'n')
				{
					gameEngine.mGameFileManager.close();
				}

			}
			throw -1;
		}
		else if (splitCommands[0] == "left" || splitCommands[0] == "right"|| splitCommands[0] == "up" || splitCommands[0] == "down")
		{
			try
			{
				gameEngine.moveHero(splitCommands[0]);
			}
			catch (int)
			{
				break;
			}
			gameEngine.visualizeMap();
			cout << endl;

			gameEngine.mGameFileManager.setUnsavedChanges(true);
			gameEngine.saveSession("backup.txt");
		}
		else if (splitCommands[0] == "restore")
		{
			//every move will be stored in a backup file
			if (backUpFileExists)
			{
				gameEngine.restoreSession("backup.txt");
				gameEngine.visualizeMap();
			}
			else
			{
				cout << "No  backup file found!" << endl;
			}
			
		}
		else if (splitCommands[0] == "visualize")
		{
			gameEngine.visualizeMap();
		}
		else if (splitCommands[0] == "generate")
		{
			bool isAuthorized = authorize(ADMIN_PASSWORD);
			if (isAuthorized)
			{
				cout << "Generating new level..." << endl;
				gameEngine.generateLevel();
				cout << "Done! Enter \"visualize\" to see new map." << endl;
			}
		}
		else if (splitCommands[0] == "" || splitCommands[0] == " ")
		{

		}
		else
		{
			cout << "Invalid command!" << endl;
		}

		
	}
}
