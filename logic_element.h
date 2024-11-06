#pragma once

class StorageElement;

/******************************************************************************
* LOGIC ELEMENT
******************************************************************************/
class LogicElement
{
private:

public:
	virtual void advance(StorageElement* pElement) = 0;
	virtual void turn(StorageElement* pElement) = 0;
};

/******************************************************************************
* LOGIC PELLET
******************************************************************************/
class LogicPellet : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC BOMB
******************************************************************************/
class LogicBomb : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC SHRAPNEL
******************************************************************************/
class LogiciShrapnel : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC MISSILE
******************************************************************************/
class LogicMissile : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC STANDARD
******************************************************************************/
class LogicStandard : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC FLOATER
******************************************************************************/
class LogicFloater : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC CRAZY
******************************************************************************/
class LogicCrazy : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC SINKER
******************************************************************************/
class LogicSinker : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC FRAGMENT
******************************************************************************/
class LogicFragment : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC STREAK
******************************************************************************/
class LogicStreak : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};

/******************************************************************************
* LOGIC EXHAUST
******************************************************************************/
class LogicExhaust : public LogicElement
{
private:

public:
	void advance(StorageElement* pElement) override;
	void turn(StorageElement* pElement) override;
};






