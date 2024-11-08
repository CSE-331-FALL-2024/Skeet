#pragma once
#include "logic.h"


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
	void input(UserInput ui);
	void processing();
	void output();
};




