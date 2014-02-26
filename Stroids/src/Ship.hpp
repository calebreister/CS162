/*
 * HEADER: SHIP_HPP
 * AUTHOR: Caleb Reister
 * DESCRIPTION: class for controlling a "ship" from above
 *      going to be used in my implementation of asteroids
 */

#ifndef SHIP_HPP
#define SHIP_HPP

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hpp"
#include "SpaceObject.hpp"

enum ShipState
{
    GOOD, EXPLODE, GONE
};

class Ship : public SpaceObject
{
    private:
        sf::ConvexShape ship; //the SFML rendering of the ship
        ShipState state;
        //////////////////////////////
        void draw();

    public:
        Ship();
        void render(sf::RenderWindow& win);
        void explode();
        //USER INTERACTION
        void applyThrust(float thrust);
        void keyCtrl();
};

#endif
