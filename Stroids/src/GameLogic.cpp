/*
 * GameLogic.cpp    Feb 28, 2014
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
}

GameLogic::~GameLogic()
{
    for (int i = 0; i < MAX_STROIDS; i++)
        if (stroid[i] != NULL)
            delete stroid[i];
    for (int i = 0; i < MAX_PULSE; i++)
        delete laser[i];
}

/* void fireGun(sf::Event& event)
 * Fires pulses from the ship. Gets event-based input for gunfire.
 *
 * sf::Event& event - the SFML event from which to capture the fire button
 */
void GameLogic::fireGun(sf::Event& event)
{
    if (ship.getState() != GONE && ship.getState() != EXPLODE)
    {
        if (event.type == sf::Event::KeyReleased
            && event.key.code == sf::Keyboard::Space)
        {
            int i;
            for (i = 0; laser[i] != NULL; i++);
            laser[i] = new Pulse(ship.getLocation(), ship.getAngle());
        }
    }
}

/* void keyInput()
 * Gets non-event based user input from the keyboard. Used to control the ship.
 */
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
}

/* void stroidLogic(sf::RenderWindow& win);
 * Allocates and deallocates all asteroids. Draws asteroids.
 *
 * sf::RenderWindow& win - the window in which to render asteroids
 */
void GameLogic::stroidLogic(sf::RenderWindow& win)
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

/* void pulseLogic(sf::RenderWindow& win);
 * Allocates and deallocates all laser pulses. Draws appropriate pulses.
 *
 * sf::RenderWindow& win - window in which to render pulses
 */
void GameLogic::pulseLogic(sf::RenderWindow& win)
{
    for (int i = 0; i < MAX_PULSE; i++)
    {
        if (laser[i] != NULL)
        {
            if (laser[i]->isDead())
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

/* void drawShip(sf::RenderWindow& win)
 * Draws the ship, the Ship class manages destruction internally.
 *
 * sf::RenderWindow& win - window in which to draw the ship
 */
void GameLogic::drawShip(sf::RenderWindow& win)
{
    ship.render(win);
    ship.updateLocation();
    ship.render(win);
}

/* void GameLogic::checkCollisions()
 * Checks all SpaceObjects for collision, performs
 * necessary actions upon collision.
 */
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
