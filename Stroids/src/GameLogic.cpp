/*
 * Graphics.cpp    Feb 28, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION:
 */

//#define NDEBUG
#include <cassert>
#include "GameLogic.hpp"

GameLogic::GameLogic()
{
    for (int i = 0; i < START_STROIDS; i++)
        stroid[i] = new Asteroid;
    for (int i = START_STROIDS; i < MAX_STROIDS; i++)
        stroid[i] = NULL;

    for (int i = 0; i < MAX_PULSE; i++)
        laser[i] = NULL;

    gunCool = GUN_COOL_TIME;
}

GameLogic::~GameLogic()
{
    for (int i = 0; i < MAX_STROIDS; i++)
        if (stroid[i] != NULL)
            delete stroid[i];
    for (int i = 0; i < MAX_PULSE; i++)
        delete laser[i];
}

void GameLogic::fireGun()
{
    int i;
    for (i = 0; laser[i] != NULL; i++)
        ;
    laser[i] = new Gun(ship.getLocation(), ship.getAngle());
}

void GameLogic::keyInput()
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

    if (ship.getState() != ShipState::EXPLODE && ship.getState()
            != ShipState::GONE)
    {
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
    }
}

void GameLogic::drawStroids(sf::RenderWindow& win)
{
    for (int i = 0; i < MAX_STROIDS; i++)
    {
        if (stroid[i] != NULL)
        {
            if (stroid[i]->hit)
            {
                delete stroid[i];
                stroid[i] = NULL;
            }
            else
                stroid[i]->draw(win);
        }
    }
}

void GameLogic::drawPulses(sf::RenderWindow& win)
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

void GameLogic::drawShip(sf::RenderWindow& win)
{
    ship.render(win);
    ship.updateLocation();
    ship.render(win);
}

void GameLogic::checkCollisions()
{
    Ship* pShip = &ship;
    for (int iStroid = 0; iStroid < MAX_STROIDS; iStroid++)
    {
        if (stroid[iStroid] != NULL)
        {
            if (objectsIntersect(pShip, stroid[iStroid]))
                pShip->explode();

            for (int iPulse = 0; iPulse < MAX_PULSE; iPulse++)
            {
                if (laser[iPulse] != NULL)
                {
                    if (objectsIntersect(laser[iPulse], stroid[iStroid]))
                    {
                        laser[iPulse]->hit();
                        stroid[iStroid]->hit = true;
                    }
                }
            }
        }
    }
}
