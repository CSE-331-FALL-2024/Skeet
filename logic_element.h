#pragma once
#include <list>
#include "storage_element.h"

class StorageElement;

/******************************************************************************
* LOGIC ELEMENT
******************************************************************************/
class LogicElement
{
protected:
    bool isOutOfBounds(StorageElement*& pElement);
    int randomInt(int min, int max);
    double randomFloat(double min, double max);
public:
    void kill(StorageElement*& pElement) { pElement->setIsDead(true); };
	virtual void advance(StorageElement*& pElement, std::list<StorageElement*> & effects);
    virtual void death(std::list<StorageElement *> & bullets) {};
};

/******************************************************************************
* LOGIC PELLET
******************************************************************************/
class LogicPellet : public LogicElement {};

/******************************************************************************
* LOGIC BOMB
******************************************************************************/
class LogicBomb : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC SHRAPNEL
******************************************************************************/
class LogicShrapnel : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC MISSILE
******************************************************************************/
class LogicMissile : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC STANDARD
******************************************************************************/
class LogicStandard : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC FLOATER
******************************************************************************/
class LogicFloater : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC CRAZY
******************************************************************************/
class LogicCrazy : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC SINKER
******************************************************************************/
class LogicSinker : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC FRAGMENT
******************************************************************************/
class LogicFragment : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC STREAK
******************************************************************************/
class LogicStreak : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};

/******************************************************************************
* LOGIC EXHAUST
******************************************************************************/
class LogicExhaust : public LogicElement
{
public:
	void advance(StorageElement* pElement, std::list<StorageElement*> & effects);
};






