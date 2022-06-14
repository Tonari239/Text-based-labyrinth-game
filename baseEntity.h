#ifndef __BASE_ENTITY_H
#define __BASE_ENTITY_H

class BaseEntity
{
protected:
	int mXCoordinate;
	int mYCoordinate;
public:
	BaseEntity(int x = -1, int y = -1);
	unsigned getXCoordinate() const;
	unsigned getYCoordinate() const;
	virtual void levelUp()=0;
};


#endif