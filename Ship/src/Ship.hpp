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
#include "SpaceObject.hpp"

class Ship : public SpaceObject
{
    public:
        Ship();
        void draw(sf::RenderWindow& win);
        //User interaction
        void applyThrust(float thrust);
};

#endif
