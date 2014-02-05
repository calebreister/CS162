/*
 * PROGRAM: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of Ship.hpp
 */

#include "Ship.hpp"
using namespace std;

Ship::Ship()
{
    location = WIN_MID;
    velocity = ORIGIN;
    shipAngle.set(45);
    radius = 5;
}

/*
 * FUNCTION: setLocation
 * DESCRIPTION: Set the location of the ship
 * PARAMETERS:
 *  x: the x-coordinate to position the ship
 *  y: the y-coordinate to position the ship
 */
void Ship::setLocation(float x, float y)
{
    location.x = x;
    location.y = y;
}

/*
 * FUNCTION: setVelocity
 * DESCRIPTION: set the the velocity of the ship
 * PARAMETERS:
 *  velX: the x-velocity factor
 *  velY: the y-velocity factor
 */
void Ship::setVelocity(float velX, float velY)
{
    velocity.x = velX;
    velocity.y = velY;
}

/*
 * FUNCTION: setAngle
 * DESCRIPTION: set the heading of the ship
 * PARAMETERS:
 *  angle: the heading of the ship in degrees
 */
void Ship::setAngle(float angle)
{
    shipAngle.set(angle - 90);
    // -90 accounts for the ship creation (which was done with SFML polygons
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
    // draw ship
    sf::ConvexShape ship;
    ship.setPointCount(3);
    ship.setPoint(0, sf::Vector2f(10, 0));
    ship.setPoint(1, sf::Vector2f(0, 25));
    ship.setPoint(2, sf::Vector2f(20, 25));

    sf::Vector2f midpoint(10, 15);
    ship.setOrigin(midpoint);

    ship.setFillColor(sf::Color(0, 0, 0));
    ship.setOutlineThickness(1);
    ship.setOutlineColor(sf::Color(255, 255, 255));

    ship.setPosition(location.x, location.y);
    ship.setRotation(shipAngle.get() + 90);
    win.draw(ship);
}

//////////////////////////////////////////////////////////////

/*
 * FUNCTION: rotateLeft
 * DESCRIPTION: rotates the ship -1 degrees, the
 *  angle of the ship becomes -1, change the current angle 359
 */
void Ship::rotateLeft()
{
    shipAngle.change( -2);
}

/*
 * FUNCTION: rotateRight
 * DESCRIPTION: rotates the ship +1 degrees, sets angle
 *  1 if it exceeds 360
 */
void Ship::rotateRight()
{
    shipAngle.change(2);
}

/*
 * FUNCTION: applyThrust
 * DESCRIPTION:
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * travelling).
 */
void Ship::applyThrust(float thrust)
{
    Vect2d slope = shipAngle.getSlope();
    velocity.x += slope.x * thrust;
    velocity.y += slope.y * thrust;
    updateLocation();
}

/*
 * FUNCTION: updateLocation
 * DESCRIPTION:
 *  - Updates the location based on the current velocity.
 *      (adds the velocity vector to the location vector)
 *  - Ensures that the ship is always inside the window
 */
void Ship::updateLocation()
{
    if (location.x > WIN_SIZE.x)
        location.x = 0;
    if (location.x < ORIGIN.x)
        location.x = WIN_SIZE.x;

    if (location.y > WIN_SIZE.y)
        location.y = 0;
    if (location.y < ORIGIN.y)
        location.y = WIN_SIZE.y;

    location.x += velocity.x;
    location.y += velocity.y;
}

///////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: getRadius
 * DESCRIPTION: returns the radius of the ship
 */
float Ship::getRadius()
{
    return radius;
}

/*
 * FUNCTION: getLocation
 * RETURN: location of the ship
 */
Vect2d Ship::getLocation()
{
    return location;
}

/*
 * FUNCTION: getVelocity
 * RETURN: current velocity of the ship
 */
Vect2d Ship::getVelocity()
{
    return velocity;
}

/*
 * FUNCTION: getAngVel
 * DESCIRPTION: returns the angular velocity of the ship
 */
float Ship::getAngVel()
{
    return std::sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
}

/*
 * FUNCTION: getAngle
 * RETURN: the angle of the ship
 */
float Ship::getAngle()
{
    return shipAngle.get();
}
