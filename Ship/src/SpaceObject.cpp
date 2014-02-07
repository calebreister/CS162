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
void SpaceObject::chgLocation(Vect2d delta)
{
    location.x += delta.x;
    location.y += delta.y;
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
 *  velY: the y-velocity factor
 */
void SpaceObject::setVelocity(float velX, float velY)
{
    velocity.x = velX;
    velocity.y = velY;
}

/*
 * FUNCTION: chgVelocity
 * DESCRIPTION changes the velocity vector and multiplies it
 * PARAMETERS:
 *  ang - the angle at which to move the ship
 *  max - the maximum velocity to allow in any direction
 *  mag - the magnitude
 */
void SpaceObject::chgVelocity(float mag, float max, Angle::deg ang)
{
    float rad = Angle::deg2rad(ang.get());
    float slope = Angle::deg2slope(ang.get());
    float magX = mag;
    float magY = mag;

    velocity.x += mag * cos(rad);
    velocity.y += mag * sin(rad);

    if (velocity.x > max)
        velocity.x = max;
    if (velocity.x < -max)
        velocity.x = -max;
    if (velocity.y > max)
        velocity.y = max;
    if (velocity.y < -max)
        velocity.y = -max;
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
