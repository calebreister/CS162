/*
 * CLASS: SPACE_OBJECT_HPP
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  Controls 2D physics for any object that floats in space
 */

#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

#include <iostream>
#include <cmath>
#include "config.hpp"
#include "util.hpp"

class SpaceObject
{
    private:
        util::Vect2d location;
        util::Vect2d velocity;
        float angleDeg;
        int radius;

    public:
        SpaceObject();
        void boundFix();
        void setRadius(int rad);

        void setLocation(float x, float y);
        void chgLocation(float deltaX, float deltaY);
        void updateLocation();

        void setVelocity(float velX, float velY, float maxAngVel);
        void chgVelocity(float deltaX, float deltaY, float max);

        void setAngle(float deg);
        void chgAngle(float deltaDeg);

        //////////////////////////////
        float getRadius();
        util::Vect2d getLocation();
        util::Vect2d getVelocity();
        float getAngVel();
        float getAngle();
        //////////////////////////////
        friend bool objectsIntersect(SpaceObject obj1, SpaceObject* obj2);
};

#endif
