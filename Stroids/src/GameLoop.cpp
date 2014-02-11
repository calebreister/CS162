/*
 * PROGRAM: ShipMain
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  SFML implementation of Ship class, making it move around the screen
 */

//#define NDEBUG
#include <cassert>
#include <cmath>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "util.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"

Ship player;
Asteroid stroid;
void keyInput(Ship& shp = player);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "'Stroids - Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(REF_HZ);
    ////////////////////////////////////////////////////////////////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        keyInput();

        //draw new frame
        window.clear();
        player.draw(window);
        player.updateLocation();
        player.draw(window);
        stroid.draw(window);

        //value validation
        util::Vect2d vel = player.getVelocity();
        //std::cout << vel.x << "   " << vel.y << std::endl;
        assert(vel.x <= MAX_SPEED);
        assert(vel.x >= -MAX_SPEED);
        assert(vel.y <= MAX_SPEED);
        assert(vel.y >= -MAX_SPEED);

        //redisplay window
        window.display();
    }
    return 0;
}

/*
 * FUNCTION: keyInput
 * DESCRIPTION: gets keyboard input for controlling the space player
 * PARAMETERS:
 *  shp - the ship object to use as the player
 */
void keyInput(Ship& shp)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shp.chgAngle( -TURN_RATE);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shp.chgAngle(TURN_RATE);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shp.applyThrust(.05);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shp.applyThrust( -.05);
}
