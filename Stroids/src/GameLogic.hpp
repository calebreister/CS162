/*
 * Graphics.hpp    Feb 28, 2014
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
#include "util.hpp"
#include "config.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "Gun.hpp"

class GameLogic
{
    private:
        //rendering order
        Asteroid* stroid[MAX_STROIDS];
        Gun* laser[MAX_PULSE];
        Ship ship;
        int gunCool;
        void fireGun();

    public:
        GameLogic();
        ~GameLogic();
        void keyInput();
        void drawStroids(sf::RenderWindow& win);
        void drawPulses(sf::RenderWindow& win);
        void drawShip(sf::RenderWindow& win);
        void checkCollisions();
};

#endif