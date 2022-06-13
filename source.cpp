#include <iostream>
using namespace std;

#include "gameEngine.h"
#include <string>

int getDelimiterCount(string input,char delimiter)
{
	int length = input.length();
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (input[i] == delimiter)
		{
			++counter;
		}
	}
	return counter;
}

vector<string> splitStringByDelimiter(string input,char delimiter)
{
	int stringLength = input.length();
	int count = getDelimiterCount(input, delimiter);
	vector<string> result;
	int delimiterPosition = 0;
	for (int i = 0; i < count; i++)
	{
		delimiterPosition= input.find(delimiter);
		result.push_back(input.substr(0, delimiterPosition));
		//skipping over the delimiter
		input.erase(0, delimiterPosition + 1);
	}
	result.push_back(input.substr(0, stringLength));
	return result;
	
	
}

int main()
{
	int raceInput=0;
	cout << "Welcome! Enter your hero's race:\n1-Human 2-Mage 3-Warrior\n";
	cin >> raceInput;
	while (raceInput != 1 && raceInput != 2 && raceInput != 3)
	{
		cout << "Invalid input! Please try again." << endl;
		cin >> raceInput;
	}
	raceInput -= 1;
	Hero hero((Race)raceInput);
	system("CLS"); // cleans console


	GameEngine gameEngine(hero); // initializing the game engine

	string command;
	cout << "For list of commands, enter \"help\"." << endl;
	while (true)
	{
		getline(std::cin, command);
		vector<string> splitCommands = splitStringByDelimiter(command, ' ');
		if (splitCommands[0] == "help")
		{
			
		}
		else if (splitCommands[0] == "open")
		{

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
	}

}