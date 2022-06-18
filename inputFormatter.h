#ifndef __INPUT_FORMATTER_H
#define __INPUT_FORMATTER_H

#include <string>
#include <vector>

using namespace std;
class InputFormatter
{
	static int getDelimiterCount(string input, char delimiter);
public:
	static vector<string> splitStringByDelimiter(string input, char delimiter);
};

#endif