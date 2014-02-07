/*
 * CLASS: SpaceObject
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  Controls 2D physics for any object that floats in space
 */

#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

#include <iostream>
#include <cmath>
#include "config.h"
#include "VectAngle.hpp"

class SpaceObject
{
    private:
        Vect2d velocity;
        Vect2d location;
        float radius;

    public:
        SpaceObject();
        Angle::deg angle;
        void boundFix();

        void setLocation(float x, float y);
        void chgLocation(Vect2d delta);
        void updateLocation();

        void setVelocity(float velX, float velY);
        void chgVelocity(float mag, float max, Angle::deg ang);

        //////////////////////////////
        float getRadius();
        Vect2d getLocation();
        Vect2d getVelocity();
        float getAngVel();
};

#endif
