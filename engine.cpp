#include "engine.h"
#include <string>
#include "inputFormatter.h"

Engine::Engine(GameEngine engine) : gameEngine(engine)
{

}

void Engine::printHelp() const
{
	system("CLS");
	cout << "The following commands are supported: " << endl;
	cout << "open <file>              opens <file> and enabled user to make changes to map" << endl;
	cout << "close                    closes currently opened file" << endl;
	cout << "save                     saves currently opened file" << endl;
	cout << "saveas <file>           saves currently opened file in <file>" << endl;
	cout << "help                    prints this information" << endl;
	cout << "exit                    exists program" << endl;
	cout << "move <direction>        moves hero in selected direction - right,left,up,down" << endl;
}

void Engine::run()
{
	
	string command;
	while (true)
	{
		getline(std::cin, command);
		vector<string> splitCommands = InputFormatter::splitStringByDelimiter(command, ' ');
		if (splitCommands[0] == "help")
		{
			printHelp();
		}
		else if (splitCommands[0] == "open")
		{
			manager.open(splitCommands[1]);
		}
		else if (splitCommands[0] == "close")
		{

		}
		else if (splitCommands[0] == "save")
		{

		}
		else if (splitCommands[0] == "saveas")
		{

		}
		else if (splitCommands[0] == "exit")
		{
			throw -1;
		}
		else if (splitCommands[0] == "left" || splitCommands[0] == "right"|| splitCommands[0] == "up" || splitCommands[0] == "down")
		{
			gameEngine.visualizeMap();
			cout << endl;
			try
			{
				gameEngine.moveHero(splitCommands[0]);
			}
			catch (int)
			{
				break;
			}
		}
		else
		{
			cout << "Invalid command!" << endl;
		}

		
	}
}
