#ifndef __MAP_H
#define __MAP_H

#include "grid.h"
#include "treasureContainer.h"
#include "monster.h"
#include "mapInfo.h"
#include "gameUtilities.h"
class Map
{
	
	int mLevel;
	int mMonstersCount;
	int mTreasuresCount;
	TreasureContainer mTreasures;
	Grid mGrid;
	vector<Monster> mMonsters;

	void positionEntities();
public:
	Map() = default;
	Map(MapInfo initialMap);
	Map(MapInfo previousMap, MapInfo previousPreviousMap);
	Map(int monstersCount, int treasuresCount, int level,int rows, int cols);

	void positionTreasures(int count);
	void positionMonsters(int count);

	int getLevel() const;
	int getMonstersCount() const;
	int getTreasuresCount() const;
	int getRows() const;
	int getCols() const;
	void setEntityOnMap(int x,int y,char c);
	void markCellAsVisited(int x, int y);
	Grid& getGrid();

};

#endif