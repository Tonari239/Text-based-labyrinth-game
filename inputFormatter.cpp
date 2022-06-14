#include "inputFormatter.h"

vector<string> InputFormatter::splitStringByDelimiter(string input, char delimiter)
{
	int stringLength = input.length();
	int count = getDelimiterCount(input, delimiter);
	vector<string> result;
	int delimiterPosition = 0;
	for (int i = 0; i < count; i++)
	{
		delimiterPosition = input.find(delimiter);
		result.push_back(input.substr(0, delimiterPosition));
		//skipping over the delimiter
		input.erase(0, delimiterPosition + 1);
	}
	result.push_back(input.substr(0, stringLength));
	return result;


}

int InputFormatter::getDelimiterCount(string input, char delimiter)
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