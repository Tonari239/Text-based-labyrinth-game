#ifndef __TREASURE_H
#define __TREASURE_H

#include "baseEntity.h"

class Treasure : public BaseEntity
{
	double mPercentStat;
public:
	Treasure(int level=1, double percentStat=10);
	virtual ~Treasure() = default;
	double getPercentStat() const;
	virtual Treasure* clone() const;
	void levelUp() override;
};

#endif