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
	Map(MapInfo initialMap);
	Map(MapInfo previousPreviousMap, MapInfo previousMap);
	Map(int level, int monstersCount, int treasuresCount, int rows, int cols);

	void positionTreasures(int count);
	void positionMonsters(int count);

	int getLevel() const;
	int getMonstersCount() const;
	int getTreasuresCount() const;
	int getRows() const;
	int getCols() const;
	const Cell& getCell(int x, int y) const;
	int getMonsterIndexByCoordinates(int x, int y) const;
	int getTreasureIndexByCoordinates(int x, int y) const;

	void setEntityOnMap(int x,int y,char c);

	void markCellAsVisited(int x, int y);
	void visualize() const;
	

	friend ostream& operator<<(ostream& out, const Map& map);
	friend istream& operator>>(istream& in, Map& map);

	friend class GameEngine;
};

#endif