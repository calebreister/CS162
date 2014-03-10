/*
 * GameLogic.hh    Feb 28, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Graphics of asteroids game
 */

#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "Ship.hh"
#include "Asteroid.hh"
#include "Pulse.hh"

class GameLogic
{
    private:
        //rendering order
        Asteroid* stroid[MAX_STROIDS];
        Pulse* laser[MAX_PULSE];
        Ship ship;
        int findFreeStroid();
        //Config* cfg;

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
