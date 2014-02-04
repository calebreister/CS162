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
#include "Ship.hpp"

void keyInput(Ship ship);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(refHz);
    //////////////////////////////////////////////////////////////////////
    Ship ship;

    while (window.isOpen())
    {
        //handle user input (events and keyboard keys being pressed)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Get Keyboard Input
        keyInput(ship);

        //draw new frame
        window.clear();

        ship.draw(window);
        ship.updateLocation();
        ship.draw(window);

        //redisplay window
        window.display();
    }
    return 0;
}

/*
 * FUNCTION: keyInput
 * DESCRIPTION: gets keyboard input for controlling the space ship
 * PARAMETERS:
 *  ship - the ship object to use
 */
void keyInput(Ship ship)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ship.rotateLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ship.rotateRight();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        ship.applyThrust(3);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        ship.applyThrust(-1);
}
