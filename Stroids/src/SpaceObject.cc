/**@file SpaceObject.cc
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief Declares a base class for any object that floats around on the screen.
 */

#define NDEBUG
#include <cassert>
#include "SpaceObject.hh"

SpaceObject::SpaceObject()
{
    location = ZERO;
    velocity = ZERO;
    angleDeg = 0;
    radius = 0;
}

/**@fn void SpaceObject::boundFix()
 * @brief Makes sure the object does not go outside the screen
 */
void SpaceObject::boundFix()
{
    if (location.x > WIN_SIZE.x)
        location.x = 0;
    else if (location.x < ZERO.x)
        location.x = WIN_SIZE.x;

    if (location.y > WIN_SIZE.y)
        location.y = 0;
    else if (location.y < ZERO.y)
        location.y = WIN_SIZE.y;
}

/**@fn void SpaceObject::chgLocation(float deltaX, float deltaY)
 * @brief Changes the ships location (in relation to the current position)
 * @param deltaX The X component to change.
 * @param deltaY The Y component to change.
 */
void SpaceObject::chgLocation(float deltaX, float deltaY)
{
    location.x += deltaX;
    location.y += deltaY;
}

/**@fn void SpaceObject::updateLocation()
 *
 *  - Updates the location based on the current velocity.
 *      (adds the velocity vector to the location vector)
 *  - Ensures that the SpaceObject is always inside the window
 */
void SpaceObject::updateLocation()
{
    location.x += velocity.x;
    location.y += velocity.y;
}

/**@fn void SpaceObject::setVelocity(float velX, float velY, float max)
 * @brief Set the velocity of the SpaceObject.
 * @param velX The x-velocity component
 * @param velY The y-velocity component
 * @param max The maximum angular velocity to allow
 */
void SpaceObject::setVelocity(float velX, float velY, float max)
{
    velocity.x = velX;
    velocity.y = velY;

    //SPEED LIMITING
    float angMaxRatio = getAngVel() / max; // angular velocity / max velocity
    if (angMaxRatio > 1)    {
        velocity.x /= angMaxRatio;
        velocity.y /= angMaxRatio;
    }

    assert(velocity.x <= max);
    assert(velocity.x >= -max);
    assert(velocity.y <= max);
    assert(velocity.y >= -max);
}
/**@fn void SpaceObject::setVelocity(const Vect2d& vel, float max)
 * @brief Sets the velocity of the SpaceObject
 * @param vel The velocity vector
 * @param max The maximum angular velocity to allow
 */
void SpaceObject::setVelocity(const Vect2d& vel, float max)
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

/**@fn void SpaceObject::chgVelocity(float deltaX, float deltaY, float max)
 * @brief Changes the velocity vector
 * @param deltaX The change in X
 * @param deltaY The change in Y
 * @param max The max allowable velocity
 */
void SpaceObject::chgVelocity(float deltaX, float deltaY, float max)
{
    setVelocity(velocity.x + deltaX, velocity.y + deltaY, max);
    assert(velocity.x <= max);
    assert(velocity.x >= -max);
    assert(velocity.y <= max);
    assert(velocity.y >= -max);
}

/**@fn void SpaceObject::setAngle(float deg)
 * @brief Set the angle of the object
 * @param deg The angle to set in degrees
 *
 * This function allows you to set the angle of the object in degrees. You do
 * not need to validate the input, that is done in getAngle().
 */
void SpaceObject::setAngle(float deg)
{
    angleDeg = deg;
}

/**@fn void SpaceObject::chgAngle(float deltaDeg)
 * @brief Changes the angle of the object
 * @param deltaDeg The number of degrees to add to the current angle
 */
void SpaceObject::chgAngle(float deltaDeg)
{
    angleDeg += deltaDeg;
}

///////////////////////////////////////////////////////////////////////////////
/**@fn float getRadius
 * @return The radius of the SpaceObject
 */
float SpaceObject::getRadius()
{
    return radius;
}

/**@fn Vect2d getLocation()
 * @return The location of the SpaceObject as a vector
 */
Vect2d SpaceObject::getLocation()
{
    return location;
}

/**@fn Vect2d getVelocity()
 * @return The current velocity of the SpaceObject
 */
Vect2d SpaceObject::getVelocity()
{
    return velocity;
}

/**@fn float getAngVel()
 * @brief Gets the angular velocity of the object
 * @return object's angular velocity as a float
 */
float SpaceObject::getAngVel()
{
    Vect2d vel = getVelocity();
    return sqrt(pow(vel.x, 2) + pow(vel.y, 2));
}

/**@fn getAngle()
 * @brief Gets the current angle (in degrees) of the object,
 *  ensures the angle value is within 0 and 359
 * @return The angle of the SpaceObject in degrees (between 0 and 359)
 */
float SpaceObject::getAngle()
{
    angleDeg = fmod(angleDeg, 360);
    return angleDeg;
}

///////////////////////////////////////////////////////////////////////
/**@fn bool objectsIntersect(SpaceObject obj1, SpaceObject obj2)
 * @brief Checks to see whether the radius of one SpaceObject intersects another
 * @param obj1 The 1st object to check
 * @param obj2 The 2nd object to check
 *
 * @return bool of whether or not objects intersect
 */
bool objectsIntersect(const SpaceObject* obj1, const SpaceObject* obj2)
{
    double distBetween =
                         sqrt(pow(obj2->location.x - obj1->location.x, 2) +
                              pow(obj2->location.y - obj1->location.y, 2));

    if (distBetween < obj1->radius + obj2->radius)
        return true;
    else
        return false;
}
