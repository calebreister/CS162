/**@file Ship.hh
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief defines a class for controlling a space ship from above.
 */

#ifndef SHIP_HH
#define SHIP_HH

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "SpaceObject.hh"

enum ShipState
{
    GOOD, EXPLODE, GONE
};

/**@class Ship
 * @brief A class derived from SpaceObject designed for
 *  drawing and controlling a user-run ship.
 */
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
        void applyThrust(float thrust);
        ShipState getState();
};

#endif
