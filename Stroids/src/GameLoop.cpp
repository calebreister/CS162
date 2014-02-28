/*
 * PROGRAM: ShipMain
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  SFML implementation of Ship class, making it move around the screen
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameGraphics.hpp"

int main()
{
    GameGraphics game;

    //initialize SFML window
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "'Stroids - Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(REF_HZ);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.keyInput();

        window.clear();
        game.drawStroids(window);
        //game.drawPulses(window);
        game.drawShip(window);
        game.checkCollisions();

        window.display();
    }
    return 0;
}
