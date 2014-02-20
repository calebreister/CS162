/*
 * PROGRAM: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of Ship.h
 */

#include "config.h"
#include "Ship.h"
using namespace std;

Ship::Ship()
{
    setRadius(5);
    setLocation(WIN_MID.x, WIN_MID.y);
    setVelocity(0, 0, 0);
    setAngle(-45);
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
    util::Vect2d loc = getLocation();

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
    shp.setRotation(getAngle() + 90);

    win.draw(shp);
}

//////////////////////////////////////////////////////////////

/*
 * FUNCTION: applyThrust
 * DESCRIPTION:
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * traveling).
 */
void Ship::applyThrust(float thrust)
{
    float rad = util::deg2rad(getAngle());
    chgVelocity(thrust * cos(rad), thrust * sin(rad), MAX_SPEED);
}
