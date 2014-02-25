/*
 * PROGRAM: ShipMain
 * AUTHOR: Caleb Reister
 * DESCRIPTION:
 *  SFML implementation of Ship class, making it move around the screen
 */

#include "util.hpp"
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"

void keyInput(Ship& shp);

int main()
{
    //create ship and asteroids
    Ship player;
    Asteroid* stroid[MAX_STROIDS] = {NULL};
    for (int i = 0; i < 5; i++)
        stroid[i] = new Asteroid;

    ////////////////////////////////////////////////////////////////////
    //initialize SFML window
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

        //get user input
        player.keyCtrl();

        //draw new frame
        window.clear();

        //draw ship
        player.draw(window);
        player.updateLocation();
        player.draw(window);

        for (int i = 0; i < MAX_STROIDS; i++)
        {
            if (stroid[i] != NULL)
                stroid[i]->draw(window);
        }

        //value validation
        //ship
        util::Vect2d vel = player.getVelocity();
        assert(vel.x <= MAX_SPEED);
        assert(vel.x >= -MAX_SPEED);
        assert(vel.y <= MAX_SPEED);
        assert(vel.y >= -MAX_SPEED);
        //stroid
        for (int i; i < MAX_STROIDS; i++)
        {
            if (i < 5)
                assert(stroid[i] != NULL);
            else
                assert(stroid[i] == NULL);
        }

        //redisplay window
        window.display();
    }
    return 0;
}

