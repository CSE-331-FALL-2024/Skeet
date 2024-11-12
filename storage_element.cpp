#include "storage_element.h"
#include <cassert>

///******************************************************************
// * RANDOM
// * These functions generate a random number.
// ****************************************************************/
//int randomIntStorage(int min, int max)
//{
//   assert(min < max);
//   int num = (rand() % (max - min)) + min;
//   assert(min <= num && num <= max);
//   return num;
//}
//double randomFloatStorage(double min, double max)
//{
//   assert(min <= max);
//   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
//   assert(min <= num && num <= max);
//   return num;
//}
//
///******************************************************************************
//* STORAGE POINT :: CONSTRUCTOR
//******************************************************************************/
//StoragePoint::StoragePoint(const Position& pt, int value)
//{
//    // initial position is where the bullet was last seen
//    this->pt = pt;
//
//    // positive for a hit, negative for a miss
//    this->value = value;
//
//    // age is initially 100%;
//    age = 1.0;
//
//    // up for positive, down for negative
//    double multiplyFactor = (value <= 0 ? -1.0 : 1.0);
//    v.setDy(randomFloatStorage(1.0, 2.0) * multiplyFactor);
//
//    // move points towards the center of the screen
//    multiplyFactor = (pt.getX() > 400 ? -1.0 : 1.0);
//    v.setDx(randomFloatStorage(1.0, 2.0) * multiplyFactor);
//}
//
///******************************************************************************
//* STORAGE STANDARD :: CONSTRUCTOR
//******************************************************************************/
//StorageStandard::StorageStandard(double radius, double speed, int points) : StorageBird()
//{
//    // set the position: standard birds start from the middle
//    pt.setY(randomFloatStorage(dimensions.getY() * 0.25, dimensions.getY() * 0.75));
//    pt.setX(0.0);
//
//    // set the velocity
//    v.setDx(randomFloatStorage(speed - 0.5, speed + 0.5));
//    v.setDy(randomFloatStorage(-speed / 5.0, speed / 5.0));
//
//    // set the points
//    this->points = points;
//
//    // set the size
//    this->radius = radius;
//}
//
///******************************************************************************
//* STORAGE FLOATER :: CONSTRUCTOR
//******************************************************************************/
//StorageFloater::StorageFloater(double radius, double speed, int points) : StorageBird()
//{
//    // floaters start on the lower part of the screen because they go up with time
//    pt.setY(randomFloatStorage(dimensions.getY() * 0.01, dimensions.getY() * 0.5));
//    pt.setX(0.0);
//
//    // set the velocity
//    v.setDx(randomFloatStorage(speed - 0.5, speed + 0.5));
//    v.setDy(randomFloatStorage(0.0, speed / 3.0));
//
//    // set the points value
//    this->points = points;
//
//    // set the size
//    this->radius = radius;
//}
//
///******************************************************************************
//* STORAGE CRAZY :: CONSTRUCTOR
//******************************************************************************/
//StorageCrazy::StorageCrazy(double radius, double speed, int points) : StorageBird()
//{
//    // crazy birds start in the middle and can go any which way
//    pt.setY(randomFloatStorage(dimensions.getY() * 0.25, dimensions.getY() * 0.75));
//    pt.setX(0.0);
//
//    // set the velocity
//    v.setDx(randomFloatStorage(speed - 0.5, speed + 0.5));
//    v.setDy(randomFloatStorage(-speed / 5.0, speed / 5.0));
//
//    // set the points value
//    this->points = points;
//
//    // set the size
//    this->radius = radius;
//}
//
///******************************************************************************
//* STORAGE SINKER :: CONSTRUCTOR
//******************************************************************************/
//StorageSinker::StorageSinker(double radius, double speed, int points) : StorageBird()
//{
//    // sinkers start on the upper part of the screen because they go down with time
//    pt.setY(randomFloatStorage(dimensions.getY() * 0.50, dimensions.getY() * 0.95));
//    pt.setX(0.0);
//
//    // set the velocity
//    v.setDx(randomFloatStorage(speed - 0.5, speed + 0.5));
//    v.setDy(randomFloatStorage(-speed / 3.0, 0.0));
//
//    // set the points value
//    this->points = points;
//
//    // set the size
//    this->radius = radius;
//}
//
///******************************************************************************
//* STORAGE FRAGMENT :: CONSTRUCTOR
//******************************************************************************/
//StorageFragment::StorageFragment(const Position & pt, const Velocity & v) : StorageEffect(pt)
//{
//    // the velocity is a random kick plus the velocity of the thing that died
//    this->v.setDx(v.getDx() * 0.5 + randomFloatStorage(-6.0, 6.0));
//    this->v.setDy(v.getDy() * 0.5 + randomFloatStorage(-6.0, 6.0));
//    
//     // age
//     age = randomFloatStorage(0.4, 1.0);
//     
//     // size
//     size = randomFloatStorage(1.0, 2.5);
//}
//
///******************************************************************************
//* STORAGE SHRAPNEL :: CONSTRUCTOR
//******************************************************************************/
//StorageShrapnel::StorageShrapnel(StorageBomb& bomb)
//{
//    // how long will this one live?
//    timeToDie = randomIntStorage(5, 15);
//    
//    // The speed and direction is random
//    v.set(randomFloatStorage(0.0, 6.2), randomFloatStorage(10.0, 15.0));
//    pt = bomb.getPosition();
//
//    value = 0;
//    
//    radius = 3.0;
//}
//
///******************************************************************************
//* STORAGE STREEK :: CONSTRUCTOR
//******************************************************************************/
//StorageStreek::StorageStreek(const Position & pt, Velocity v) : StorageEffect(pt)
//{
//    ptEnd = pt;
//    v *= -1.0;
//    ptEnd += v;
//    
//     // age
//     age = 0.5;
//}
//
///******************************************************************************
//* STORAGE EXHAUST :: CONSTRUCTOR
//******************************************************************************/
//StorageExhaust::StorageExhaust(const Position & pt, Velocity v) : StorageEffect(pt)
//{
//    ptEnd = pt;
//    v *= -1.0;
//    ptEnd += v;
//
//    // age
//    age = 0.5;
//}
