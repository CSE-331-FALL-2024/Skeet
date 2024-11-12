#pragma once
#include <list>
#include "storage_element.h"

class StorageElement;
class Storage;

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
    //void kill(StorageElement* pElement) { pElement->setIsDead(true); };
    void kill(StorageElement* pElement) { pElement->getIsDead() = true; };
	virtual void advance(StorageElement* pElement, Storage & storage);
    virtual void death(Storage & storage) {};
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
	void advance(StorageElement* pElement, Storage & storage);
    void death(Storage & storage, StorageElement * storageElement);
};

/******************************************************************************
* LOGIC SHRAPNEL
******************************************************************************/
class LogicShrapnel : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC MISSILE
******************************************************************************/
class LogicMissile : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC STANDARD
******************************************************************************/
class LogicStandard : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC FLOATER
******************************************************************************/
class LogicFloater : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC CRAZY
******************************************************************************/
class LogicCrazy : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC SINKER
******************************************************************************/
class LogicSinker : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC FRAGMENT
******************************************************************************/
class LogicFragment : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC STREAK
******************************************************************************/
class LogicStreak : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};

/******************************************************************************
* LOGIC EXHAUST
******************************************************************************/
class LogicExhaust : public LogicElement
{
public:
	void advance(StorageElement* pElement, Storage & storage);
};






