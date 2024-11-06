#pragma once
#include "position.h"

// Forward declarations
class LogicElement;
class InterfaceElement;

/******************************************************************************
* ENUM STORAGE TYPE
******************************************************************************/
enum class StorageType
{
	BIRD,
	BULLET,
	EFFECT,
	POINTS
};


/******************************************************************************
* STORAGE ELEMENT
******************************************************************************/
class StorageElement
{
protected:
	/* Note: The Teacher's UML has [pt: Point] However, the class Point 
	   doesn't exist and the Points class represented the numbers that are 
	   displayed on the screen when a bird dies (see StoragePoints below). 
	   The pt should be of type Position, a location. */
	Position pt;
	Velocity v;
	double radius;
	int points;
	bool isDead;
	LogicElement* pLogic;
	InterfaceElement* pInterface;
public:
	// The IteratorBird and IteratorBullet in Storage need this method.
	virtual StorageType getStorageType() = 0;
	Position getPoint() { return pt; }
	Velocity getVelocity() { return v; }
	double getRadius() { return radius; }
	int getPoints() { return points; }
	bool getIsDead() { return isDead; }
	LogicElement* getLogicElementPtr() { return pLogic; }
	InterfaceElement* getInterfaceElementPtr() { return pInterface; }
};


/******************************************************************************
* STORAGE BIRD
******************************************************************************/
class StorageBird : public StorageElement
{
public:
	virtual StorageType getStorageType() final override 
	{ 
		return StorageType::BIRD; 
	}
};


/******************************************************************************
* STORAGE BULLET
******************************************************************************/
class StorageBullet : public StorageElement
{
public:
	virtual StorageType getStorageType() final override 
	{ 
		return StorageType::BULLET; 
	}
};


/******************************************************************************
* STORAGE EFFECT
******************************************************************************/
class StorageEffect : public StorageElement
{
public:
	virtual StorageType getStorageType() final override 
	{ 
		return StorageType::EFFECT; 
	}
};

/******************************************************************************
* STORAGE POINT
******************************************************************************/
class StoragePoint : public StorageElement
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	// Note: StoragePoint doesn't have children so it's constructor needs to 
	// be implemented here
	StoragePoint();
	virtual StorageType getStorageType() final override 
	{ 
		return StorageType::POINTS; 
	}
};


/******************************************************************************
* STORAGE STANDARD 
******************************************************************************/
class StorageStandard : public StorageBird
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageStandard();
};

/******************************************************************************
* STORAGE FLOATER 
******************************************************************************/
class StorageFloater : public StorageBird
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageFloater();
};


/******************************************************************************
* STORAGE CRAZY 
******************************************************************************/
class StorageCrazy : public StorageBird
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageCrazy();
};


/******************************************************************************
* STORAGE SINKER 
******************************************************************************/
class StorageSinker : public StorageBird
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageSinker();
};


/******************************************************************************
* STORAGE PELLET
******************************************************************************/
class StoragePellet : public StorageBullet
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StoragePellet();
};


/******************************************************************************
* STORAGE BOMB 
******************************************************************************/
class StorageBomb : public StorageBullet
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageBomb();
};


/******************************************************************************
* STORAGE SHRAPNEL 
******************************************************************************/
class StorageShrapnel : public StorageBullet
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageShrapnel();
};


/******************************************************************************
* STORAGE MISSILE 
******************************************************************************/
class StorageMissile : public StorageBullet
{
public:
	// The constructors for each Storage type need to be modified so 
	// they can initialize their member variables: pt, v, radius, points, etc.
	StorageMissile();
};

