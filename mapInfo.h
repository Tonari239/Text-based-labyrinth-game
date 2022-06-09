#ifndef __MAPINFO_H
#define __MAPINFO_H

struct MapInfo
{
	int mLevel;
	int mMonstersCount;
	int mTreasuresCount;
	int mRows;
	int mCols;

	MapInfo(int level, int monstersCount, int treasuresCount, int rows, int cols);
};

#endif