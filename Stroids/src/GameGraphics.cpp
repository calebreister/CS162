/*
 * Graphics.cpp    Feb 28, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION:
 */

//#define NDEBUG
#include <cassert>
#include "GameGraphics.hpp"

GameGraphics::GameGraphics()
{
    for (int i = 0; i < START_STROIDS; i++)
        stroid[i] = new Asteroid;
    for (int i = START_STROIDS; i < MAX_STROIDS; i++)
        stroid[i] = NULL;

    for (int i = 0; i < MAX_PULSE; i++)
        laser[i] = NULL;

    gunCool = GUN_COOL_TIME;
}

GameGraphics::~GameGraphics()
{
    for (int i = 0; i < MAX_STROIDS; i++)
        if (stroid[i] != NULL)
            delete stroid[i];
    for (int i = 0; i < MAX_PULSE; i++)
        delete laser[i];
}

void GameGraphics::fireGun()
{
    int i;
    for (i = 0; laser[i] != NULL; i++);
    laser[i] = new Gun(ship.getLocation(), ship.getAngle());
}

void GameGraphics::keyInput()
{
    if (ship.getState() == GOOD)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.chgAngle(-TURN_RATE);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.chgAngle(TURN_RATE);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ship.applyThrust(.05);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ship.applyThrust(-.05);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (gunCool == 0)
        {
            fireGun();
            gunCool = GUN_COOL_TIME;
        }
        else
            gunCool--;
    }

    //EVENT BELOW DOES NOT WORK
    /*sf::Event event;
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            std::cout << "space pressed" << std::endl;
        }
    }*/
}

void GameGraphics::drawStroids(sf::RenderWindow& win)
{
    for (int i = 0; i < MAX_STROIDS; i++)
    {
        if (stroid[i] != NULL)
            stroid[i]->draw(win);
    }
}

void GameGraphics::drawPulses(sf::RenderWindow& win)
{
    for (int i = 0; i < MAX_PULSE; i++)
    {
        if (laser[i] != NULL)
        {
            if (laser[i]->pulseDead())
            {
                delete laser[i];
                laser[i] = NULL; //prevents program from cashing
                                 //not sure why
            }
            else
                laser[i]->draw(win);
        }
    }
}

void GameGraphics::drawShip(sf::RenderWindow& win)
{
    ship.render(win);
    ship.updateLocation();
    ship.render(win);
}

void GameGraphics::checkCollisions()
{
    Ship* pShip = &ship;
    for (int i = 0; i < MAX_STROIDS; i++)
    {
        if (stroid[i] != NULL)
        {
            if (objectsIntersect(pShip, stroid[i]))
                pShip->explode();
        }
    }
}
