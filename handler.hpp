//
//  handler.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/23/24.
//

#ifndef handler_hpp
#define handler_hpp

#include <stdio.h>

class Skeet;
class UserInput;
class Handler
{
public:
    Handler() {};
    virtual bool handleRequest(const UserInput & ui, Skeet & skeet) = 0;
};

class HandlerGameOver : public Handler
{
public:
    HandlerGameOver() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};

class HandlerPellet : public Handler
{
public:
    HandlerPellet() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};

class HandlerMissile : public Handler
{
public:
    HandlerMissile() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};

class HandlerBomb : public Handler
{
public:
    HandlerBomb() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};

class HandlerMoveGun : public Handler
{
public:
    HandlerMoveGun() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};

class HandlerGuideMissile : public Handler
{
public:
    HandlerGuideMissile() {};
    bool handleRequest(const UserInput & ui, Skeet & skeet);
};
#endif /* handler_hpp */
