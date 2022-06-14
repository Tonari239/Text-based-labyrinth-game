#include "treasureContainer.h"

void TreasureContainer::copyFrom(const TreasureContainer& other)
{
	mCount = other.mCount;
	mCapacity = other.mCapacity;
	mData = new Treasure*[mCapacity];
	for (int i = 0; i < mCount; i++)
	{
		mData[i]= other.mData[i]->clone();
	}
}

void TreasureContainer::free()
{
	for (int i = 0; i < mCount; i++)
	{
		delete mData[i];
	}
	delete[] mData;
}



void TreasureContainer::resizeAccordingly()
{
	if (mCount >= mCapacity * 3 / 4)
	{
		resize(2);
	}
	else if (mCount <= mCapacity * 1 / 4)
	{
		resize(1.0/ 2);
	}
}

void TreasureContainer::resize(double multiplier)
{
	mCapacity *= multiplier;
	Treasure** temp = new Treasure * [mCapacity];
	for (int i = 0; i < mCount; i++)
	{
		temp[i] = mData[i];
	}
	delete[] mData; // tui go check-ni just in case
	mData = temp;
}



TreasureContainer::TreasureContainer(int capacity) :mCapacity(capacity)
{
	mCount = 0;
	mData = new Treasure * [mCapacity];
}

TreasureContainer::TreasureContainer(const TreasureContainer& other)
{
	copyFrom(other);
}

TreasureContainer::~TreasureContainer()
{
	free();
}

TreasureContainer& TreasureContainer::operator=(const TreasureContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}




void TreasureContainer::addTreasure(const Treasure& T)
{
	resizeAccordingly();
	mData[mCount++] = T.clone();
}



void TreasureContainer::removeIndex(int index)
{
	if (index<0 || index>mCount)
	{
		throw "Index out of bounds!";
	}
	if (mCount == 0)
	{
		throw "Collection is empty!";
	}
	delete mData[index];
	for (int i = index; i < mCount; i++)
	{
		mData[i] = mData[i + 1];
	}
	--mCount;
	resizeAccordingly();
}


const Treasure* TreasureContainer::getAt(int index) const
{
	if (index < 0 || index>mCount)
	{
		throw "Index out of bound!";
	}
	return (mData[index]);
}


Treasure& TreasureContainer::operator[](int index)
{
	if (index < 0 || index>mCount)
	{
		throw "Index out of bound!";
	}
	return *mData[index];
}


Treasure TreasureContainer::operator[](int index) const
{
	return *getAt(index);
}

int TreasureContainer::getCount() const
{
	return mCount;
}