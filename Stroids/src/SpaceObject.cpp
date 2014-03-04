/*
 * SpaceObject.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: caleb
 */

#define NDEBUG
#include <cassert>
#include "SpaceObject.hpp"

SpaceObject::SpaceObject()
{
    location = ZERO;
    velocity = ZERO;
    angleDeg = 0;
    radius = 0;
}

/*
 * FUNCTION: boundFix
 * DESCRIPTION: makes sure the object does not go outside the screen
 */
void SpaceObject::boundFix()
{
    if (location.x > WIN_SIZE.x)
        location.x = 0;
    if (location.x < ZERO.x)
        location.x = WIN_SIZE.x;

    if (location.y > WIN_SIZE.y)
        location.y = 0;
    if (location.y < ZERO.y)
        location.y = WIN_SIZE.y;
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

    assert(velocity.x <= max);
    assert(velocity.x >= -max);
    assert(velocity.y <= max);
    assert(velocity.y >= -max);
}
void SpaceObject::setVelocity(Vect2d vel, float max)
{
    velocity = vel;

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
    assert(velocity.x <= max);
    assert(velocity.x >= -max);
    assert(velocity.y <= max);
    assert(velocity.y >= -max);
}

/*
 * FUNCTION: setAngle
 * DESCRIPTION: set the angle of the object
 * PARAMETERS:
 *  deg - the angle in degrees to set
 * NOTE: does not set the angle to be within 360 degrees, this is done in getAngle()
 */
void SpaceObject::setAngle(float deg)
{
    angleDeg = deg;
}

/*
 * FUNCTION: chgAngle
 * DESCRIPTION: changes the angle of the object
 * PARAMETERS:
 *  deltaDeg - number of degrees to add to the current angle
 * NOTE: does not set the angle to be within 360 degrees, this is done in getAngle()
 */
void SpaceObject::chgAngle(float deltaDeg)
{
    angleDeg += deltaDeg;
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

/*
 * FUNCTION: getAngle
 * DESCRIPTION: gets the current angle (in degrees) of the object,
 *  ensures the angle value is within 0 and 359
 * RETURN:
 *  angle in degrees (between 0 and 359)
 */
float SpaceObject::getAngle()
{
    angleDeg = fmod(angleDeg, 360);
    return angleDeg;
}

///////////////////////////////////////////////////////////////////////
/*
 * objectsIntersect(SpaceObject obj1, SpaceObject obj2)
 * Checks to see whether the radius of one SpaceObject intersects another
 *
 * obj1: the first object to check
 * obj2: the second object to check
 *
 * RETURN: bool whether or not objects intersect
 */
bool objectsIntersect(SpaceObject* obj1, SpaceObject* obj2)
{
    double distBetween =
                         sqrt(
                              pow(obj2->location.x - obj1->location.x, 2) +
                              pow(obj2->location.y - obj1->location.y, 2));

    if (distBetween < obj1->radius + obj2->radius)
        return true;
    else
        return false;
}
