#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid(int rows, int cols) :mRows(rows), mCols(cols)
{
	mGrid = new Cell * [mRows];
	for (int i = 0; i < mRows; i++)
	{
		mGrid[i] = new Cell[mCols];
	}
	populateGrid();
}

Grid::Grid(const Grid& other)
{
	copyFrom(other);
}

Grid::~Grid()
{
	_free();
}

Grid& Grid::operator=(const Grid& other)
{
	if (this != &other)
	{
		_free();
		copyFrom(other);
	}
	return *this;
}


int Grid::getRows() const
{
	return mRows;
}

int Grid::getCols() const
{
	return mCols;
}

const Cell& Grid::getCell(int row, int col) const
{
	if (row > mRows || col > mCols || row < 0 || col < 0)
	{
		throw "Out of bounds!";
	}
	return mGrid[row][col];
}

void Grid::setCellValue(int row, int col, char value)
{
	if (row <0 || row >mRows || col <0 || col > mCols)
	{
		throw "Out of bounds!";
	}
	mGrid[row][col].setSymbol(value);
}

void Grid::markCellAsVisited(int row, int col)
{
	if (row <0 || row >mRows || col <0 || col > mCols)
	{
		throw "Out of bounds!";
	}
	mGrid[row][col].markVisited();
}

void Grid::print() const
{
	for (int i = 0; i < mRows; i++)
	{
		for (int j = 0; j < mCols; j++)
		{
			mGrid[i][j].print();
		}
		cout << endl;
	}
}


void Grid::_free()
{
	for (int i = 0; i < mRows; i++)
	{
		delete[] mGrid[i];
	}
	delete[] mGrid;
}

void Grid::copyFrom(const Grid& other)
{
	mRows = other.mRows;
	mCols = other.mCols;

	mGrid = new Cell*[mRows];
	for (int i = 0; i < mRows; i++)
	{
		mGrid[i] = new Cell[mCols];
		for (int j = 0; j < mCols; j++)
		{
			mGrid[i][j] = other.mGrid[i][j];
		}
	}
}

void Grid::populateGrid()
{
	for (int i = 0; i < mRows; i++)
	{
		for (int j = 0; j < mCols; j++)
		{
			bool isBorder = (i == 0 || i == mRows - 1 || j == 0 || j == mCols - 1);
			bool isExit = (i == mRows - 2 && j == mCols - 1);
			if (isBorder && !isExit) // we set question marks, because it is yet unexplored
			{
				setCellValue(i, j, '#');

			}
		}

	}
}





ostream& operator<<(ostream& out, const Grid& grid)
{
	out << grid.mRows << ' ' << grid.mCols <<endl;
	for (int i = 0; i < grid.mRows; i++)
	{
		for (int j = 0; j < grid.mCols; j++)
		{
			out << grid.mGrid[i][j];
		}
		out << endl;
	} 
	return out;
}

istream& operator>>(istream& in, Grid& grid)
{

	if (grid.mRows != 0 && grid.mCols != 0)
	{
		for (int i = 0; i < grid.mRows; i++)
		{
			delete[] grid.mGrid[i];
		}
		delete[] grid.mGrid;
		
	}
	in >> grid.mRows;
	in >> grid.mCols;

	grid.mGrid = new Cell * [grid.mRows];
	for (int i = 0; i < grid.mRows; i++)
	{
		grid.mGrid[i] = new Cell[grid.mCols];
		for (int j = 0; j < grid.mCols; j++)
		{
			in >> grid.mGrid[i][j];
		}
	}
	return in;
}