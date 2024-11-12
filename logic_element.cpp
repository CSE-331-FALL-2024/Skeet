#include "logic_element.h"
#include "storage_element.h"
#include "storage.h"
#include <cassert>

/******************************************************************************
* LOGIC ELEMENT :: MOVE
******************************************************************************/
void LogicElement::advance(StorageElement* pElement, Storage & storage)
{
    // inertia
    pElement->getPosition().add(pElement->getVelocity());
    
    // out of bounds checker
    if (isOutOfBounds(pElement))
    {
        kill(pElement);
        if (pElement->getStorageType() == StorageType::BIRD)
            pElement->getPoints() *= -1;
    }
}

/******************************************************************************
* LOGIC ELEMENT :: IS OUT OF BOUNDS
******************************************************************************/
bool LogicElement::isOutOfBounds(StorageElement *&pElement)
{
    // checking if the element is out of the screen
    return (pElement->getPosition().getX() < -pElement->getRadius() || 
            pElement->getPosition().getX() >= pElement->getDimensions().getX() + pElement->getRadius() ||
            pElement->getPosition().getY() < -pElement->getRadius() || 
            pElement->getPosition().getY() >= pElement->getDimensions().getY() + pElement->getRadius());
    
}

/******************************************************************************
* LOGIC ELEMENT :: RANDOM HELPER FUNCTIONS
******************************************************************************/
int LogicElement::randomInt(int min, int max)
{
    assert(min < max);
    int num = (rand() % (max - min)) + min;
    assert(min <= num && num <= max);
    return num;
}
double LogicElement::randomFloat(double min, double max)
{
    assert(min <= max);
    double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
    assert(min <= num && num <= max);
    return num;
}

/******************************************************************************
* LOGIC BOMB :: ADVANCE
******************************************************************************/
void LogicBomb::advance(StorageElement* pElement, Storage & storage)
{
    // kill if it has been around too long
    pElement->getTimeToDie()--;
    if (!pElement->getTimeToDie())
        kill(pElement);
    
    // Move the bomb
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC BOMB :: DEATH
******************************************************************************/
void LogicBomb::death(Storage & storage, StorageElement * storageElement)
{
    for (int i = 0; i < 20; i++)
       storage.add(new StorageShrapnel(storageElement));
}

/******************************************************************************
* LOGIC SHRAPNEL :: ADVANCE
******************************************************************************/
void LogicShrapnel::advance(StorageElement* pElement, Storage & storage)
{
    // Kill if it has been around too long
    pElement->getTimeToDie()--;
    if (!pElement->getTimeToDie())
        kill(pElement);
    
    // Add a streek
    storage.add(new StorageStreek(pElement->getPosition(), pElement->getVelocity()));
    
    // Move the bomb
    LogicElement::advance(pElement, storage);
}


/******************************************************************************
* LOGIC MISSILE :: ADVANCE
******************************************************************************/
void LogicMissile::advance(StorageElement* pElement, Storage & storage)
{
    // add the tail of the missile
    storage.add(new StorageExhaust(pElement->getPosition(), pElement->getVelocity()));
    
    // move the missile
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC STANDARD :: ADVANCE
******************************************************************************/
void LogicStandard::advance(StorageElement* pElement, Storage & storage)
{
    // Drag
    pElement->getVelocity() *= 0.995;
    
    // Move
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC FLOATER :: ADVANCE
******************************************************************************/
void LogicFloater::advance(StorageElement* pElement, Storage & storage)
{
    // Drag
    pElement->getVelocity() *= 0.990;
    
    // Anti-gravity
    pElement->getVelocity().addDy(0.05);
    
    // Move
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC CRAZY :: ADVANCE
******************************************************************************/
void LogicCrazy::advance(StorageElement* pElement, Storage & storage)
{
    // erratic turns eery half a second or so
    if (randomInt(0, 15) == 0)
    {
        pElement->getVelocity().addDy(randomFloat(-1.5, 1.5));
        pElement->getVelocity().addDx(randomFloat(-1.5, 1.5));
    }
    
    // Move
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC SINKER :: ADVANCE
******************************************************************************/
void LogicSinker::advance(StorageElement* pElement, Storage & storage)
{
    // Gravity
    pElement->getVelocity().addDy(-0.07);
    
    // Move
    LogicElement::advance(pElement, storage);
}

/******************************************************************************
* LOGIC FRAGMENT :: ADVANCE
******************************************************************************/
void LogicFragment::advance(StorageElement* pElement, Storage & storage)
{
    // Move inertia
    pElement->getPosition().add(pElement->getVelocity());
    
    // Increase the age so it fades away
    pElement->getAge() -= 0.02;
    pElement->getSize() *= 0.95;
}

/******************************************************************************
* LOGIC STREAK :: ADVANCE
******************************************************************************/
void LogicStreak::advance(StorageElement* pElement, Storage & storage)
{
    // Increase the age so it fades away
    pElement->getAge() -= 0.10;
}

/******************************************************************************
* LOGIC EXHAUST :: ADVANCE
******************************************************************************/
void LogicExhaust::advance(StorageElement* pElement, Storage & storage)
{
    // Increase the age so it fades away
    pElement->getAge() -= 0.025;
}
