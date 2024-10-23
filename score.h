/***********************************************************************
 * Header File:
 *    Score
 * Author:
 *    Br. Helfrich
 * Summary:
 *    How well the player is doing
 ************************************************************************/

#pragma once
#include <string>

/**********************
 * STATUS
 * How well the player is doing
 **********************/
class Status
{
public:
    Status() {}
    virtual std::string getText() const = 0;
    // AFTER - REMOVED NOT NEEDED
    // virtual void adjust(int value) = 0;
    virtual void reset() = 0;
    // AFTER - ADDED
    virtual void update(int message) = 0;
};

/**********************
 * SCORE
 * Points earned vs lost
 **********************/
class Score : public Status
{
public:
    Score() { reset(); }
    std::string getText() const;
    // AFTER - REMOVED NOT NEEDED
    // void adjust(int value) { points += value; }
    void reset() { points = 0; }
    // AFTER - ADDED
    void update(int message) override;
private:
    int points;
};

/**********************
 * HIT RATIO
 * Bird hit ratio
 **********************/
class HitRatio : public Status
{
public:
    HitRatio()  { reset(); }
    std::string getText() const;
    // AFTER - REMOVED NOT NEEDED
    //void adjust(int value);
    void reset() { numKilled = numMissed = 0; }
    // AFTER - ADDED
    void update(int message) override;
private:
    int numKilled;
    int numMissed;
};
