/*
 * HEADER: ASTEROIRD_H
 * AUTHOR: Caleb Reister
 * DESCRIPTION: contains class declaration for a single
 *  asteroid for use in my Asteroids clone
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#define NDEBUG
#include <cassert>
#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.h"
#include "SpaceObject.h"

class Asteroid : public SpaceObject
{
    private:
        unsigned int sides;
        float rotationVel; //short for rotational velocity

        enum Side
        {
            left, right,
            top, bottom
        };
        bool checkSide(Side s);
    public:
        Asteroid();
        void draw(sf::RenderWindow& win);
};

#endif
