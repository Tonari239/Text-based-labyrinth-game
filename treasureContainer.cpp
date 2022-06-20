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
		if (tc.getAt(i)->getName() == "weapon")
		{
			out << 'w' << ' ';
		}
		else if (tc.getAt(i)->getName() == "armor")
		{
			out << 'a' << ' ';
		}
		else if (tc.getAt(i)->getName() == "spell")
		{
			out << 's' << ' ';
		}
		out << *tc.mData[i] <<endl;
	}
	return out;
}

istream& operator>>(istream& in, TreasureContainer& tc)
{
	if (tc.mCount != 0)
	{
		for (int i = 0; i < tc.mCount; i++)
		{
			delete tc.mData[i];
		}
		delete[] tc.mData;
	}
	in >> tc.mCount;
	while (tc.mCount>=tc.mCapacity)
	{
		tc.mCapacity *= 2;
	}
	tc.mData = new Treasure * [tc.mCapacity];
	char label;
	for (int i = 0; i < tc.mCount; i++)
	{
		in >> label;
		if (label == 'w')
		{
			tc.mData[i] = new Weapon(-1,-1,1);
		}
		else if (label == 'a')
		{
			tc.mData[i] = new Armor(-1, -1, 1);
		}
		else if (label == 's')
		{
			tc.mData[i] = new Spell(-1, -1, 1);
		}
		in >> *tc.mData[i];
	}
	return in;
}

