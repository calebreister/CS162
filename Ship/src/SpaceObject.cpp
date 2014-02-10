/*
 * SpaceObject.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: caleb
 */

#include "SpaceObject.hpp"

SpaceObject::SpaceObject()
{
    location = WIN_MID;
    velocity = ORIGIN;
    angle.set(45);
    radius = 5;
}

/*
 * FUNCTION: boundFix
 * DESCRIPTION: makes sure the object does not go outside the screen
 */
void SpaceObject::boundFix()
{
    if (location.x > WIN_SIZE.x)
        location.x = 0;
    if (location.x < ORIGIN.x)
        location.x = WIN_SIZE.x;

    if (location.y > WIN_SIZE.y)
        location.y = 0;
    if (location.y < ORIGIN.y)
        location.y = WIN_SIZE.y;
}

/*
 * FUNCTION: setLocation
 * DESCRIPTION: Set the location of the SpaceObject
 * PARAMETERS:
 *  x: the x-coordinate to position the SpaceObject
 *  y: the y-coordinate to position the SpaceObject
 */
void SpaceObject::setLocation(float x, float y)
{
    location.x = x;
    location.y = y;
    boundFix();
}

/*
 * FUNCTION: chgLocation
 * DESCRIPTION: changes the ships location (in relation to the current position)
 * PARAMETERS:
 *  delta - the change vector
 */
void SpaceObject::chgLocation(float deltaX, float deltaY)
{
    location.x += deltaX;
    location.y += deltaY;
    boundFix();
}

/*
 * FUNCTION: updateLocation
 * DESCRIPTION:
 *  - Updates the location based on the current velocity.
 *      (adds the velocity vector to the location vector)
 *  - Ensures that the SpaceObject is always inside the window
 */
void SpaceObject::updateLocation()
{
    location.x += velocity.x;
    location.y += velocity.y;
    boundFix();
}

/*
 * FUNCTION: setVelocity
 * DESCRIPTION: set the the velocity of the SpaceObject
 * PARAMETERS:
 *  velX: the x-velocity factor
 *  velY: the y-velocity factor'
 *  max: the maximum angular velocity to allow
 */
void SpaceObject::setVelocity(float velX, float velY, float max)
{
    velocity.x = velX;
    velocity.y = velY;

    //SPEED LIMITING
    float angMaxRatio = getAngVel() / max; // angular velocity / max velocity
    if (angMaxRatio > 1)
    {
        velocity.x /= angMaxRatio;
        velocity.y /= angMaxRatio;
    }
}

/*
 * FUNCTION: chgVelocity
 * DESCRIPTION changes the velocity vector and multiplies it
 * PARAMETERS 1:
 *  deltaX - the change in X
 *  deltaY - the change in Y
 *  ang - the angle at which to move the ship
 *  mag - the magnitude
 *  max - the max allowable velocity
 */
void SpaceObject::chgVelocity(float deltaX, float deltaY, float max)
{
    setVelocity(velocity.x + deltaX, velocity.y + deltaY, max);
}

///////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: getRadius
 * DESCRIPTION: returns the radius of the SpaceObject
 */
float SpaceObject::getRadius()
{
    return radius;
}

/*
 * FUNCTION: getLocation
 * RETURN: location of the SpaceObject
 */
Vect2d SpaceObject::getLocation()
{
    return location;
}

/*
 * FUNCTION: getVelocity
 * RETURN: current velocity of the SpaceObject
 */
Vect2d SpaceObject::getVelocity()
{
    return velocity;
}

/*
 * FUNCTION: getAngVel
 * DESCRIPTION: gets the angular velocity of the object
 * RETURN: object's angular velocity as a float
 */
float SpaceObject::getAngVel()
{
    Vect2d vel = getVelocity();
    return sqrt(pow(vel.x, 2) + pow(vel.y, 2));
}
