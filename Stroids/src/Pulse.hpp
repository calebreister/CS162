/*
 * Munition.hpp    Feb 27, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Defines the "bullets" fired
 *  by the ship in the asteroids game implementation.
 */
#ifndef MUNITION_HPP_
#define MUNITION_HPP_

#include "util.hpp"
#include "config.hpp"
#include "SpaceObject.hpp"

class Pulse : public SpaceObject
{
    private:
        sf::RectangleShape pulse;
        unsigned int timeToLive; //lifetime of pulse

    public:
        Pulse();
        Pulse(Vect2d loc, float ang);
        //projectile
        void hit();
        bool isDead();
        void draw(sf::RenderWindow& win);
};

#endif