#pragma once
#include "logic.h"
#include "interface_element.h"
#include "draw_helper.h"


// Forward Declarations
class UserInput;
class StorageGun;

/******************************************************************************
* CLASS INTERFACE
******************************************************************************/
class Interface
{
private:
	Logic logic;

public:
	Interface();

	InterfaceStandard ifaceStandard;
	InterfaceFloater ifaceFloater;
	InterfaceSinker ifaceSinker;
	InterfaceCrazy ifaceCrazy;
	InterfacePellet ifacePellet;
	InterfaceBomb ifaceBomb;
	InterfaceShrapnel ifaceShrapnel;
	InterfaceMissile ifaceMissile;
	InterfaceFragment ifaceFragment;
	InterfaceStreak ifaceStreak;
	InterfaceExhaust ifaceExhaust;
	//InterfacePoints ifacePoints;

	void input(UserInput ui);
	void processing();
	void output();
};




