#pragma once

// Forward Declaration
class StorageElement;
class Position;

/******************************************************************************
* INTERFACE ELEMENT
******************************************************************************/
class InterfaceElement
{
public:
	virtual void draw(StorageElement* pElement) = 0;
protected:
    void glVertexPoint(const Position& point) const;
    void drawLine(const Position& begin, const Position& end,
                  double red, double green, double blue) const;
    void drawDot(const Position& point, double radius,
                 double red, double green, double blue) const;
    void drawDisk(const Position& center, double radius,
                  double red, double green, double blue);
};

/******************************************************************************
* INTERFACE PELLET
******************************************************************************/
class InterfacePellet : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};


/******************************************************************************
* INTERFACE BOMB
******************************************************************************/
class InterfaceBomb : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};


/******************************************************************************
* INTERFACE SHRAPNEL
******************************************************************************/
class InterfaceShrapnel : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE MISSILE
******************************************************************************/
class InterfaceMissile : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE STANDARD
******************************************************************************/
class InterfaceStandard : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE FLOATER
******************************************************************************/
class InterfaceFloater : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE CRAZY
******************************************************************************/
class InterfaceCrazy : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE SINKER
******************************************************************************/
class InterfaceSinker : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE FRAGMENT
******************************************************************************/
class InterfaceFragment : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE STREAK
******************************************************************************/
class InterfaceStreak : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};

/******************************************************************************
* INTERFACE EXHAUST
******************************************************************************/
class InterfaceExhaust : public InterfaceElement
{
public:
	void draw(StorageElement* pElement) override;
};




