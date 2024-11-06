#pragma once
#include "storage.h"


class Logic
{
private:
	Storage storage;
public:
	Logic();
	void advance();
	void spawn();
	void input();
	/* The UML shows an Iterator in this class, but the class doesn't have 
	   a collection to iterate through since everything is in the Storage class.
	   I'm not sure if these functions are just relaying the iterators from 
	   Storage. I've left the stubs commented out for now. */
	// Iterator begin();
	// Iterator end();
	int getFramesLeft();
	int getLevelNumber();
	double getGunAngle();
	bool isPlaying();
	bool isGameOver();
	double getPercentLeft();
};

