#pragma once

// Forward Declaration
class StorageElement;

/******************************************************************************
* INTERFACE ELEMENT
******************************************************************************/
class InterfaceElement
{
private:

public:
	virtual void draw(StorageElement* pElement) = 0;
};

/******************************************************************************
* INTERFACE PELLET
******************************************************************************/
class InterfacePellet : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};


/******************************************************************************
* INTERFACE BOMB
******************************************************************************/
class InterfaceBomb : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};


/******************************************************************************
* INTERFACE SHRAPNEL
******************************************************************************/
class InterfaceShrapnel : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE MISSILE
******************************************************************************/
class InterfaceMissile : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE STANDARD
******************************************************************************/
class InterfaceStandard : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE FLOATER
******************************************************************************/
class InterfaceFloater : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE CRAZY
******************************************************************************/
class InterfaceCrazy : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE SINKER
******************************************************************************/
class InterfaceSinker : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE FRAGMENT
******************************************************************************/
class InterfaceFragment : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE STREAK
******************************************************************************/
class InterfaceStreak : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE EXHAUST
******************************************************************************/
class InterfaceExhaust : public InterfaceElement
{
private:

public:
	void draw(StorageElement* pElement) override;
};




