#include "utilities.h"

#include <iostream>
using namespace std;

int Utilities::generateRandom()
{
	srand(time(NULL));
	int start = rand() % 2 ;
	return start;
}