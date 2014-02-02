/*
 * PROGRAM: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of Ship.hpp
 */

#include "Ship.hpp"
using namespace std;

Ship::Ship()
{
    location = {0, 0};
    velocity = {0, 0};
    shipAngle.set(0);
    radius = 5;
    maxLocation =
    {   1000, 1000};
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
    //validate
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
    //validate
    shipAngle.set(angle);
}

//========================================================

/*
 * FUNCTION: rotateLeft
 * DESCRIPTION: rotates the ship -1 degrees, the
 *  angle of the ship becomes -1, change the current angle 359
 */
void Ship::turnLeft()
{
    shipAngle.change(1);
}

/*
 * FUNCTION: rotateRight
 * DESCRIPTION: rotates the ship +1 degrees, sets angle
 *  1 if it exceeds 360
 */
void Ship::turnRight()
{
    shipAngle.change( -1);
}

/*
 * FUNCTION: applyThrust
 * DESCRIPTION:
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * travelling).
 */
void Ship::applyThrust(int thrust)
{
    velocity = shipAngle.getSlope(thrust);
    updateLocation();
}

/*
 * FUNCTION: updateLocation
 * DESCRIPTION: Updates the location based on the current velocity.
 *  (adds the velocity vector to the location vector)
 */
void Ship::updateLocation()
{
    location.x += velocity.x;
    location.y += velocity.y;
}

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
 * FUNCTION: getAngle
 * RETURN: the angle of the ship
 */
float Ship::getAngle()
{
    return shipAngle.get();
}
