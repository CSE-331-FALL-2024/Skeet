#include "interface.h"
#include "logic.h"
#include "uiInteract.h"
#include "storage_gun.h"
#include "storage_element.h"

/******************************************************************************
* INTERFACE :: CONSTRUCTOR
******************************************************************************/
Interface::Interface(UserInput* pUi)
{
	// Create the logic
	logic = Logic(this);
	// Set the pointer to the user input
	ui = pUi;
}

/******************************************************************************
* INTERFACE :: GET UI
******************************************************************************/
UserInput* Interface::getUi()
{
    // return UsersInput
    return ui;
}

/******************************************************************************
* INTERFACE :: INPUT
******************************************************************************/
void Interface::input()
{
	// start logics input
	logic.input();
}

/******************************************************************************
* INTERFACE :: PROCESSING
******************************************************************************/
void Interface::processing()
{
    // Process game logic
    if (logic.isPlaying() == true && logic.isGameOver() == false) {
        logic.advance();
    }
}

/******************************************************************************
* INTERFACE :: OUTPUT
******************************************************************************/
void Interface::output()
{
    // Get the iterator from logic
    auto elementsBegin = logic.getElementsBegin();
    auto elementsEnd = logic.getElementsEnd();


    // Iterate through all elements and call their draw functions
    for (auto it = elementsBegin; it != elementsEnd; ++it)
    {
		StorageEffect* pElement = *it;
		pElement->draw(pElement);
    }
}


