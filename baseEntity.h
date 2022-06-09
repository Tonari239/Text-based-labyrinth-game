#ifndef __BASE_ENTITY_H
#define __BASE_ENTITY_H

class BaseEntity
{
protected:
	unsigned mXCoordinate;
	unsigned mYCoordinate;
public:
	unsigned getXCoordinate() const;
	unsigned getYCoordinate() const;
	virtual void levelUp()=0;
};


#endif