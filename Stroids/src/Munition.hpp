/*
 * Munition.hpp    Feb 27, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Defines the "bullets" fired
 *  by the ship in the asteroids game implementation.
 */
#ifndef MUNITION_HPP_
#define MUNITION_HPP_

#include "SpaceObject.hpp"

class Munition : public SpaceObject
{
    private:
        int timeToLive;
    public:
        Munition();
        Munition(Vect2d loc, Vect2d vel, float ang);
        bool dead();
        void draw(sf::RenderWindow& win);
};

#endif
