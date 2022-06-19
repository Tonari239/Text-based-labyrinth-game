#include "treasureContainer.h"



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
	_free();
}

TreasureContainer& TreasureContainer::operator=(const TreasureContainer& other)
{
	if (this != &other)
	{
		_free();
		copyFrom(other);
	}
	return *this;
}


int TreasureContainer::getCount() const
{
	return mCount;
}


void TreasureContainer::copyFrom(const TreasureContainer& other)
{
	mCount = other.mCount;
	mCapacity = other.mCapacity;
	mData = new Treasure * [mCapacity];
	for (int i = 0; i < mCount; i++)
	{
		mData[i] = other.mData[i]->clone();
	}
}

void TreasureContainer::_free()
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
	delete[] mData; 
	mData = temp;
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


ostream& operator<<(ostream& out, const TreasureContainer& tc)
{
	out << tc.mCount <<endl;
	for (int i = 0; i < tc.mCount; i++)
	{
		out << *tc.mData[i] <<endl;
	}
	return out;
}

istream& operator>>(istream& in, TreasureContainer& tc)
{
	in >> tc.mCount;
	for (int i = 0; i < tc.mCount; i++)
	{
		in >> *tc.mData[i];
	}
	return in;
}

