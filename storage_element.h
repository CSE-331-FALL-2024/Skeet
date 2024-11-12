#pragma once
#pragma once
#include "position.h"
#include <cassert>

// Forward declarations
class LogicElement;
class InterfaceElement;

/******************************************************************************
* ENUM STORAGE TYPE
******************************************************************************/
enum class StorageType
{
	NONE,
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
	static Position dimensions;
	Position pt;
	Velocity v;
	double radius;
	int points;
	int value;
	StorageType type;
	double age;
	double size;
	int timeToDie;
	Position ptEnd;
	bool dead;
	LogicElement* pLogElement;
	InterfaceElement* pIfaceElement;
	double angle;

public:
	StorageElement();
	Position getDimensions() { return dimensions; }
	Position& getPosition() { return pt; }
	Velocity& getVelocity() { return v; }
	double& getRadius() { return radius; }
	int& getPoints() { return points; }
	bool& getIsDead() { return dead; }
	int& getValue() { return value; }
	LogicElement* getLogicElementPtr() { return pLogElement; }
	InterfaceElement* getInterfaceElementPtr() { return pIfaceElement; }
	StorageType getStorageType() { return type; }
	// Used by Bomb, Shrapnel
	int& getTimeToDie() { return timeToDie; }
	// Used by Fragment, Streak, Exhaust
	double& getAge() { return age; }
	// Used by Fragment
	double& getSize() { return size; }
	// Used by Exhaust
	Position getPtEnd() { return ptEnd; }
};

/******************************************************************************
* STORAGE BIRD
******************************************************************************/
class StorageBird : public StorageElement
{
public:
	StorageBird() { type = StorageType::BIRD; }
};

/******************************************************************************
* STORAGE BULLET
******************************************************************************/
class StorageBullet : public StorageElement
{
public:
	StorageBullet() { type = StorageType::BULLET; }
};

/******************************************************************************
* STORAGE EFFECT
******************************************************************************/
class StorageEffect : public StorageElement
{
public:
	StorageEffect() { type = StorageType::EFFECT; }
};

/******************************************************************************
* STORAGE POINT
******************************************************************************/
class StoragePoints : public StorageElement
{
public:
	StoragePoints() { type = StorageType::POINTS; }
};


