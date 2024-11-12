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
	Logic logic = nullptr;
	UserInput* ui;
public:
	Interface();
	void input(UserInput* pUi);
	void processing();
	void output();
};




