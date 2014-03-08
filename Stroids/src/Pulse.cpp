/*
 * Pulse.cpp    Feb 27, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Defines the "bullets" fired
 *  by the ship in the asteroids game implementation.
 */

//#define NDEBUG
#include <cassert>
#include "Pulse.hpp"

/* Pulse()
 * Initializes pulse data for testing purposes.
 */
Pulse::Pulse()
{
    //cfg = &stroidConfig;
    timeToLive = 250;
    radius = 0;
    location = ZERO;
    setVelocity(0, 0, 0);
    setAngle(0);
}

/* Pulse(Vect2d loc, float ang)
 * Constructor that passes location and angle data, used to fire a pulse from the ship.
 * Sets a constant velocity.
 *
 * Vect2d loc - the starting location of the pulse
 * float ang - the starting angle of the pulse
 */
Pulse::Pulse(Vect2d loc, float ang)
{
    Vect2d vel = util::deg2slope(ang);
    timeToLive = cfg::getInst()->read["LASER"]["PULSE_LIFE"].as_int();
    radius = 1;
    location = loc;
    setAngle(ang);

    vel *= 100;
    setVelocity(vel, cfg::getInst()->read["SHIP"]["SPEED"].as_float() + 2);
    pulse.setRotation(getAngle());
    pulse.setPosition(loc.x, loc.y);
    pulse.setSize(sf::Vector2f(30, 3));
}

/* void checkScreenEdge()
 * Checks to see if the pulse has reached the edge of the screen.
 * Prevents it from going to the other side.
 */

/* void hit()
 * Sets timeToLive to 0, invoking the draw function will
 * cause the pulse to disappear.
 */
void Pulse::hit()
{
    timeToLive = 0;
}

/* void isDead()
 * Checks to see if the pulse has hit anything.
 */
bool Pulse::isDead()
{
    assert(timeToLive >= 0);
    if (timeToLive == 0)
        return true;
    else
        return false;
}

/* draw(sf::RenderWindow& win)
 * Draws the pulse on the screen where and when appropriate.
 *
 * sf::RenderWindow& win - the window in which to draw the pulse.
 */
void Pulse::draw(sf::RenderWindow& win)
{
    Vect2d loc = getLocation();

    pulse.setPosition(loc.x, loc.y);
    pulse.setFillColor(sf::Color(255, 255, 255));

    win.draw(pulse);
    timeToLive--;
    updateLocation();
}
