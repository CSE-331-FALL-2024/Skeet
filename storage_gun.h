#pragma once
#include "position.h"

// NOTE: cpp not needed and deleted

class StorageGun
{
private:
	double angle;
	Position pt;

public:
	StorageGun() : angle(0.0), pt(Position(0.0, 0.0)) {}
	Position& getPositionRef() { return pt; }
	const Position& getPositionRef() const { return pt; }
	double& getAngleRef() { return angle; }
	const double& getAngleRef() const { return angle; }
	//void setGunAngle(double gunAngle) { angle = gunAngle; }
	//void setGunPosition(Position& position) { pt = position; }
};

