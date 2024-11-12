#include "interface.h"
#include "logic.h"
#include "uiInteract.h"
#include "storage_gun.h"
#include "storage_element.h"
#include "draw_helper.h"

 /************************************************************************
  * ROTATE
  * Rotate a given point (point) around a given origin (center) by a given
  * number of degrees (angle).
  *    INPUT  origin   The center point we will rotate around
  *           x,y      Offset from center that we will be rotating
  *           rotation Rotation in degrees
  *    OUTPUT point    The new position
  *************************************************************************/
Position rotate(const Position& origin,
   double x, double y, double rotation) 
{
   // because sine and cosine are expensive, we want to call them only once
   double cosA = cos(rotation);
   double sinA = sin(rotation);

   // start with our original point
   Position ptReturn(origin);

   // find the new values
   ptReturn.addX(x * cosA - y * sinA);
   ptReturn.addY(y * cosA + x * sinA /*center of rotation*/);

   return ptReturn;
}


/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
//inline void glVertexPoint(const Position& point)
//{
//   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
//}

/************************************************************************
 * DRAW RECTANGLE
 * Draw a rectangle on the screen from the beginning to the end.
 *************************************************************************/
void drawRectangle(const Position& pt,
                   double angle = 0.0,
                   double width = 10.0,
                   double height = 100.0,
                   double red = 1.0,
                   double green = 1.0,
                   double blue = 1.0)
{
   // Get ready...
   glBegin(GL_QUADS);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(rotate(pt,  width / 2.0,  height / 2.0, angle));
   glVertexPoint(rotate(pt,  width / 2.0, -height / 2.0, angle));
   glVertexPoint(rotate(pt, -width / 2.0, -height / 2.0, angle));
   glVertexPoint(rotate(pt, -width / 2.0,  height / 2.0, angle));
   glVertexPoint(rotate(pt,  width / 2.0,  height / 2.0, angle));

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}




/******************************************************************************
* INTERFACE :: CONSTRUCTOR
******************************************************************************/
Interface::Interface(Position dimensions) : logic(this)
{
    this->dimensions = dimensions;
}

/******************************************************************************
* INTERFACE :: INPUT
******************************************************************************/
void Interface::input(UserInput ui)
{
}

/******************************************************************************
* INTERFACE :: PROCESSING
******************************************************************************/
void Interface::processing()
{
	//logic.input();
}

/******************************************************************************
* INTERFACE :: OUTPUT
******************************************************************************/
void Interface::output()
{
}

void Interface::drawLevel()
{
    // Iterate through all elements and call their draw functions
    for (auto it = logic.getElementsBegin(); it != logic.getElementsEnd(); ++it)
    {
        InterfaceElement* pIface = (*it)->getInterfaceElementPtr();
        pIface->draw(*it);
    }
    drawGun();
}

void Interface::drawStatus()
{
}

/*********************************************
  * GUN : DISPLAY
  * Display the gun on the screen
  *********************************************/
//void Interface::drawGun(const StorageGun& sg) const
void Interface::drawGun() const
{
	//StorageGun& sg = const_cast<StorageGun&>(storageGun);
    const StorageGun& sg = logic.storage.gun;
	const Position& pt = sg.getPositionRef();
	const double& angle = sg.getAngleRef();
	drawRectangle(pt, M_PI_2 - angle, 10.0, 100.0, 1.0, 1.0, 1.0);
}

