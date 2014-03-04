/*
 * HEADER: ASTEROIRD_HPP
 * AUTHOR: Caleb Reister
 * DESCRIPTION: contains class declaration for a single
 *  asteroid for use in my Asteroids clone
 */

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hpp"
#include "config.hpp"
#include "SpaceObject.hpp"

enum Side
{
    left, right,
    top, bottom
};
enum Quadrant
{
    pp, //++
    nn, //--
    pn, //+-
    np //-+
};

class Asteroid : public SpaceObject
{
    private:
        unsigned int sides;
        float rotationVel; //short for rotational velocity
        bool checkSide(Side s);
        bool checkLocBound(Quadrant quad, Vect2d loc,
                           Vect2d point = WIN_MID,
                           int radius = 200);
        sf::Color color;

    public:
        Asteroid();
        Asteroid(Asteroid* old);
        void draw(sf::RenderWindow& win);
        bool hit;
        bool split;
};

#endif
