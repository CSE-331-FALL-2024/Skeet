#pragma once
#include <vector>
#include <cassert>


// NOTE: cpp not needed and deleted
class StorageTime
{
private:
	int framesLeft;
	int levelNumber;
	std::vector<int> levelLength;

public:
	StorageTime() : framesLeft(0), levelNumber(0) {}
	void setLevelLengths(const std::vector<int>& values)
	{
		levelLength = values;
	}
	int getLevelLength(int level)
	{
		assert(level >= 0);
		assert(level < levelLength.size());
		return levelLength[level];
	}
	int getLevelLengthSize()
	{
		return levelLength.size();
	}
	int& getFramesLeftRef()
	{
		return framesLeft;
	}
	int& getLevelNumberRef()
	{
		return levelNumber;
	}
};

