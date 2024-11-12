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
    static Position dimensions;
	Position pt;
	Velocity v;
	double radius;
	int points;
    int value;
    double age;
    double size;
    int timeToDie;
    Position ptEnd;
	bool isDead;
	LogicElement* pLogic;
	InterfaceElement* pInterface;
public:
	// The IteratorBird and IteratorBullet in Storage need this method.
    StorageElement() : isDead(false) {}
    Position getDimensions() {return dimensions; }
	Position& getPosition() { return pt; }
	Velocity& getVelocity() { return v; }
	double& getRadius() { return radius; }
	int& getPoints() { return points; }
    void setPoints(int newPoints) { points = newPoints; }
    int& getValue() { return value; }
    void setValue(int newValue) { value = newValue; }
    double& getAge() { return age; }
    double& getSize() { return size; }
    int& getTimeToDie() { return timeToDie; }
    Position& getPtEnd() { return ptEnd; }
	bool& getIsDead() { return isDead; }
    void setIsDead(bool value) { isDead = value; }
	LogicElement* getLogicElementPtr() { return pLogic; }
	InterfaceElement* getInterfaceElementPtr() { return pInterface; }
    
    virtual StorageType getStorageType() = 0;
};

/******************************************************************************
* STORAGE BIRD
******************************************************************************/
class StorageBird : public StorageElement
{
public:
    StorageBird(int points = 0, double radius = 1.0) : StorageElement()
    {
        this->points = points;
        this->radius = radius;
    }
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
    StorageBullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1) : StorageElement() {
        this->radius = radius;
        this->value = value;
        
        // set the initial position
        pt.setX(dimensions.getX() - 1.0);
        pt.setY(1.0);
        assert(pt.getX() > 100.0);

        // set the initial velocity
        v.setDx(-speed * cos(angle));
        v.setDy(speed * sin(angle));
        assert(v.getDx() <= 0.0);
        assert(v.getDy() >= 0.0);
    }
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
    StorageEffect(const Position & pt)
    {
        this->pt = pt;
        this->age = 0.5;
    }
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
	// Note: StoragePoint doesn't have children so it's constructor needs to 
	// be implemented here
    StoragePoint(const Position& pt, int value);
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
	StorageStandard(double radius = 25.0, double speed = 5.0, int points = 10);
};

/******************************************************************************
* STORAGE FLOATER 
******************************************************************************/
class StorageFloater : public StorageBird
{
public:
	StorageFloater(double radius = 30.0, double speed = 5.0, int points = 15);
};

/******************************************************************************
* STORAGE CRAZY 
******************************************************************************/
class StorageCrazy : public StorageBird
{
public:
	StorageCrazy(double radius = 30.0, double speed = 4.5, int points = 30);
};

/******************************************************************************
* STORAGE SINKER 
******************************************************************************/
class StorageSinker : public StorageBird
{
public:
	StorageSinker(double radius = 30.0, double speed = 4.5, int points = 20);
};

/******************************************************************************
* STORAGE PELLET
******************************************************************************/
class StoragePellet : public StorageBullet
{
public:
    StoragePellet(double angle, double speed = 15.0) : StorageBullet(angle, speed, 1.0, 1) {}
};


/******************************************************************************
* STORAGE BOMB 
******************************************************************************/
class StorageBomb : public StorageBullet
{
public:
    StorageBomb(double angle, double speed = 10.0) : StorageBullet(angle, speed, 4.0, 4){
        timeToDie = 60;
    }
};

/******************************************************************************
* STORAGE SHRAPNEL 
******************************************************************************/
class StorageShrapnel : public StorageBullet
{
public:
    StorageShrapnel(StorageElement * bomb);
};

/******************************************************************************
* STORAGE MISSILE 
******************************************************************************/
class StorageMissile : public StorageBullet
{
public:
    StorageMissile(double angle, double speed = 10.0) : StorageBullet(angle, speed, 1.0, 3) {}
};

/******************************************************************************
* STORAGE FRAGMENT
******************************************************************************/
class StorageFragment : public StorageEffect
{
public:
    StorageFragment(const Position & pt, const Velocity & v);
};

/******************************************************************************
* STORAGE STREEK
******************************************************************************/
class StorageStreek : public StorageEffect
{
public:
    StorageStreek(const Position & pt, Velocity v);
};

/******************************************************************************
* STORAGE EXHAUST
******************************************************************************/
class StorageExhaust : public StorageEffect
{
public:
    StorageExhaust(const Position & pt, Velocity v);
};
