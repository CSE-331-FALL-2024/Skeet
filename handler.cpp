//
//  handler.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/23/24.
//

#include "handler.hpp"
//#include "skeet.h"
#include "uiInteract.h"

bool HandlerGameOver::handleRequest(UserInput & ui, Skeet & skeet){
    if (ui.isSpace())
    {
        skeet.time.reset();
        skeet.score.reset();
        skeet.hitRatio.reset();
        return true;
    }
    return false;
}

bool HandlerPellet::handleRequest(UserInput & ui, Skeet & skeet){
    
}

bool HandlerMissile::handleRequest(UserInput & ui, Skeet & skeet){
    
}

bool HandlerBomb::handleRequest(UserInput & ui, Skeet & skeet){
    
}
