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
    angle.set(45);
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
 * FUNCTION: rotateLeft
 * DESCRIPTION: rotates the ship -1 degrees, the
 *  angle of the ship becomes -1, change the current angle 359
 *
void Ship::rotateLeft()
{
    angle.change( -2);
}

/*
 * FUNCTION: rotateRight
 * DESCRIPTION: rotates the ship +1 degrees, sets angle
 *  1 if it exceeds 360
 *
void Ship::rotateRight()
{
    angle.change(2);
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
    chgVelocity(slope);
    updateLocation();
}
