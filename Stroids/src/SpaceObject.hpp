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
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hpp"

class SpaceObject
{
    private:
        float angleDeg;
        Vect2d velocity;

    protected:
        int radius;
        Vect2d location;
        void boundFix();
        void setVelocity(float velX, float velY, float maxAngVel);
        void setVelocity(Vect2d vel, float max);
        void setAngle(float deg);
        void updateLocation();

    public:
        SpaceObject();
        //////////////////////////////
        void chgLocation(float deltaX, float deltaY);
        void chgVelocity(float deltaX, float deltaY, float max);
        void chgAngle(float deltaDeg);
        //////////////////////////////
        float getRadius();
        Vect2d getLocation();
        Vect2d getVelocity();
        float getAngVel();
        float getAngle();
        //////////////////////////////
        friend bool objectsIntersect(SpaceObject* obj1, SpaceObject* obj2);
};

#endif
