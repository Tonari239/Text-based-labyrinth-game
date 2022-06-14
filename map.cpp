#include "Map.h"
#include <time.h>

void Map::positionEntities()
{
	positionTreasures(mTreasuresCount);
	positionMonsters(mMonstersCount);
}

Map::Map(int level, int monstersCount, int treasuresCount,int rows,int cols) 
	:mMonstersCount(monstersCount),mTreasuresCount(treasuresCount),mLevel(level), mGrid(rows,cols)
{
	positionEntities();
}

Map::Map(MapInfo initialMap) : mMonstersCount(initialMap.mMonstersCount),
	mTreasuresCount(initialMap.mTreasuresCount),
	mLevel(initialMap.mLevel), mGrid(initialMap.mRows,
		initialMap.mCols)
{
	positionEntities();
}


Map::Map(MapInfo previousPreviousMap, MapInfo previousMap)
	: mMonstersCount(previousMap.mMonstersCount + previousPreviousMap.mMonstersCount),
	mTreasuresCount(previousMap.mTreasuresCount + previousPreviousMap.mMonstersCount),
	mLevel(previousMap.mLevel+1),mGrid((previousMap.mRows + previousPreviousMap.mRows),
		(previousMap.mCols + previousPreviousMap.mCols))
{
	positionEntities();
}


void Map::positionTreasures(int count)
{
	int* rows = new int[count]; // saving the coordinates of treasures as x,y pair
	int* columns = new int[count];
	for (int i = count; i > 0; i--)
	{
		int row = 0;
		int column = 0;

		do
		{ 
			srand(time(NULL));
			row = 1 + rand() % (mGrid.getRows() - 1);
			column = 1 + rand() % (mGrid.getCols() - 1);
		} while (mGrid.getCell(row, column).isOccupied());

		int currentIndex = mTreasuresCount - count;
		rows[currentIndex] = row;
		columns[currentIndex] = column;
		setEntityOnMap(row, column, 'T');
		mTreasures.addTreasure(*(GameUtilities::generateTreasure(row, column, mLevel)));
		
	}
	
	delete[] rows;
	delete[] columns;
}

void Map::positionMonsters(int count)
{
	int* rows = new int[count];
	int* columns = new int[count];
	for (int i = count; i > 0; i--)
	{
		{
			int row = 0;
			int column = 0;

			do
			{
				srand(time(NULL));
				row = 1 + rand() % (mGrid.getRows() - 1);
				column = 1 + rand() % (mGrid.getCols() - 1);
			} while (mGrid.getCell(row, column).isOccupied());

			int currentIndex = mMonstersCount - i;
			rows[currentIndex] = row;
			columns[currentIndex] = column;
			setEntityOnMap(row, column, 'M');
			Monster monster(row, column, mLevel);
			mMonsters.push_back(monster);
		}
	}
	delete[] rows;
	delete[] columns;
}

int Map::getLevel() const
{
	return mLevel;
}

int Map::getMonstersCount() const
{
	return mMonstersCount;
}

int Map::getTreasuresCount() const
{
	return mTreasuresCount;
}

int Map::getRows() const
{
	return mGrid.getRows();
}

int Map::getCols() const
{
	return mGrid.getCols();
}

void Map::setEntityOnMap(int x, int y, char c)
{
	mGrid.setCellValue(x, y, c);
}


void Map::markCellAsVisited(int x, int y)
{
	mGrid.markCellAsVisited(x, y);
}

const Cell& Map::getCell(int x, int y) const
{
	return mGrid.getCell(x, y);
}

int Map::getMonsterIndexByCoordinates(int x, int y) const
{
	if (x<0 || y < 0 || x >mGrid.getRows() || y > mGrid.getCols())
	{
		throw "Out of bounds!";
	}
	for (int i = 0; i < mMonstersCount; i++)
	{
		if (mMonsters[i].getXCoordinate() == x && mMonsters[i].getYCoordinate() == y)
		{
			return i;
		}
	}
	return -1;
}

int Map::getTreasureIndexByCoordinates(int x,int y) const
{
	if (x<0 || y < 0 || x >mGrid.getRows() || y > mGrid.getCols())
	{
		throw "Out of bounds!";
	}
	for (int i = 0; i < mMonstersCount; i++)
	{
		if (mTreasures[i].getXCoordinate() == x && mTreasures[i].getYCoordinate() == y)
		{
			return i;
		}
	}
	return -1;
}

void  Map::visualize() const
{
	mGrid.print();
}