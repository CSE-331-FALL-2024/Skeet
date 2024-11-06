#include "storage.h"
#include "storage_element.h"


/******************************************************************************
* STORAGE :: CONSTRUCTOR
******************************************************************************/
Storage::Storage() : numBirds(0), points(0), numKilled(0)
{
}

/******************************************************************************
* STORAGE :: GET POINTS
******************************************************************************/
int Storage::getPoints()
{
	return 0;
}

/******************************************************************************
* STORAGE :: GET NUM KILLED
******************************************************************************/
int Storage::getNumKilled()
{
	return 0;
}

/******************************************************************************
* STORAGE :: GET NUM MISSED
******************************************************************************/
int Storage::getNumMissed()
{
	return 0;
}

/******************************************************************************
* STORAGE ::  ADD
******************************************************************************/
void Storage::add(StorageElement* pElement)
{
}

/******************************************************************************
* STORAGE :: RESET
******************************************************************************/
void Storage::reset()
{
}

/******************************************************************************
* STORAGE :: BEGIN for Iterator
******************************************************************************/
Storage::Iterator Storage::begin()
{
	// Return is correct
	return Iterator(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END for Iterator
******************************************************************************/
Storage::Iterator Storage::end()
{
	// Return is correct
	return Iterator(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: BEGIN BIRD for IteratorBird
******************************************************************************/
Storage::IteratorBird Storage::beginBird()
{
	// Return is INCORRECT, just a place holder: FIX
	return IteratorBird(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END BIRD for IteratorBird
******************************************************************************/
Storage::IteratorBird Storage::endBird()
{
	// Return is INCORRECT, just a place holder: FIX
	return IteratorBird(elements.end(), elements.end());
}

/******************************************************************************
* STORAGE :: BEGIN BULLET for IteratorBullet
******************************************************************************/
Storage::IteratorBullet Storage::beginBullet()
{
	// Return is INCORRECT, just a place holder: FIX
	return IteratorBullet(elements.begin(), elements.end());
}

/******************************************************************************
* STORAGE :: END BULLET for IteratorBullet
******************************************************************************/
Storage::IteratorBullet Storage::endBullet()
{
	// Return is INCORRECT, just a place holder: FIX
	return IteratorBullet(elements.end(), elements.end());
}

/******************************************************************************
* STORAGE :: ITERATOR :: CONSTRUCTOR
******************************************************************************/
Storage::Iterator::Iterator(IterType start, IterType stop)
{
}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR!=()
******************************************************************************/
//bool Storage::Iterator::operator!=(Iterator& rhs)
//{
//	return false;
//}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR*()
******************************************************************************/
//StorageElement* Storage::Iterator::operator*()
//{
//	return nullptr;
//}

/******************************************************************************
* STORAGE :: ITERATOR :: OPERATOR++()
******************************************************************************/
//Iterator& Storage::Iterator::operator++()
//{
//	// TODO: insert return statement here
//}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: CONSTRUCTOR
******************************************************************************/
Storage::IteratorBird::IteratorBird(IterType start, IterType stop)
{
}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR!=()
******************************************************************************/
//bool Storage::IteratorBird::operator!=(IteratorBird& rhs)
//{
//	return false;
//}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR*()
******************************************************************************/
//StorageElement* Storage::IteratorBird::operator*()
//{
//	return nullptr;
//}

/******************************************************************************
* STORAGE :: ITERATOR BIRD :: OPERATOR++()
******************************************************************************/
//IteratorBird& Storage::IteratorBird::operator++()
//{
//	// TODO: insert return statement here
//}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: CONSTRUCTOR
******************************************************************************/
Storage::IteratorBullet::IteratorBullet(IterType start, IterType stop)
{
}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR!=()
******************************************************************************/
//bool Storage::IteratorBullet::operator!=(IteratorBullet& rhs)
//{
//	return false;
//}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR*()
******************************************************************************/
//StorageElement* Storage::IteratorBullet::operator*()
//{
//	return nullptr;
//}

/******************************************************************************
* STORAGE :: ITERATOR BULLET :: OPERATOR++()
******************************************************************************/
//IteratorBullet& Storage::IteratorBullet::operator++()
//{
//	// TODO: insert return statement here
//}



