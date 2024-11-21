#pragma once
#ifndef ORDER_H
#define ORDER_H

// Abstract class for all orders
class Order {
public:
    virtual void execute() = 0; // Pure virtual function to execute the order
    virtual ~Order() {}        // Virtual destructor for cleanup
};

#endif // ORDER_H


#include "bullet.h"

class PelletOrder : public Order {
private:
	// Attributes
    std::list<Bullet*>& bullets;
	double angle;
public:
	// Constructor
	PelletOrder(std::list<Bullet*>& bullets, double angle) : bullets(bullets), angle(angle) {}
	
	// Methods
	void execute() override
	{
		bullets.push_back(new Pellet(angle));
	}
};

class MissileOrder : public Order {
private:
	// Attributes
    std::list<Bullet*>& bullets;
    double angle;           

public:
	// Constructor
    MissileOrder(std::list<Bullet*>& bullets, double angle)
        : bullets(bullets), angle(angle) {}


	// Methods
    void execute() override {
        bullets.push_back(new Missile(angle));
    }
};

class BombOrder : public Order {
private:
	// Attributes
    std::list<Bullet*>& bullets;
    double angle;

public:
	// Constructor
    BombOrder(std::list<Bullet*>& bullets, double angle)
        : bullets(bullets), angle(angle) {}

	// Methods
    void execute() override {
        bullets.push_back(new Bomb(angle)); 
    }
};

class gameResetOrder : public Order {
private:
    //Attributes
	Time& time;
	Score& score;
	HitRatio& hitRatio;
public:
	//Constructor
	gameResetOrder(Time& time, Score& score, HitRatio& hitRatio) : time(time), score(score), hitRatio(hitRatio) {}

	// Methods
	void execute() override
	{
		time.reset();
		score.reset();
		hitRatio.reset();
	}
};

class stateOrder : public Order {
private:
	//Attribute
	int isUp;
	int isRight;
	int isDown;
	int isLeft;
	bool isB;
	bool isShift;
	std::list<Bullet*>& bullets;
	Gun& gun;
	bool& bullseye;
public:
	//Constructor
	stateOrder(int isUp, int isRight, int isDown, int isLeft, bool isB, bool isShift, std::list<Bullet*>& bullets, Gun&gun, bool& bullseye)
		: isUp(isUp), isRight(isRight), isDown(isDown), isLeft(isLeft), isB(isB), isShift(isShift), bullets(bullets), gun(gun), bullseye(bullseye){}

	//Methods
	void execute() override
	{
		for (auto bullet : bullets)
		{
			bullet->input(isUp + isRight, isDown + isLeft, isB);
		}
		gun.interact(isUp + isRight, isDown + isLeft);
		bullseye = isShift;
	}
};