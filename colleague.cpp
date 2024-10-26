/***********************************************************************
 * Source File:
 *    Colleague : Send/Receive Messages to/from Mediator
 * Author:
 *    David Cole
 * Summary:
 *    Send/Receive Messages to/from Mediator. Interpret received messages
 *    and perform the correct actions.
 ************************************************************************/

#pragma once

#include <cassert>
#include <list>
#include <string>
#include "mediator.cpp"
#include "bird.h"
#include "score.h"
#include "bullet.h"
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
 * AbstractColleague constructor
 ******************************************************************/
class Colleague
{
public:
	Colleague() : mediator(mediator), message() {};
	Colleague(Mediator pmediator) : mediator(pmediator) {};
	void notify(Message message)
	{
		return;
	};
protected:
	Mediator mediator;
	Message message;
};

/******************************************************************
 * BirdColleague constructor
 ******************************************************************/
class BirdColleague : Colleague
{
public:
	BirdColleague(Bird& pbird) : pBird(pbird) {}

	void wentOutOfBounds()
	{
		message.type = "BIRD_DIED";
		message.value = -pBird.getPoints();
		mediator.notify(message);
	};
	void wasShot()
	{
		message.type = "BIRD_DIED";
		message.value = pBird.getPoints();
		mediator.notify(message);
	};
private:
	Bird& pBird;
};

/******************************************************************
 * BulletColleague constructor
 ******************************************************************/
class BulletColleague : Colleague
{
public:
	BulletColleague(Bullet& pbullet) : pBullet(pbullet) {}

	void firedBullet()
	{
		message.type = "BULLET_FIRED";
		message.value = pBullet.getValue();
		mediator.notify(message);
	}
private:
	Bullet& pBullet;
};

/******************************************************************
 * ScoreColleague constructor
 ******************************************************************/
class ScoreColleague : Colleague
{
public:
	ScoreColleague(Score& pscore) : pScore(pscore) {}
	void notify(Message message)
	{
		pScore.adjust(message.value);
	}

private:
	Score& pScore;
};

/******************************************************************
 * HitRatioColleague constructor
 ******************************************************************/
class HitRatioColleague : Colleague
{
public:
	HitRatioColleague(HitRatio phitratio) : pHitRatio(phitratio) {}
	void notify(Message message)
	{
		if (message.type == "BIRD_DIED")
		{
			pHitRatio.adjust(message.value);
		}
	}

private:
	HitRatio& pHitRatio;
};