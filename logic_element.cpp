#include "logic_element.h"
#include "storage_element.h"
#include <cassert>

/******************************************************************************
* LOGIC ELEMENT :: MOVE
******************************************************************************/
void LogicElement::advance(StorageElement*& pElement, std::list<StorageElement*> & effects)
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
void LogicBomb::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // kill if it has been around too long
    pElement->getTimeToDie()--;
    if (!pElement->getTimeToDie())
        kill(pElement);
    
    // Move the bomb
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC SHRAPNEL :: ADVANCE
******************************************************************************/
void LogicShrapnel::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Kill if it has been around too long
    pElement->getTimeToDie()--;
    if (!pElement->getTimeToDie())
        kill(pElement);
    
    // Add a streek
//    effects.push_back(new Streek())
    
    // Move the bomb
    LogicElement::advance(pElement, effects);
}


/******************************************************************************
* LOGIC MISSILE :: ADVANCE
******************************************************************************/
void LogicMissile::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // add the tail of the missile
//    effects.push_back(new Exaust)
    
    // move the missile
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC STANDARD :: ADVANCE
******************************************************************************/
void LogicStandard::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Drag
    pElement->getVelocity() *= 0.995;
    
    // Move
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC FLOATER :: ADVANCE
******************************************************************************/
void LogicFloater::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Drag
    pElement->getVelocity() *= 0.990;
    
    // Anti-gravity
    pElement->getVelocity().addDy(0.05);
    
    // Move
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC CRAZY :: ADVANCE
******************************************************************************/
void LogicCrazy::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // erratic turns eery half a second or so
    if (randomInt(0, 15) == 0)
    {
        pElement->getVelocity().addDy(randomFloat(-1.5, 1.5));
        pElement->getVelocity().addDx(randomFloat(-1.5, 1.5));
    }
    
    // Move
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC SINKER :: ADVANCE
******************************************************************************/
void LogicSinker::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Gravity
    pElement->getVelocity().addDy(-0.07);
    
    // Move
    LogicElement::advance(pElement, effects);
}

/******************************************************************************
* LOGIC FRAGMENT :: ADVANCE
******************************************************************************/
void LogicFragment::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
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
void LogicStreak::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Increase the age so it fades away
    pElement->getAge() -= 0.10;
}

/******************************************************************************
* LOGIC EXHAUST :: ADVANCE
******************************************************************************/
void LogicExhaust::advance(StorageElement* pElement, std::list<StorageElement*> & effects)
{
    // Increase the age so it fades away
    pElement->getAge() -= 0.025;
}
