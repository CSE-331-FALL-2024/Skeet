/******V*****************************************************************
 * Header File:
 *    Bullet
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that kills other things
 ************************************************************************/

#pragma once
#include "position.h"
#include "effect.h"
#include <list>
#include <cassert>

class Status;
class Score;

/*********************************************
 * BULLET
 * Something to shoot something else
 *********************************************/
class Bullet {
	// AFTER - New
private:
	std::list<Status*> audience;

protected:
	static Position dimensions;   // size of the screen
	Position pt;                  // position of the bullet
	Velocity v;                // velocity of the bullet
	double radius;             // the size (radius) of the bullet
	bool dead;                 // is this bullet dead?
	int value;                 // how many points does this cost?

public:
	// BEFORE
	// Bullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1);
	// AFTER
	Bullet(Status* pScore, double angle = 0.0, double speed = 30.0,
		double radius = 5.0, int value = 1);

	// setters
    void kill() { dead = true; }
	void setValue(int newValue) { value = newValue; }

	// getters
	bool isDead()           const { return dead; }
	Position getPosition()  const { return pt; }
	Velocity getVelocity()  const { return v; }
	double getRadius()      const { return radius; }
	int getValue()          const { return value; }

	// special functions
	virtual void death(std::list<Bullet*>& bullets) {}
	virtual void output() = 0;
	virtual void input(bool isUp, bool isDown, bool isB) {}
	virtual void move(std::list<Effect*>& effects);

	// AFTER - New
	// subscriptions
	void subscribe(Status* status);
	void unsubscribe(Status* status);
	void notify(int message);

protected:
	bool isOutOfBounds() const {
		return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
			pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
	}
	void drawLine(const Position& begin, const Position& end,
		double red = 1.0, double green = 1.0, double blue = 1.0) const;

	void drawDot(const Position& point, double radius = 2.0,
		double red = 1.0, double green = 1.0, double blue = 1.0) const;
	int    random(int    min, int    max);
	double random(double min, double max);
};

/*********************
 * PELLET
 * Small little bullet
 **********************/
class Pellet : public Bullet {
public:
	// BEFORE
	// Pellet(double angle, double speed = 15.0) : Bullet(angle, speed, 1.0, 1) {}
	// AFTER
	Pellet(Status* pScore, double angle, double speed = 15.0) :
		Bullet(pScore, angle, speed, 1.0, 1) {
	}

	void output();
};

/*********************
 * BOMB
 * Things that go "boom"
 **********************/
class Bomb : public Bullet {
private:
	int timeToDie;
	// AFTER - ADDED
	Status* pScore;
	double angle;
	double speed;

public:
	// BEFORE
	// Bomb(double angle, double speed = 10.0) : Bullet(angle, speed, 4.0, 4), timeToDie(60) {}
	// AFTER
	Bomb(Status* pScore, double angle, double speed = 10.0) :
		Bullet(pScore, angle, speed, 4.0, 4), pScore(pScore),
		angle(angle), speed(speed), timeToDie(60) {}

	void output();
	void move(std::list<Effect*>& effects);
	void death(std::list<Bullet*>& bullets);
	// AFTER - ADDED TO HELP SHRAPNEL CONSTRUCTOR
	Status* getStatus() const { return pScore; }
	double getAngle() const { return angle; }
	double getSpeed() const { return speed; }

};

/*********************
 * Shrapnel
 * A piece that broke off of a bomb
 **********************/
class Shrapnel : public Bullet {
private:
	int timeToDie;
public:
	// BEFORE
	// Shrapnel(const Bomb& bomb) 
	// AFTER
	Shrapnel(const Bomb& bomb) :
		Bullet(bomb.getStatus(), bomb.getAngle(),
			bomb.getSpeed(), 4.0, 4) {

		// how long will this one live?
		timeToDie = random(5, 15);

		// The speed and direction is random
		v.set(random(0.0, 6.2), random(10.0, 15.0));
		pt = bomb.getPosition();

		value = 0;

		radius = 3.0;
	}

	void output();
	void move(std::list<Effect*>& effects);
};


/*********************
 * MISSILE
 * Guided missiles
 **********************/
class Missile : public Bullet {
public:
	// BEFORE
	// Missile(double angle, double speed = 10.0) : 
	// Bullet(angle, speed, 1.0, 3) {}
	// AFTER
	Missile(Status* pScore, double angle, double speed = 10.0) :
		Bullet(pScore, angle, speed, 1.0, 3) {}

	void output();
	void input(bool isUp, bool isDown, bool isB) {
		if (isUp)
			v.turn(0.04);
		if (isDown)
			v.turn(-0.04);
	}
	void move(std::list<Effect*>& effects);
};
