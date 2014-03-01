/*
 * Graphics.hpp    Feb 28, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: Graphics of asteroids game
 */

#ifndef GAME_GRAPHICS_HPP_
#define GAME_GRAPHICS_HPP_

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.hpp"
#include "config.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "Gun.hpp"

class GameGraphics
{
    private:
        //rendering order
        Asteroid* stroid[MAX_STROIDS] = { NULL };
        Gun* laser[MAX_PULSE] = { NULL };
        Ship ship;
        void fireGun();

    public:
        GameGraphics();
        ~GameGraphics();
        void keyInput();
        void drawStroids(sf::RenderWindow& win);
        void drawPulses(sf::RenderWindow& win);
        void drawShip(sf::RenderWindow& win);
        void checkCollisions();
};

#endif
