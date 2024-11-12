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
	LogicElement* pLogic;
	InterfaceElement* pInterface;

public:
	StorageElement();
    Position getDimensions() {return dimensions; }
	Position& getPosition() { return pt; }
	Velocity& getVelocity() { return v; }
	double& getRadius() { return radius; }
	int& getPoints() { return points; }
	bool& getIsDead() { return dead; }
	LogicElement* getLogicElementPtr() { return pLogic; }
	InterfaceElement* getInterfaceElementPtr() { return pInterface; }
	StorageType getStorageType() { return type;}
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





/******************************************************************************
* STORAGE STANDARD 
******************************************************************************/
//class StorageStandard : public StorageBird
//{
//public:
//	StorageStandard(double radius = 25.0, double speed = 5.0, int points = 10);
//};

/******************************************************************************
* STORAGE FLOATER 
******************************************************************************/
//class StorageFloater : public StorageBird
//{
//public:
//	StorageFloater(double radius = 30.0, double speed = 5.0, int points = 15);
//};

/******************************************************************************
* STORAGE CRAZY 
******************************************************************************/
//class StorageCrazy : public StorageBird
//{
//public:
//	StorageCrazy(double radius = 30.0, double speed = 4.5, int points = 30);
//};

/******************************************************************************
* STORAGE SINKER 
******************************************************************************/
//class StorageSinker : public StorageBird
//{
//public:
//	StorageSinker(double radius = 30.0, double speed = 4.5, int points = 20);
//};

/******************************************************************************
* STORAGE PELLET
******************************************************************************/
//class StoragePellet : public StorageBullet
//{
//public:
//    StoragePellet(double angle, double speed = 15.0) : StorageBullet(angle, speed, 1.0, 1) {}
//};


/******************************************************************************
* STORAGE BOMB 
******************************************************************************/
//class StorageBomb : public StorageBullet
//{
//public:
//    StorageBomb(double angle, double speed = 10.0) : StorageBullet(angle, speed, 4.0, 4){
//        timeToDie = 60;
//    }
//};

/******************************************************************************
* STORAGE SHRAPNEL 
******************************************************************************/
// class StorageShrapnel : public StorageBullet
//{
//public:
//    StorageShrapnel(StorageBomb & bomb);
//};

/******************************************************************************
* STORAGE MISSILE 
******************************************************************************/
//class StorageMissile : public StorageBullet
//{
//public:
//    StorageMissile(double angle, double speed = 10.0) : StorageBullet(angle, speed, 1.0, 3) {}
//};

/******************************************************************************
* STORAGE FRAGMENT
******************************************************************************/
//class StorageFragment : public StorageEffect
//{
//public:
//    StorageFragment(const Position & pt, const Velocity & v);
//};

/******************************************************************************
* STORAGE STREEK
******************************************************************************/
//class StorageStreek : public StorageEffect
//{
//public:
//    StorageStreek(const Position & pt, Velocity v);
//};

/******************************************************************************
* STORAGE EXHAUST
******************************************************************************/
//class StorageExhaust : public StorageEffect
//{
//public:
//    StorageExhaust(const Position & pt, Velocity v);
//};
