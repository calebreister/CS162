/*
 * PROGRAM: ShipMain
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  SFML implementation of Ship class, making it move around the screen
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameLogic.hpp"

int main()
{
    GameLogic game;
    //Config* cfg = &stroidConfig;

    //initialize SFML window
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "'Stroids - Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(cfg.read["FRAME_RATE"].as_int());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

                game.fireGun(event);
        }

        game.keyInput();

        window.clear();
        game.stroidLogic(window);
        game.pulseLogic(window);
        game.drawShip(window);
        game.checkCollisions();

        window.display();
    }
    //delete cfg;
    return 0;
}
