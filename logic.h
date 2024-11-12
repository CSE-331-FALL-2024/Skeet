#pragma once
#include "storage.h"
#include "gun.h"
#include "time.h"
#include "uiInteract.h"
#include "logic_element.h"

class Interface;

class Logic
{
private:
	Storage storage;
	Interface* pInterface;
    Time time;
    Gun gun;
public:
	Logic(Interface* iface);
	LogicStandard logStandard;
	LogicFloater logFloater;
	LogicSinker logSinker;
	LogicCrazy logCrazy;
	LogicPellet logPellet;
	LogicBomb logBomb;
	LogicShrapnel logShrapnel;
	LogicMissile logMissile;
	LogicFragment logFragment;
	LogicStreak logStreak;
	LogicExhaust logExhaust;
		//LogicPoints logPoints;

	void advance();
	void spawn();
	void input(UserInput & ui);
    void hitDetection();
    void removeDeadElements();
	int getFramesLeft();
	int getLevelNumber();
	double getGunAngle();
	bool isPlaying();
	bool isGameOver();
	double getPercentLeft();
    Storage::Iterator getElementsBegin() { return storage.begin(); };
    Storage::Iterator getElementsEnd() { return storage.end(); };
};


