#pragma once
#include "visitor.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "points.h"

class MoveVisitor : public Visitor {

private:
    std::list<Effect*>& effects;
    HitRatio hitRatio;
public:
    // Constructor
    MoveVisitor(std::list<Effect*>& effects, HitRatio hitRatio) : effects(effects), hitRatio(hitRatio) {}

    void visit(Bird& bird) override {
        bird.advance();
        hitRatio.adjust(bird.isDead() ? -1 : 0);
    }

    void visit(Bullet& bullet) override {
		bullet.move(effects);
    }

    void visit(Effect& effect) override {
		effect.fly();
    }

    void visit(Points& points) override {
		points.update();
    }
};