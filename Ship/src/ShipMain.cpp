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
        shp.rotateLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shp.rotateRight();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
//        for (i = 0; i < 3; i += .00001)
            shp.applyThrust(.1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shp.applyThrust( -1);
}
