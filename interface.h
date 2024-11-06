#pragma once
#include "logic.h"


// Forward Declarations
class UserInput;

/******************************************************************************
* INTERFACE
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

