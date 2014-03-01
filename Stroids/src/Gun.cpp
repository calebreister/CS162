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
    timeToLive = 250;
    setRadius(0);
    setLocation(0, 0);
    setVelocity(0, 0, 0);
    setAngle(0);
}

Gun::Gun(Vect2d loc, float ang)
{
    Vect2d vel = util::deg2slope(ang);
    timeToLive = 255;
    setRadius(1);
    setLocation(loc);
    setAngle(ang);

    //vel += 5;
    setVelocity(vel, .1);
    pulse.setRotation(getAngle());
    pulse.setPosition(loc.x, loc.y);
    pulse.setSize(sf::Vector2f(15, 3));
}

void Gun::hit()
{
    timeToLive = 0;
}


bool Gun::pulseDead()
{
    return (timeToLive <= 0) ? true : false;
}

void Gun::draw(sf::RenderWindow& win)
{
    Vect2d loc = getLocation();
    static const int STEPS = timeToLive;
    static int alpha = 255;

    pulse.setPosition(loc.x, loc.y);
    pulse.setFillColor(sf::Color(255, 255, 255, alpha));

    win.draw(pulse);
    alpha -= (255 / STEPS);
    updateLocation();
}
