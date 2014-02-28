/*
 * Gun.cpp    Feb 27, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Defines the "bullets" fired
 *  by the ship in the asteroids game implementation.
 */

#include "Gun.hpp"

Gun::Gun()
{
    timeToLive = 255;
    setRadius(0);
    setLocation(0, 0);
    setVelocity(0, 0, 0);
    setAngle(0);
}

Gun::Gun(Vect2d loc, float ang)
{
    Vect2d vel = util::deg2slope(ang);
    vel.x = 2;
    vel.y = 2;
    timeToLive = 255;
    setRadius(1);
    setLocation(loc);
    setAngle(ang);

    vel *= 5;
    setVelocity(vel, 4);
    pulse.setRotation(getAngle() - 90);
    pulse.setOrigin(loc.x, loc.y);
    pulse.setPosition(0, 0);
    pulse.setSize(sf::Vector2f(15, 3));
}

void Gun::kill()
{
    timeToLive = 0;
}

bool Gun::dead()
{
    return (timeToLive <= 0) ? true : false;
}

void Gun::draw(sf::RenderWindow& win)
{
    Vect2d LOC = getLocation();
    static const int STEPS = timeToLive;
    static int alpha = 255;

    pulse.setPosition(LOC.x, LOC.y);
    pulse.setFillColor(sf::Color(255, 255, 255, alpha));

    win.draw(pulse);
    alpha -= (255 / STEPS);
    updateLocation();
}
