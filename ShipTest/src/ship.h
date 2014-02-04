/*
 * CLASS: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: class for controlling a "ship" from above
 *      going to be used in my implementation of asteroids
 */

#ifndef SHIP_H
#define SHIP_H

#include <cmath>
#include "MyVect.h"

const float PI = M_PI;

/*
 * FUNCTION: toRadians
 * DESCRIPTION: convert degrees to radians
 * PARAMETERS:
 *      degrees - angle in degrees to convert
 * RETURN VALUES:
 *      radians as a float
 */
float
toRadians(float degrees);

class Ship
{
  private:
    MyVect maxLocation;
    MyVect location;
    MyVect velocity;
    float angleDeg;
    float radius;
  public:
    /*
     * CONSTRUCTOR: Ship
     * DESCRIPTION: initialize all member variables to 0, except
     * maxLocations, which should be 1000,1000, and radius, which should be 5
     */
    Ship();

    //=======================================================

    /*
     * FUNCTION: setLocation
     * DESCRIPTION: Set the location of the ship
     * PARAMETERS:
     *  x: the x-coordinate to position the ship
     *  y: the y-coordinate to position the ship
     */
    void
    setLocation(float x, float y);

    /*
     * FUNCTION: setVelocity
     * DESCRIPTION: set the the velocity of the ship
     * PARAMETERS:
     *  velX: the x-velocity factor
     *  velY: the y-velocity factor
     */
    void
    setVelocity(float velX, float velY);

    /*
     * FUNCTION: setAngle
     * DESCRIPTION: set the heading of the ship
     * PARAMETERS:
     *  angle: the heading of the ship in degrees
     */
    void
    setAngle(float angle);

    //========================================================

    /*
     * FUNCTION: rotateLeft
     * DESCRIPTION: rotates the ship -1 degrees, the
     *  angle of the ship becomes -1, change the current angle 359
     */
    void
    turnLeft();

    /*
     * FUNCTION: rotateRight
     * DESCRIPTION: rotates the ship +1 degrees, sets angle
     *  1 if it exceeds 360
     */
    void
    turnRight();

    /*
     * FUNCTION: applyThrust
     * DESCRIPTION:
     * Simulates firing the engine. Changes the current velocity based on the
     * angle the ship is facing (it may be facing a different direction than it’s
     * travelling).
     */
    void
    applyThrust(int thrust);

    /*
     * FUNCTION: updateLocation
     * DESCRIPTION: Updates the location based on the current velocity.
     *  (adds the velocity vector to the location vector)
     */
    void
    updateLocation();

    //====================================================

    /*
     * FUNCTION: getRadius
     * DESCRIPTION: returns the radius of the ship
     */
    float
    getRadius();

    /*
     * FUNCTION: getLocation
     * RETURN: location of the ship
     */
    MyVect
    getLocation();

    /*
     * FUNCTION: getVelocity
     * RETURN: current velocity of the ship
     */
    MyVect
    getVelocity();

    /*
     * FUNCTION: getAngle
     * RETURN: the angle of the ship
     */
    float
    getAngle();
};

#endif
