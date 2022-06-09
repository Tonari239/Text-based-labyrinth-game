#include <iostream>


#include "cell.h"
using namespace std;

Cell::Cell()
{
	mHasBeenVisited = false;
	mSymbol = '#';
}


bool Cell::isOccupied() const
{
	return (mSymbol != '.' && mSymbol!='?');
}

bool Cell::hasBeenVisited() const
{
	return mHasBeenVisited;
}

void Cell::markVisited()
{
	mHasBeenVisited = true;
}

void Cell::setSymbol(char c)
{
	if (c != 'T' && c != '#' && c != '.' && c != 'M' && c != '@' && c!='?')
	{
		throw "Invalid symbol!";
	}
	mSymbol = c;
}

void Cell::print() const
{
	cout << mSymbol;
}