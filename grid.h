#ifndef __GRID_H
#define __GRID_H

#include <vector>
#include "cell.h"

using namespace std;

class Grid
{
	int mRows;
	int mCols;
	Cell** mGrid;

	void _free();
	void copyFrom(const Grid& other);
	void populateGrid();
public:
	Grid() = default;
	Grid(int rows, int cols);
	Grid(const Grid& other);
	~Grid();
	Grid& operator=(const Grid& other);

	int getRows() const;
	int getCols() const;
	const Cell& getCell(int row, int col) const;
	void setCellValue(int row, int col, char value);
	void markCellAsVisited(int row, int col);
	void print() const;

	
	friend ostream& operator<<(ostream& out, const Grid& grid);
	friend istream& operator>>(istream& in, Grid& grid);

};


#endif