//
//  handler.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/23/24.
//

#ifndef handler_hpp
#define handler_hpp

#include <stdio.h>
#include "skeet.h"

class UserInput;
class Handler
{
public:
    Handler();
    virtual bool handleRequest(UserInput & ui, Skeet & skeet) = 0;
};

class HandlerGameOver : public Handler
{
public:
    HandlerGameOver();
    bool handleRequest(UserInput & ui, Skeet & skeet);
};

class HandlerPellet : public Handler
{
public:
    HandlerPellet();
    bool handleRequest(UserInput & ui, Skeet & skeet);
};

class HandlerMissile : public Handler
{
public:
    HandlerMissile();
    bool handleRequest(UserInput & ui, Skeet & skeet);
};

class HandlerBomb : public Handler
{
public:
    HandlerBomb();
    bool handleRequest(UserInput & ui, Skeet & skeet);
};

#endif /* handler_hpp */
