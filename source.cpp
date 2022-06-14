#include <iostream>
using namespace std;

#include "gameEngine.h"
#include <string>
#include "fileManager.h"

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
	Hero hero((Race)1); 
	GameEngine gameEngine(hero);
	
	string command;
	while (true)
	{
		gameEngine.visualizeMap();
		cout << endl;
		cin >> command;
		try
		{
			gameEngine.moveHero(command);
		}
		catch (int)
		{
			break;
		}
		
	}
}