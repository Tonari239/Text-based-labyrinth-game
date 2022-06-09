#ifndef __CELL_H
#define __CELL_H

class Cell
{
	/*int mXCoordinate;
	int mYCoordinate;*/
	char mSymbol; // border symbol by default
	bool mHasBeenVisited;

public:
	Cell();
	bool isOccupied() const;
	bool hasBeenVisited() const;
	void markVisited();
	void setSymbol(char c);
	void print() const;
};

#endif