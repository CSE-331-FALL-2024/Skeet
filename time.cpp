/***********************************************************************
 * Implementation File:
 *    TIME
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Time in level, what level it is, etc.
 ************************************************************************/

#include "time.h"
#include <sstream>
#include "storage_time.h"

using namespace std;

#define SECONDS_STATUS 5.0



Time::Time(StorageTime& storageTime):storageTime(storageTime), 
    levelNumber(storageTime.getLevelNumberRef()),
    framesLeft(storageTime.getFramesLeftRef())
{
    reset();
}

/************************
 * TIME reset
 * Set up the levels and stuff
 ************************/
void Time::reset()
{
    // first level is 30 seconds in length, the first 5 are the status time
    storageTime.setLevelLengths({0, 30, 30, 45, 45});
    levelNumber = 1;
    framesLeft = FRAMES_PER_SECOND * storageTime.getLevelLength(levelNumber);

    //levelLength = {0, 30, 30, 45, 45};
    //levelNumber = 1;
    //framesLeft = FRAMES_PER_SECOND * levelLength[levelNumber];
}


/************************
 * TIME IS PLAYING
 * Are we currently in a game playing time?
 ************************/
bool Time::isPlaying() const
{
    // the first 5 seconds are not game plahing time.
    return secondsInLevel() > SECONDS_STATUS;
}

/************************
 * TIME PERCENT LEFT
 * What percent is left?
 ************************/
double Time::percentLeft() const
{
    //assert(levelNumber >= 0 && levelNumber < (int)levelLength.size());
    assert(levelNumber >= 0 && levelNumber < storageTime.getLevelLengthSize());
    double framesInStatus = SECONDS_STATUS * FRAMES_PER_SECOND;
    //double framesInPlaying = (levelLength[levelNumber] - SECONDS_STATUS) * FRAMES_PER_SECOND;
    double framesInPlaying = (storageTime.getLevelLength(levelNumber) - SECONDS_STATUS) * FRAMES_PER_SECOND;
    
    if (isStatus())
    {
        assert(framesLeft - framesInPlaying <= framesInStatus);
        assert(framesLeft - framesInPlaying >= 0);
        assert(framesInStatus > 0);
        return (double)(framesLeft - framesInPlaying) / (double)framesInStatus;
    }
    else
    {
        assert(framesLeft - framesInStatus <= framesInPlaying);
        assert(framesLeft - framesInStatus >= 0);
        assert(framesInPlaying > 0);
        return (double)(framesLeft - framesInStatus) / (double)framesInPlaying;
    }
}

/************************
 * TIME SECONDS LEFT
 * How much time left, including status messages
 ************************/
int Time::secondsLeft() const
{
    //assert(levelNumber >= 0 && levelNumber < (int)levelLength.size());
    assert(levelNumber >= 0 && levelNumber < storageTime.getLevelLengthSize());
    if (isStatus())
        //return secondsFromFrames(framesLeft) - levelLength[levelNumber] + (int)SECONDS_STATUS + 1;
        return secondsFromFrames(framesLeft) - storageTime.getLevelLength(levelNumber) 
            + (int)SECONDS_STATUS + 1;
    else
        return secondsFromFrames(framesLeft) + 1;
}

/************************
 * TIME IS START LEVEL
 * Os this the very start of the playing time of the leve
 ************************/
bool Time::isStartLevel() const
{
    if (isPlaying())
        //return framesLeft == FRAMES_PER_SECOND * (levelLength[levelNumber] - (int)SECONDS_STATUS) - 1;
        return framesLeft == FRAMES_PER_SECOND * (storageTime.getLevelLength(levelNumber) - (int)SECONDS_STATUS) - 1;
    else
        return false;
}

/************************
 * TIME ADVANCE
 * Advance the time counter by one frame
 ************************/
void Time::operator++(int postfix)
{
    //assert(levelNumber >= 0 && levelNumber < (int)levelLength.size());
    assert(levelNumber >= 0 && levelNumber < storageTime.getLevelLengthSize());
    
    // do nothing in the game over scenario
    if (levelNumber == 0)
        return;
    
    // standard move withing a level
    if (framesLeft >= 1)
        framesLeft--;
    
    // changing the level
    else
    {
        // move the level or...
        levelNumber++;
        //if (levelNumber < (int)levelLength.size())
        if (levelNumber < storageTime.getLevelLengthSize())
        {
            //framesLeft = FRAMES_PER_SECOND * levelLength[levelNumber];
            framesLeft = FRAMES_PER_SECOND * storageTime.getLevelLength(levelNumber);
        }
        // game over!
        else
            levelNumber = 0;
    }
}

/************************
 * TIME GET TEXT
 * Get the status text
 ************************/
string Time::getText() const
{
    ostringstream sout;

    sout << "Time:  " << secondsLeft();

    return sout.str();
}
    // how long have we been in the level in seconds?
int Time::secondsInLevel() const
{
	//assert(levelNumber < (int)levelLength.size());
	assert(levelNumber < storageTime.getLevelLengthSize());
	//return levelLength[levelNumber] - secondsFromFrames(framesLeft);
	return storageTime.getLevelLength(levelNumber) - secondsFromFrames(framesLeft);
}
