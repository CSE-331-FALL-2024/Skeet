#pragma once
#include "visitor.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "points.h"

class DrawVisitor : public Visitor {
public:
    void visit(Bird& bird) override {
        bird.draw();
    }

    void visit(Bullet& bullet) override {
        bullet.output();
    }

    void visit(Effect& effect) override {
        effect.render();
    }

    void visit(Points& points) override {
        points.show();
    }
};
