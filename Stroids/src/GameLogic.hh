/**@file GameLogic.hh
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief Graphics and operation of the asteroids game
 */

#ifndef GAME_LOGIC_HH
#define GAME_LOGIC_HH

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "Ship.hh"
#include "Asteroid.hh"
#include "Pulse.hh"

/**@class GameLogic
 * @brief A class used to control an asteroids game.
 */
class GameLogic
{
    private:
        //rendering order
        Asteroid* stroid[MAX_STROIDS];
        Pulse* laser[MAX_PULSE];
        Ship ship;
        int findFreeStroid();

    public:
        GameLogic();
        ~GameLogic();
        void keyInput();
        void fireGun(sf::Event& event);
        void stroidLogic(sf::RenderWindow& win);
        void pulseLogic(sf::RenderWindow& win);
        void drawShip(sf::RenderWindow& win);
        void checkCollisions();
};

#endif
