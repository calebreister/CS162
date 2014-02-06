/*
 * PROGRAM: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of Ship.hpp
 */

#include "config.h"
#include "Ship.hpp"
using namespace std;

Ship::Ship()
{
    setLocation(WIN_MID.x, WIN_MID.y);
    setVelocity(0, 0);
    angle.set(0);
}

/*
 * FUNCTIOPN: draw
 * DESCRIPTION: draws the ship in the given window
 *  and gets position information from the class.
 *  Defines the shape of the ship
 *  Does NOT get input for positioning
 * PARAMETERS:
 *  win - the window in which to draw the ship
 */
void Ship::draw(sf::RenderWindow& win)
{
    Vect2d loc = getLocation();

    sf::ConvexShape shp;
    shp.setPointCount(3);
    shp.setPoint(0, sf::Vector2f(10, 0));
    shp.setPoint(1, sf::Vector2f(0, 25));
    shp.setPoint(2, sf::Vector2f(20, 25));

    sf::Vector2f midpoint(10, 15);
    shp.setOrigin(midpoint);

    shp.setFillColor(sf::Color(0, 0, 0));
    shp.setOutlineThickness(1);
    shp.setOutlineColor(sf::Color(255, 255, 255));

    shp.setPosition(loc.x, loc.y);
    shp.setRotation(angle.get() + 90);
    win.draw(shp);
}

//////////////////////////////////////////////////////////////

/*
 * FUNCTION: speedLimit
 * DESCRIPTION: limits the speed of the ship based on MAX_SPEED
 *  and MIN_SPEED set in config.h
 */
void Ship::speedLimit()
{
    Vect2d vel = getVelocity();
//    Vect2d slope = Angle::deg2slope(angle.get());

    if (vel.x > MAX_SPEED)
        setVelocity(MAX_SPEED, vel.y);
    if (vel.x < -MAX_SPEED)
        setVelocity(-MAX_SPEED, vel.y);
    if (vel.y > MAX_SPEED)
        setVelocity(vel.x, MAX_SPEED);
    if (vel.y < -MAX_SPEED)
        setVelocity(vel.x, -MAX_SPEED);
}

/*
 * FUNCTION: applyThrust
 * DESCRIPTION:
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * travelling).
 */
void Ship::applyThrust(axis dir, float thrust)
{
    Vect2d slope = Angle::deg2slope(angle.get());
    if (dir == x)
        slope.y = 0;
    if (dir == y)
        slope.x = 0;
    chgVelocity(slope, thrust);
    speedLimit();
    updateLocation();
    speedLimit();
}
