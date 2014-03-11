/**@file Asteroid.hh
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief Contains a class declaration for a single asteroid.
 */

#ifndef ASTEROID_HH
#define ASTEROID_HH

#include <iostream>
#include <cmath>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "SpaceObject.hh"

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

/**@class Asteroid
 * @brief A SpaceObject that draws an asteroid in the given window.
 */
class Asteroid : public SpaceObject
{
    private:
        unsigned int sides;
        float rotationVel; //short for rotational velocity
        bool checkSide(Side s);
        bool checkLocBound(Quadrant quad, const Vect2d& loc,
                           const Vect2d& point = WIN_MID,
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
