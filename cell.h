#ifndef __CELL_H
#define __CELL_H

#include <iostream>
using namespace std;
class Cell
{
	char mSymbol; // border symbol by default
	bool mHasBeenVisited;

public:
	Cell();
	bool isOccupied() const;
	bool hasBeenVisited() const;
	void markVisited();
	void setSymbol(char c);
	void print() const;
	char getSymbol() const;
	void setVisitedStatus(bool status);

	friend ostream& operator<<(ostream& out, const Cell& cell);
	friend istream& operator>>(istream& out, Cell& cell);
};

#endif