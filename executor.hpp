//
//  executor.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 11/21/24.
//

#ifndef executor_hpp
#define executor_hpp

#include <stdio.h>

#pragma once
#include <tuple>
#include <list>

class Gun;
class Bullet;
class Bird;

using namespace std;

class Executor
{
public:
    Executor(std::list<Bird*>& birds,
             std::list<Bullet*>& bullets)
        : birds(birds), bullets(bullets) {}
    void execute(std::tuple<string, char, double> order);
private:
    void createBirds(int level);
    void fireBullet(char type, double angle);
    std::list<Bird*>& birds;
    std::list<Bullet*>& bullets;
};


#endif /* executor_hpp */
