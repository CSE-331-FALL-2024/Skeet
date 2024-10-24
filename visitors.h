#pragma once
#include "bird.h"  // Ensure Bird class is fully defined

// Forward declaration of Bird class
class Bird;

// Visitor Interface
class Visitor {
public:
    virtual void visitBird(Bird& bird) = 0;
    //virtual void visit(Bullet& bullet) = 0;
    //virtual void visitEffect(Effect& effect) = 0;
    //virtual void visitTime(Time& time) = 0;
    //virtual void visitScore(Score& score) = 0;
};

// Update class implementing Visitor
class VisitDraw : public Visitor {
public:
    void visitBird(Bird& bird) override {
        bird.draw();
    }

    //void visitBullet(Bullet& bullet) override {
    //    bullet.advance();  
    //}

    //void visitEffect(Effect& effect) override {
    //    effect.fly();  
    //}

    //void visitTime(Time& time) override {
    //    time.advance(); 
    //}

    //void visitScore(Score& score) override {
    //    score.adjust(1);
    //}

    /************************
    * Other birds?
    ************************/
    //void visitBird(Standard& bird) {
    //    bird.advance();
    //}
    //void visitBird(Floater& bird) {
    //    bird.advance();
    //}
    //void visitBird(Crazy& bird) {
    //    bird.advance();
    //}
    //void visitBird(Sinker& bird) {
    //    bird.advance();
    //}
};

//class Draw : public Visitor {
//public:
//    void visitBird(Bird& bird) {
//        bird.draw(); 
//    }

    //void visitBullet(Bullet& bullet) {
    //    bullet.draw();  
    //}

    //void visitEffect(Effect& effect) {
    //    effect.draw(); 
    //}

    //void visitTime(Time& time) {
    //    time.draw();  
    //}

    //void visitScore(Score& score) {
    //    score.draw(); 
    //}
//};