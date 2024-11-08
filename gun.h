/***********************************************************************
 * Header File:
 *    GUN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The gun at the bottom of the screen
 ************************************************************************/

#pragma once
#include "position.h"
#include "storage_gun.h"

// Forward Declare
class StorageGun;

/*********************************************
 * GUN
 * The gun at the bottom of the screen
 *********************************************/
class Gun
{
public:
	Gun(StorageGun& storageGun, const Position& pt);
	// TODO: ** REMOVE display() - to be implemented in class Interface
	void display(const StorageGun& storageGun) const;  
	void interact(int clockwise, int counterclockwise);
	double getAngle() const { return storageGun.getAngleRef(); }

private:
	StorageGun& storageGun;
};


