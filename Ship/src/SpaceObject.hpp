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
        void chgLocation(float deltaX, float deltaY);
        void updateLocation();

        void setVelocity(float velX, float velY, float maxAngVel);
        void chgVelocity(float deltaX, float deltaY, float max);

        //////////////////////////////
        float getRadius();
        Vect2d getLocation();
        Vect2d getVelocity();
        float getAngVel();
};

#endif
