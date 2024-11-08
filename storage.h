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

public:
	Storage();
	int getPoints();
	int getNumKilled();
	int getNumMissed();
	void add(StorageElement* pElement);
	void reset();
	StorageTime time;
	StorageGun gun;

	// Internal Class
	class Iterator
	{
	public:
		using IterType = std::list<StorageElement*>::iterator;
		Iterator(IterType start, IterType stop);
		bool operator!=(const Iterator& rhs);
		StorageElement* operator*();
		Iterator& operator++();
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
		bool operator!=(IteratorBird& rhs);
		StorageElement* operator*();
		IteratorBird& operator++();
	private:
		IterType currentBird;
		IterType endBird;
	};

	// Internal Class
	class IteratorBullet
	{
	public:
		using IterType = std::list<StorageElement*>::iterator;
		IteratorBullet(IterType start, IterType stop);
		bool operator!=(IteratorBullet& rhs);
		StorageElement* operator*();
		IteratorBullet& operator++();
	private:
		IterType currentBullet;
		IterType endBullet;

	};

	Iterator begin();
	Iterator end();	
	IteratorBird beginBird();
	IteratorBird endBird();	
	IteratorBullet beginBullet();	
	IteratorBullet endBullet();		


};

