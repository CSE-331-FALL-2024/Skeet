#pragma once

class Bird;
class Bullet;
class Effect;
class Points;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Bird& bird) = 0;
    virtual void visit(Bullet& bullet) = 0;
    virtual void visit(Effect& effect) = 0;
	virtual void visit(Points& points) = 0;
};

