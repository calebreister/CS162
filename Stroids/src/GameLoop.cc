/**@file ShipMain.cc
 * @author Caleb Reister <calebreister@gmail.com
 * @mainpage Stroids is an SFML implementation of asteroids. It has several extensions.
 *  - Color
 *  - A human-readable configuration file
 *  - Object-oriented
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameLogic.hh"

int main()
{
    GameLogic game;
    //Config* cfg = &stroidConfig;

    //initialize SFML window
    sf::RenderWindow window(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y),
                            "'Stroids - Gamma Quadrant",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(cfg::getInst()->read["FRAME_RATE"].as_int());

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
