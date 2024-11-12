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
	static Position dimensions;

public:
	Logic logic;
	Interface(Position dimensions);

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
	void drawLevel();
	void drawStatus();
	void drawGun() const;
};




