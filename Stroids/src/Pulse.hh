/**@file Pulse.hh
 * @brief Defines the "bullets" fired by the ship in the asteroids game implementation.
 */
#ifndef MUNITION_HH_
#define MUNITION_HH_

#include "util.hh"
#include "SpaceObject.hh"

/**@class Pulse
 * @brief SpaceObject that simulates laser pulses.
 */
class Pulse : public SpaceObject
{
    private:
        sf::RectangleShape pulse;
        unsigned int timeToLive; //lifetime of pulse
        void checkScreenEdge();
        sf::Color color;

    protected:
        Pulse();

    public:
        Pulse(Vect2d loc, float ang);
        void hit();
        bool isDead();
        void draw(sf::RenderWindow& win);
};

#endif
