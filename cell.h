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
	char getSymbol() const;
	void setSymbol(char c);
	void setVisitedStatus(bool status);

	bool isOccupied() const;
	bool hasBeenVisited() const;
	void markVisited();
	
	void print() const;
	
	

	friend ostream& operator<<(ostream& out, const Cell& cell);
	friend istream& operator>>(istream& out, Cell& cell);
};

#endif