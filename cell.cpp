#include "cell.h"

Cell::Cell()
{
	mHasBeenVisited = false;
	mSymbol = '?';
}


char Cell::getSymbol() const
{
	return mSymbol;
}

void Cell::setSymbol(char c)
{
	if (c != 'T' && c != '#' && c != '.' && c != 'M' && c != 'H' && c != '?')
	{
		throw "Invalid symbol!";
	}
	mSymbol = c;
}

void Cell::setVisitedStatus(bool status)
{
	mHasBeenVisited = status;
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
	mSymbol = '.'; // we've discovered what's on the map so we put that symbol
}

void Cell::print() const
{
	cout << mSymbol;
}

ostream& operator<<(ostream& out, const Cell& cell)
{
	out << cell.getSymbol();
	return out;
}

istream& operator>>(istream& in, Cell& cell)
{
	in >> cell.mSymbol;
	if (cell.mSymbol == '.')
	{
		cell.mHasBeenVisited = true;
	}
	return in;
}

