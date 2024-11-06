#pragma once
#include<list>
#include "storage_time.h"
#include "storage_gun.h"

// Forward Declaration
class StorageElement;
class Iterator;
class IteratorBird;
class IteratorBullet;

class Storage
{
private:
	std::list<StorageElement*> elements;
	int numBirds;
	int points;
	int numKilled;
	StorageTime time;
	StorageGun gun;

public:
	Storage();
	int getPoints();
	int getNumKilled();
	int getNumMissed();
	void add(StorageElement* pElement);
	void reset();

	// Internal Class
	class Iterator
	{
	public:
		using IterType = std::list<StorageElement*>::iterator;
		Iterator(IterType start, IterType stop);
		// STUBS ARE IN, COMMENTED OUT UNTIL IMPLIMENTED
		// *********************************************
		//bool operator!=(Iterator& rhs);
		//StorageElement* operator*();
		//Iterator& operator++();
	private:
		IterType current;
		IterType end;
	};

	// Internal Class
	class IteratorBird
	{
	public:
		using IterType = std::list<StorageElement*>::iterator;
		IteratorBird(IterType start, IterType stop);
		// STUBS ARE IN, COMMENTED OUT UNTIL IMPLIMENTED
		// *********************************************
		//bool operator!=(IteratorBird& rhs);
		//StorageElement* operator*();
		//IteratorBird& operator++();
		
		
	private:
		IterType currentBird;
		IterType endBird;
	};

	// Internal Class
	class IteratorBullet
	{
	public:
		using IterType = std::list<StorageElement*>::iterator;
		// STUBS ARE IN, COMMENTED OUT UNTIL IMPLIMENTED
		// *********************************************
		IteratorBullet(IterType start, IterType stop);
		//bool operator!=(IteratorBullet& rhs);
		//StorageElement* operator*();
		//IteratorBullet& operator++();
	private:
		IterType currentBullet;
		IterType endBullet;

	};

	Iterator begin();				// Normal
	Iterator end();					// Normal
	IteratorBird beginBird();		// Need to check for StorageType::BIRD
	IteratorBird endBird();			// Need to check for StorageType::BIRD
	IteratorBullet beginBullet();	// Need to check for StorageType::BULLET
	IteratorBullet endBullet();		// Need to check for StorageType::BULLET


};

