//
//  executor.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 11/21/24.
//
#include "executor.hpp"
#include "cassert"
#include "bird.h"
#include "bullet.h"

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int executeRandom(int min, int max)
{
   int num = (rand() % (max - min)) + min;

   return num;
}

void Executor::execute(std::tuple<string, char, double> order)
{
    if (std::get<0>(order) == "CREATE")
    {
        createBirds((int)std::get<2>(order));
    }
    if (std::get<0>(order) == "FIRE")
    {
        fireBullet(std::get<1>(order), std::get<2>(order));
    }
}

void Executor::createBirds(int level)
{
    double size;
    switch (level)
    {
       // in level 1 spawn big birds occasionally
       case 1:
          size = 30.0;
          // spawns when there is nothing on the screen
          if (birds.size() == 0 && executeRandom(0, 15) == 1)
             birds.push_back(new Standard(size, 7.0));
          
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Standard(size, 7.0));
          break;
          
       // two kinds of birds in level 2
       case 2:
          size = 25.0;
          // spawns when there is nothing on the screen
          if (birds.size() == 0 && executeRandom(0, 15) == 1)
             birds.push_back(new Standard(size, 7.0, 12));

          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Standard(size, 5.0, 12));
          // spawn every 3 seconds
          if (executeRandom(0, 3 * 30) == 1)
             birds.push_back(new Sinker(size));
          break;
       
       // three kinds of birds in level 3
       case 3:
          size = 20.0;
          // spawns when there is nothing on the screen
          if (birds.size() == 0 && executeRandom(0, 15) == 1)
             birds.push_back(new Standard(size, 5.0, 15));

          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Standard(size, 5.0, 15));
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Sinker(size, 4.0, 22));
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Floater(size));
          break;
          
       // three kinds of birds in level 4
       case 4:
          size = 15.0;
          // spawns when there is nothing on the screen
          if (birds.size() == 0 && executeRandom(0, 15) == 1)
             birds.push_back(new Standard(size, 4.0, 18));

          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Standard(size, 4.0, 18));
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Sinker(size, 3.5, 25));
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Floater(size, 4.0, 25));
          // spawn every 4 seconds
          if (executeRandom(0, 4 * 30) == 1)
             birds.push_back(new Crazy(size));
          break;
          
       default:
          break;
    }
}

void Executor::fireBullet(char type, double angle)
{
    if (type == 'P')
        bullets.push_back(new Pellet(angle));
    if (type == 'M')
        bullets.push_back(new Missile(angle));
    if (type == 'B')
        bullets.push_back(new Bomb(angle));
}

