#pragma once
#include "logic.h"


// Forward Declarations
class UserInput;
class StorageGun;
class InterfaceElement;

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
	Interface(UserInput* pUi);

	UserInput* getUi();

	void input();
	void processing();
	void output();
};