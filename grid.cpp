#include "grid.h"
#include <iostream>

using namespace std;

void Grid::setCellValue(int row, int col, char value)
{
	mGrid[row][col].setSymbol(value);
}

const Cell& Grid::getCell(int row, int col) const
{
	return mGrid[row][col];
}

void Grid::populateGrid()
{
	for (int i = 0; i < mRows; i++)
	{
		for (int j = 0; j < mCols; j++)
		{
			bool isBorder = (i == 0 || i == mRows - 1 || j == 0 || j == mCols - 1);
			bool isExit = (i == mRows - 2 && j == mCols - 1);
			if (!isBorder || isExit) // we set question marks, because it is yet unexplored
			{
				setCellValue(i, j, '?'); 
			}
		}
	}
}

Grid::Grid(int rows, int cols) :mRows(rows), mCols(cols)
{
	mGrid = new Cell * [mRows];
	for (int i = 0; i < mRows; i++)
	{
		mGrid[i] = new Cell[mCols];
	}
	populateGrid();
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

void Grid::free()
{
	for (int i = 0; i < mRows; i++)
	{
		delete[] mGrid[i];
	}
	delete[] mGrid;
}

void Grid::copyFrom(const Grid& other)
{
	mRows = other.getRows();
	mCols = other.getCols();

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

int Grid::getRows() const
{
	return mRows;
}

int Grid::getCols() const
{
	return mCols;
}



Grid::~Grid()
{
	free();
}

Grid::Grid(const Grid& other)
{
	copyFrom(other);
}

Grid& Grid::operator=(const Grid& other)
{
	if (this != &other)
	{
		//free();
		copyFrom(other);
	}
	return *this;
}

//Grid::Grid(Grid&& other) noexcept
//{
//	mRows = other.getRows();
//	mCols = other.getCols();
//	for (int i = 0; i < mRows; i++)
//	{
//		mGrid[i] = other.mGrid[i];
//		other.mGrid[i] = nullptr;
//	}
//	mGrid = other.mGrid;
//	other.mGrid = nullptr;
//}

//Grid& Grid::operator=(Grid&& other) noexcept
//{
//	if (this != &other)
//	{
//		free();
//		mRows = other.getRows();
//		mCols = other.getCols();
//		for (int i = 0; i < mRows; i++)
//		{
//			mGrid[i] = other.mGrid[i];
//			other.mGrid[i] = nullptr;
//		}
//		mGrid = other.mGrid;
//		other.mGrid = nullptr;
//	}
//	return *this;
//}

void Grid::markCellAsVisited(int row, int col)
{
	mGrid[row][col].markVisited();
}

ostream& operator<<(ostream& out, const Grid& grid)
{
	out << grid.mRows << " " << grid.mCols;
	for (int i = 0; i < grid.mRows; i++)
	{
		for (int j = 0; j < grid.mCols; j++)
		{
			out << grid.mGrid[i][j] << endl;
		}
	} 
	return out;
}

istream& operator>>(istream& in, Grid& grid)
{
	in >> grid.mRows;
	in >> grid.mCols;
	for (int i = 0; i < grid.mRows; i++)
	{
		for (int j = 0; j < grid.mCols; j++)
		{
			in >> grid.mGrid[i][j];
		}
	}
	return in;
}