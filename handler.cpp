//
//  handler.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/23/24.
//

#include "handler.hpp"
#include "skeet.h"
#include "uiInteract.h"

bool HandlerGameOver::handleRequest(const UserInput & ui, Skeet & skeet){
    if (ui.isSpace())
    {
        skeet.reset();
        return true;
    }
    return false;
}

bool HandlerPellet::handleRequest(const UserInput & ui, Skeet & skeet){
    if (ui.isSpace())
    {
        auto p = new Pellet(skeet.getGunAngle());
        skeet.addBullet(p);
        return true;
    }
    return false;
}

bool HandlerMissile::handleRequest(const UserInput & ui, Skeet & skeet){
    if (ui.isM())
    {
        auto p = new Missile(skeet.getGunAngle());
        skeet.addBullet(p);
        return true;
    }
    return false;
}

bool HandlerBomb::handleRequest(const UserInput & ui, Skeet & skeet){
    if (ui.isB())
    {
        auto p = new Bomb(skeet.getGunAngle());
        skeet.addBullet(p);
        return true;
    }
    return false;
}

bool HandlerMoveGun::handleRequest(const UserInput & ui, Skeet & skeet){
    skeet.moveGun(ui);
    return false;
}

bool HandlerGuideMissile::handleRequest(const UserInput & ui, Skeet & skeet){
    skeet.moveMissile(ui);
    return false;
}
