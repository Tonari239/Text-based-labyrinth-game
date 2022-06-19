#include "engine.h"
#include "inputFormatter.cpp"


Engine::Engine(GameEngine engine) : gameEngine(engine)
{

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
}

void Engine::run()
{
	
	string command;
	cin.ignore();
	gameEngine.visualizeMap();
	cout << endl;
	cout << "Enter help to see available commands." << endl;
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
			gameEngine.mGameFileManager.open(splitCommands[1],gameEngine.mHero,gameEngine.mMap);
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
			gameEngine.mGameFileManager.saveAs(splitCommands[1],gameEngine.mHero,gameEngine.mMap);
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
			gameEngine.restoreSession("backup.txt");
		}
		else
		{
			cout << "Invalid command!" << endl;
		}

		
	}
}
