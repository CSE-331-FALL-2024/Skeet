#include "interface_element.h"
#include "storage_element.h"
#include <cassert>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

/******************************************************************************
* INTERFACE ELEMENT:: glVertexPoint
******************************************************************************/
void InterfaceElement::glVertexPoint(const Position& point) const
{
    glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

/******************************************************************************
* INTERFACE ELEMENT:: drawLine
******************************************************************************/
void InterfaceElement::drawLine(const Position& begin, const Position& end,
                                double red, double green, double blue) const
{
    // Get ready...
    glBegin(GL_LINES);
    glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

    // Draw the actual line
    glVertexPoint(begin);
    glVertexPoint(end);

    // Complete drawing
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/******************************************************************************
* INTERFACE ELEMENT:: drawDot
******************************************************************************/
void InterfaceElement::drawDot(const Position& point, double radius,
                               double red, double green, double blue) const
{
    // Get ready, get set...
    glBegin(GL_TRIANGLE_FAN);
    glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);
    double r = radius / 2.0;

    // Go...
    glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() - r));
    glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() - r));
    glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() + r));
    glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() + r));

    // Done!  OK, that was a bit too dramatic
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/******************************************************************************
* INTERFACE ELEMENT:: drawDisk
******************************************************************************/
void InterfaceElement::drawDisk(const Position& center, double radius,
              double red, double green, double blue)
{
    assert(radius > 1.0);
    const double increment = M_PI / radius;  // bigger the circle, the more increments

    // begin drawing
    glBegin(GL_TRIANGLES);
    glColor3f((GLfloat)red /* red % */, (GLfloat)green /* green % */, (GLfloat)blue /* blue % */);

    // three points: center, pt1, pt2
    Position pt1;
    pt1.setX(center.getX() + (radius * cos(0.0)));
    pt1.setY(center.getY() + (radius * sin(0.0)));
    Position pt2(pt1);

    // go around the circle
    for (double radians = increment;
       radians <= M_PI * 2.0 + .5;
       radians += increment)
    {
       pt2.setX(center.getX() + (radius * cos(radians)));
       pt2.setY(center.getY() + (radius * sin(radians)));

       glVertex2f((GLfloat)center.getX(), (GLfloat)center.getY());
       glVertex2f((GLfloat)pt1.getX(), (GLfloat)pt1.getY());
       glVertex2f((GLfloat)pt2.getX(), (GLfloat)pt2.getY());

       pt1 = pt2;
    }

    // complete drawing
    glEnd();
}

/******************************************************************************
* INTERFACE PELLET :: DRAW
******************************************************************************/
void InterfacePellet::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
        drawDot(pElement->getPosition(), 3.0, 1.0, 1.0, 0.0);
}
/******************************************************************************
* INTERFACE BOMB :: DRAW
******************************************************************************/
void InterfaceBomb::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
        // Bomb actually has a gradient to cut out the harsh edges
        drawDot(pElement->getPosition(), pElement->getRadius() + 2.0, 0.50, 0.50, 0.00);
        drawDot(pElement->getPosition(), pElement->getRadius() + 1.0, 0.75, 0.75, 0.00);
        drawDot(pElement->getPosition(), pElement->getRadius() + 0.0, 0.87, 0.87, 0.00);
        drawDot(pElement->getPosition(), pElement->getRadius() - 1.0, 1.00, 1.00, 0.00);
    }
}

/******************************************************************************
* INTERFACE SHRAPNEL :: DRAW
******************************************************************************/
void InterfaceShrapnel::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
       drawDot(pElement->getPosition(), pElement->getRadius(), 1.0, 1.0, 0.0);
}

/******************************************************************************
* INTERFACE MISSILE :: DRAW
******************************************************************************/
void InterfaceMissile::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
        // missile is a line with a dot at the end so it looks like fins.
        Position ptNext(pElement->getPosition());
        ptNext.add(pElement->getVelocity());
        drawLine(pElement->getPosition(), ptNext, 1.0, 1.0, 0.0);
        drawDot(pElement->getPosition(), 3.0, 1.0, 1.0, 1.0);
    }
}

/******************************************************************************
* INTERFACE STANDARD :: DRAW
******************************************************************************/
void InterfaceStandard::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
       drawDisk(pElement->getPosition(), pElement->getRadius() - 0.0, 1.0, 1.0, 1.0); // white outline
       drawDisk(pElement->getPosition(), pElement->getRadius() - 3.0, 0.0, 0.0, 1.0); // blue center
    }
}

/******************************************************************************
* INTERFACE FLOATER :: DRAW
******************************************************************************/
void InterfaceFloater::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
       drawDisk(pElement->getPosition(), pElement->getRadius() - 0.0, 0.0, 0.0, 1.0); // blue outline
       drawDisk(pElement->getPosition(), pElement->getRadius() - 4.0, 1.0, 1.0, 1.0); // white center
    }
}

/******************************************************************************
* INTERFACE CRAZY :: DRAW
******************************************************************************/
void InterfaceCrazy::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
       drawDisk(pElement->getPosition(), pElement->getRadius() * 1.0, 0.0, 0.0, 1.0); // bright blue outside
       drawDisk(pElement->getPosition(), pElement->getRadius() * 0.8, 0.2, 0.2, 1.0);
       drawDisk(pElement->getPosition(), pElement->getRadius() * 0.6, 0.4, 0.4, 1.0);
       drawDisk(pElement->getPosition(), pElement->getRadius() * 0.4, 0.6, 0.6, 1.0);
       drawDisk(pElement->getPosition(), pElement->getRadius() * 0.2, 0.8, 0.8, 1.0); // almost white inside
    }
}

/******************************************************************************
* INTERFACE SINKER :: DRAW
******************************************************************************/
void InterfaceSinker::draw(StorageElement* pElement)
{
    if (!pElement->getIsDead())
    {
       drawDisk(pElement->getPosition(), pElement->getRadius() - 0.0, 0.0, 0.0, 0.8);
       drawDisk(pElement->getPosition(), pElement->getRadius() - 4.0, 0.0, 0.0, 0.0);
    }
}

/******************************************************************************
* INTERFACE FRAGMENT :: DRAW
******************************************************************************/
void InterfaceFragment::draw(StorageElement* pElement)
{
    // Do nothing if we are already dead
    if (pElement->getIsDead())
        return;
    
    // Draw this sucker
    glBegin(GL_TRIANGLE_FAN);
    
    // the color is a function of age - fading to black
    glColor3f((GLfloat)pElement->getAge(), (GLfloat)pElement->getAge(), (GLfloat)pElement->getAge());
    
    // draw the fragment
    glVertex2f((GLfloat)(pElement->getPosition().getX() - pElement->getSize()), (GLfloat)(pElement->getPosition().getY() - pElement->getSize()));
    glVertex2f((GLfloat)(pElement->getPosition().getX() + pElement->getSize()), (GLfloat)(pElement->getPosition().getY() - pElement->getSize()));
    glVertex2f((GLfloat)(pElement->getPosition().getX() + pElement->getSize()), (GLfloat)(pElement->getPosition().getY() + pElement->getSize()));
    glVertex2f((GLfloat)(pElement->getPosition().getX() - pElement->getSize()), (GLfloat)(pElement->getPosition().getY() + pElement->getSize()));
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/******************************************************************************
* INTERFACE STREAK :: DRAW
******************************************************************************/
void InterfaceStreak::draw(StorageElement* pElement)
{
    // Do nothing if we are already dead
    if (pElement->getIsDead())
        return;
    
    // Draw this sucker
    glBegin(GL_LINES);
    glColor3f((GLfloat)pElement->getAge(), (GLfloat)pElement->getAge(), (GLfloat)pElement->getAge());

    // Draw the actual line
    glVertex2f((GLfloat)pElement->getPosition().getX(), (GLfloat)pElement->getPosition().getY());
    glVertex2f((GLfloat)pElement->getPtEnd().getX(), (GLfloat)pElement->getPtEnd().getY());

    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/******************************************************************************
* INTERFACE EXHAUST :: DRAW
******************************************************************************/
void InterfaceExhaust::draw(StorageElement* pElement)
{
    // Do nothing if we are already dead
    if (pElement->getIsDead())
        return;
    
    // Draw this sucker
    glBegin(GL_LINES);
    glColor3f((GLfloat)pElement->getAge(), (GLfloat)pElement->getAge(), (GLfloat)pElement->getAge());

    // Draw the actual line
    glVertex2f((GLfloat)pElement->getPosition().getX(), (GLfloat)pElement->getPosition().getY());
    glVertex2f((GLfloat)pElement->getPtEnd().getX(), (GLfloat)pElement->getPtEnd().getY());

    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}




