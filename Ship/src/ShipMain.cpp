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
#include "VectAngle.hpp"
#include "Ship.hpp"

Ship player;
void keyInput(float& i, Ship& shp = player);

int main()
{
    float iter; //used for keyboard input acceleration loops
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(refHz);
    //////////////////////////////////////////////////////////////////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        keyInput(iter);

        //draw new frame
        window.clear();
        player.draw(window);
        player.updateLocation();
        player.draw(window);

        Vect2d vel = player.getVelocity();
        std::cout << vel.x << "   " << vel.y << std::endl;
        assert(vel.x <= 3);
        assert(vel.x >= -3);
        assert(vel.y <= 3);
        assert(vel.y >= -3);

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
 *  i - iterator for loops
 */
void keyInput(float& i, Ship& shp)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shp.angle.change( -1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shp.angle.change(1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shp.applyThrust(both);

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //    shp.applyThrust();
}
