#include "Map.h"
#include <time.h>

void Map::positionEntities()
{
	positionTreasures(mTreasuresCount);
	positionMonsters(mMonstersCount);
}

Map::Map(int monstersCount, int treasuresCount, int level,int rows,int cols) 
	:mMonstersCount(monstersCount),mTreasuresCount(treasuresCount),mLevel(level), mGrid(rows,cols)
{
	
}

Map::Map(MapInfo initialMap) : mMonstersCount(initialMap.mMonstersCount),
	mTreasuresCount(initialMap.mTreasuresCount),
	mLevel(initialMap.mLevel), mGrid(initialMap.mRows,
		initialMap.mCols)
{

}


Map::Map(MapInfo previousMap, MapInfo previousPreviousMap) 
	: mMonstersCount(previousMap.mMonstersCount + previousPreviousMap.mMonstersCount),
	mTreasuresCount(previousMap.mTreasuresCount + previousPreviousMap.mMonstersCount),
	mLevel(previousMap.mLevel+1), mGrid(previousMap.mRows + previousPreviousMap.mRows,
		previousMap.mCols + previousPreviousMap.mCols)
{

}

void Map::positionTreasures(int count)
{
	int* rows = new int[count];
	int* columns = new int[count];
	while (count != 0)
	{
		int row=0;
		int column=0;

		do 
		{
			srand(time(NULL));
			row = rand() % mGrid.getRows();
			column = rand() % mGrid.getCols();
		} while (mGrid.getCell(row, column).isOccupied());

		int currentIndex = mTreasuresCount - count;
		rows[currentIndex] = row;
		columns[currentIndex] = column;
		mGrid.setCellValue(row, column, 'T');
		Treasure treasure = GameUtilities::generateTreasure(mLevel);
		mTreasures.addTreasure(treasure);
		--count;
	}
	delete[] rows;
	delete[] columns;
}

void Map::positionMonsters(int count)
{
	int* rows = new int[count];
	int* columns = new int[count];
	while (count != 0)
	{
		int row = 0;
		int column = 0;

		do
		{
			srand(time(NULL));
			row = rand() % mGrid.getRows();
			column = rand() % mGrid.getCols();
		} while (mGrid.getCell(row, column).isOccupied());

		int currentIndex = mMonstersCount - count;
		rows[currentIndex] = row;
		columns[currentIndex] = column;
		mGrid.setCellValue(row, column, 'M');
		Monster monster(mLevel);
		mMonsters.push_back(monster);
		--count;
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