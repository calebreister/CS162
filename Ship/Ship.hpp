/*
 * CLASS: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: class for controlling a "ship" from above
 *      going to be used in my implementation of asteroids
 */

#ifndef SHIP_H
#define SHIP_H

#include <cmath>
#include "VectAngle.hpp"

class Ship
{
    private:
        Vect2d maxLocation;
        Vect2d location;
        Vect2d velocity;
        AngleDeg shipAngle;
        float radius;

    public:
        Ship();
        void setLocation(float x, float y);
        void setVelocity(float velX, float velY);
        void setAngle(float angle);
        ///////////////////////////////////////////
        void turnLeft();
        void turnRight();
        void applyThrust(int thrust);
        void updateLocation();
        float getRadius();
        Vect2d getLocation();
        Vect2d getVelocity();
        float getAngle();
};

#endif
