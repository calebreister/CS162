/*
 * CLASS: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: class for controlling a "ship" from above
 *      going to be used in my implementation of asteroids
 */

#ifndef SHIP_H
#define SHIP_H

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "VectAngle.hpp"

const int refHz = 120; //Hz at which to refresh the screen
const Vect2d WIN_SIZE = { 800, 800 };
const Vect2d WIN_MID = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
const Vect2d ORIGIN = { 0, 0 };

class Ship
{
    private:
        Vect2d location;
        Vect2d velocity;
        AngleDeg shipAngle;
        float radius;

    public:
        Ship();
        //Utility actions
        void setLocation(float x, float y);
        void setVelocity(float velX, float velY);
        void setAngle(float angle);
        void draw(sf::RenderWindow& win);
        void updateLocation();
        //User interaction
        void rotateLeft();
        void rotateRight();
        void applyThrust(float thrust);
        //accessors
        float getRadius();
        Vect2d getLocation();
        Vect2d getVelocity();
        float getAngle();
};

#endif
