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
#include "util.hpp"
#include "config.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "Gun.hpp"

int main()
{
    //create ship and asteroids
    Asteroid* stroid[MAX_STROIDS] = { NULL };
    Gun* laser[MAX_LASER_PULSE] = { NULL };
    Ship player;

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

        //draw stroid
        for (int i = 0; i < MAX_STROIDS; i++)
        {
            if (stroid[i] != NULL)
            {
                stroid[i]->draw(window);
                if (objectsIntersect(player, stroid[i]))
                    player.explode();
            }
        }

        //draw ship
        player.render(window);
        player.updateLocation();
        player.render(window);

        //laser
/*        if (event.type == sf::Event::KeyPressed && event.key.code
                                                   == sf::Keyboard::Space)
        {
            for (int i = 0; i < MAX_LASER_PULSE; i++)
            {
                if (laser[i] == NULL)
                {*/
                    int i = 0;
                    if (laser[i] == NULL)
                        laser[i] = new Gun(player.getLocation(), player.getAngle());
                    if (laser[i]->dead())
                        delete laser[i];
                    else
                        laser[i]->draw(window);
                    /*break;
                }
            }
            assert(laser[0] != NULL);
        }*/

        /////////////////TEST CODE//////////////////////
        //ship
        Vect2d vel = player.getVelocity();
        assert(vel.x <= MAX_SPEED);
        assert(vel.x >= -MAX_SPEED);
        assert(vel.y <= MAX_SPEED);
        assert(vel.y >= -MAX_SPEED);
        /////////////////END TEST CODE////////////////////

        //redisplay window
        window.display();
    }
    return 0;
}
