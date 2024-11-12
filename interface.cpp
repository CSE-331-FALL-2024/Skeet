#include "interface.h"
#include "logic.h"
#include "uiInteract.h"
#include "storage_gun.h"
#include "storage_element.h"
#include "interface_element.h"

/******************************************************************************
* CONSTRUCTOR DEFAULT
******************************************************************************/
Interface::Interface()
{
    //Probably wont use this method

    // Create the logic
    logic = Logic(this);
    // Set the pointer to the user input
    ui = new UserInput();
}

/******************************************************************************
* CONSTRUCTOR WITH USER INPUT
******************************************************************************/
Interface::Interface(UserInput* pUi)
{
    // Use this constructor to set the UserInput as a attribute

	// Create the logic
	logic = Logic(this);
	// Set the pointer to the user input
	ui = pUi;
}

/******************************************************************************
* GET UI
* Get the UserInput from the Interface
******************************************************************************/
UserInput* Interface::getUi()
{
    return ui;
}

/******************************************************************************
* INPUT
******************************************************************************/
void Interface::input()
{
	// start logics input
	logic.input();
}

/******************************************************************************
* PROCESSING
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
    // Make a interface element that acts like a visitor to go to 
    // each element to draw it
    InterfaceElement* pInterface;
    
    // Get iterator from logic
    auto elementsBegin = logic.getElementsBegin();
    auto elementsEnd = logic.getElementsEnd();


    // Iterate through all elements and call their draw functions
    for (auto it = elementsBegin; it != elementsEnd; ++it)
    {
        
        StorageElement* pElement = *it;
        pInterface->draw(pElement);
    }
}


