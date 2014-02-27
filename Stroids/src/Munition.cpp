/*
 * Munition.cpp    Feb 27, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Defines the "bullets" fired
 *  by the ship in the asteroids game implementation.
 */

#include "Munition.hpp"

Munition::Munition()
{
    timeToLive = 0;
    setRadius(0);
    setLocation(0, 0);
    setVelocity(0, 0, 0);
    setAngle(0);
}

Munition::Munition(Vect2d loc, Vect2d vel, float ang)
{
    timeToLive = 150;
    setRadius(1);
    setLocation(loc);
    setAngle(ang);
    setVelocity(vel + 150, 20);
}
