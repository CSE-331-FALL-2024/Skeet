/***********************************************************************
 * Source File:
 *    Mediator : Mediate Message Passing
 * Author:
 *    David Cole
 * Summary:
 *    Passes messages between various objects in the program.
 ************************************************************************/

#pragma once

#include <cassert>
#include <list>
#include <string>
#include "colleague.cpp"
using namespace std;

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

/***************************************************************/
/***************************************************************/
/*                         CONSTRUCTORS                         */
/***************************************************************/
/***************************************************************/

/******************************************************************
 * MESSAGE constructor
 ******************************************************************/
class Message
{
public:
	Message() : type("none"), value(0) { }
	Message(string type, int value) { this->type = type, this->value = value; };
	string type;
	int value;
};

/******************************************************************
 * MEDIATOR constructor
 ******************************************************************/
class Mediator
{
protected:
	std::list<Colleague*> colleagues; // colleagues that send/receive messages to/from Mediator
public:
	void notify(Message message)
	{
		for (auto colleague : colleagues)
		{
			colleague->notify(message);
		}
	};
	void enroll(Colleague* enrollee)
	{
		colleagues.push_back(enrollee);
	};
	void unenroll(Colleague* enrollee)
	{
		bool found = false;
		for (auto item = colleagues.begin(); item != colleagues.end() && !found; ++item)
		{
			if (*item == enrollee)
			{
				colleagues.erase(item);
			}

		}
	}
};