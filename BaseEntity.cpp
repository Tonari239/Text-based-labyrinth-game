#include "baseEntity.h"

BaseEntity::BaseEntity(int x, int y) :mXCoordinate(x), mYCoordinate(y)
{

}


unsigned BaseEntity::getXCoordinate() const
{
	return mXCoordinate;
}

unsigned BaseEntity::getYCoordinate() const
{
	return mYCoordinate;
}

