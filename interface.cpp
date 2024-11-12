#include "interface.h"
#include "logic.h"
#include "uiInteract.h"
#include "storage_gun.h"
#include "storage_element.h"

/******************************************************************************
* INTERFACE :: CONSTRUCTOR
******************************************************************************/
Interface::Interface()
{
	// Create the logic
	logic = Logic(this);
}

/******************************************************************************
* INTERFACE :: INPUT
******************************************************************************/
void Interface::input(UserInput ui)
{
    // Handle user input and pass it to the logic
    logic.input();
}

/******************************************************************************
* INTERFACE :: PROCESSING
******************************************************************************/
void Interface::processing()
{
    // Process game logic
    logic.advance();
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


