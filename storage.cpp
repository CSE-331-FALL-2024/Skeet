#include "storage.h"
#include "storage_element.h"


/******************************************************************************
* STORAGE :: CONSTRUCTOR
******************************************************************************/
Storage::Storage() : numBirds(0), points(0), numKilled(0), time(), gun()
{
}

/******************************************************************************
* STORAGE :: GET POINTS (THE SCORE)
******************************************************************************/
int Storage::getPoints()
{
	return points;
}

/******************************************************************************
* STORAGE :: GET NUM KILLED
******************************************************************************/
int Storage::getNumKilled()
{
	return numKilled;
}

/******************************************************************************
* STORAGE :: GET NUM MISSED
******************************************************************************/
int Storage::getNumMissed()
{
	return numBirds - numKilled;
}

/******************************************************************************
* STORAGE ::  ADD
******************************************************************************/
void Storage::add(StorageElement* pElement)
{
	elements.emplace_back(pElement);
}

/******************************************************************************
* STORAGE :: RESET remove all elements
******************************************************************************/
void Storage::reset()
{
	elements.clear();
}

/******************************************************************************
* STORAGE :: BEGIN for Iterator
******************************************************************************/
Storage::Iterator Storage::begin()
{
	return Iterator(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END for Iterator
******************************************************************************/
Storage::Iterator Storage::end()
{
	return Iterator(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: BEGIN BIRD for IteratorBird
******************************************************************************/
Storage::IteratorBird Storage::beginBird()
{
	return IteratorBird(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END BIRD for IteratorBird
******************************************************************************/
Storage::IteratorBird Storage::endBird()
{
	return IteratorBird(elements.end(), elements.end());
}

/******************************************************************************
* STORAGE :: BEGIN BULLET for IteratorBullet
******************************************************************************/
Storage::IteratorBullet Storage::beginBullet()
{
	return IteratorBullet(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END BULLET for IteratorBullet
******************************************************************************/
Storage::IteratorBullet Storage::endBullet()
{
	return IteratorBullet(elements.end(), elements.end());
}

/******************************************************************************
* STORAGE :: ITERATOR :: CONSTRUCTOR
******************************************************************************/
Storage::Iterator::Iterator(IterType start, IterType stop) : 
	current(start), end(stop)
{
}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR!=()
******************************************************************************/
bool Storage::Iterator::operator!=(const Iterator& rhs)
{
	return current != rhs.current;
}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR*()
******************************************************************************/
StorageElement* Storage::Iterator::operator*()
{
	return *current;
}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR++()
******************************************************************************/
Storage::Iterator& Storage::Iterator::operator++()
{
	++current;
	return *this;
}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: CONSTRUCTOR
******************************************************************************/
Storage::IteratorBird::IteratorBird(IterType start, IterType stop) :
	currentBird(start), endBird(stop)
{
	// Find first bird
	if (currentBird != endBird)
	{
		StorageElement* element = *currentBird;
		if (element->getStorageType() != StorageType::BIRD)
		{
			currentBird++;
		}
	}
}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR!=()
******************************************************************************/
bool Storage::IteratorBird::operator!=(IteratorBird& rhs)
{
	return currentBird != rhs.currentBird;
}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR*()
******************************************************************************/
StorageElement* Storage::IteratorBird::operator*()
{
	return *currentBird;
}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR++()
******************************************************************************/
Storage::IteratorBird& Storage::IteratorBird::operator++()
{
	bool foundBird = false;
	while (!foundBird && currentBird != endBird)
	{
		++currentBird;
		if (currentBird != endBird)
		{
			StorageElement* element = *currentBird;
			if (element->getStorageType() == StorageType::BIRD)
			{
				foundBird = true;
			}
		}
	}
	return *this;
}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: CONSTRUCTOR
******************************************************************************/
Storage::IteratorBullet::IteratorBullet(IterType start, IterType stop):
	currentBullet(start), endBullet(stop)
{
	// Find first bullet
	if (currentBullet != endBullet)
	{
		StorageElement* element = *currentBullet;
		if (element->getStorageType() != StorageType::BULLET)
		{
			currentBullet++;
		}
	}
}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR!=()
******************************************************************************/
bool Storage::IteratorBullet::operator!=(IteratorBullet& rhs)
{
	return currentBullet != rhs.currentBullet;
}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR*()
******************************************************************************/
StorageElement* Storage::IteratorBullet::operator*()
{
	return *currentBullet;
}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR++()
******************************************************************************/
Storage::IteratorBullet& Storage::IteratorBullet::operator++()
{
	bool foundBullet = false;
	while (!foundBullet && currentBullet != endBullet)
	{
		++currentBullet;
		if (currentBullet != endBullet)
		{
			StorageElement* element = *currentBullet;
			if (element->getStorageType() == StorageType::BULLET)
			{
				foundBullet = true;
			}
		}
	}
	return *this;
}



