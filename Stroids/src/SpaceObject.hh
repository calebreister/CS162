/**@file SpaceObject.cc
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief  Controls 2D physics for any object that floats in space.
 */

#ifndef SPACE_OBJECT_HH
#define SPACE_OBJECT_HH

#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hh"

/**@class SpaceObject
 * @brief A base class that defines any object that moves from above in a 2d world.
 *  I am using it for an Asteroids clone.
 */
class SpaceObject
{
    private:
        float angleDeg;
        Vect2d velocity;

    protected:
        int radius;
        Vect2d location;
        void boundFix();
        void setVelocity(float velX, float velY, float max);
        void setVelocity(const Vect2d& vel, float max);
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
        friend bool objectsIntersect(const SpaceObject* obj1, const SpaceObject* obj2);
};

#endif
