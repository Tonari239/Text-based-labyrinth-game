#include "baseEntity.h"


unsigned BaseEntity::getXCoordinate() const
{
	return mXCoordinate;
}

unsigned BaseEntity::getYCoordinate() const
{
	return mYCoordinate;
}

BaseEntity::BaseEntity(int x, int y) :mXCoordinate(x),mYCoordinate(y)
{

}