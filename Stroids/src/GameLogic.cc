/**@file GameLogic.cc
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief Graphics and operation of the asteroids game
 */

//#define NDEBUG
#include <cassert>
#include "GameLogic.hh"

GameLogic::GameLogic()
{
    //cfg = &stroidConfig;
    for (int i = 0; i < cfg::getInst()->read["STROID"]["START_NUM"].as_int(); i++)
        stroid[i] = new Asteroid;
    for (int i = cfg::getInst()->read["STROID"]["START_NUM"].as_int();
            i < MAX_STROIDS; i++)
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
    //delete cfg;
}

/**@fn int findFreeStroid()
 * @brief Finds a free asteroid within the pointer array of asteroids
 * @return The index of a free (NULL) space in the asteroid array.
 */
int GameLogic::findFreeStroid()
{
    int i = 0;
    while (i < MAX_STROIDS)
    {
        if (stroid[i] == NULL)
        {
            //std::cout << i << std::endl;
            return i;
        }
        i++;
    }
    std::cerr << "Error: asteroid memory full. New asteroid not created." << std::endl;
    return -1; //Error: no memory
}

/**
 * Gets non-event based user input from the keyboard. Used to control the ship.
 */
void GameLogic::keyInput()
{
    if (ship.getState() == GOOD)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.chgAngle(-(cfg::getInst()->read["SHIP"]["TURN_RATE"].as_float()));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.chgAngle(cfg::getInst()->read["SHIP"]["TURN_RATE"].as_float());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ship.applyThrust(cfg::getInst()->read["SHIP"]["THRUST_FWD"].as_float());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ship.applyThrust(cfg::getInst()->read["SHIP"]["THRUST_REV"].as_float());
    }
}

/**@fn void GameLogic::fireGun(sf::Event& event)
 * @brief Fires pulses from the ship. Gets event-based input for gunfire.
 * @param[in] event The SFML event from which to capture the fire button
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

/**@fn void GameLogic::stroidLogic(sf::RenderWindow& win);
 * @brief Allocates and deallocates all asteroids. Draws asteroids.
 * @param[out] win The window in which to render the asteroids
 */
void GameLogic::stroidLogic(sf::RenderWindow& win)
{
    static int count = 0;

    for (int i = 0; i < MAX_STROIDS; i++)
    {
        if (stroid[i] != NULL)
        {
            //if an asteroid is destroyed...
            if (stroid[i]->hit)
            {
                if (stroid[i]->split)
                {
                    //destroy the asteroid
                    delete stroid[i];
                    stroid[i] = NULL;
                }
                else
                {
                    //create 2 new asteroids
                    if (findFreeStroid() != -1)
                    {
                        stroid[findFreeStroid()] = new Asteroid(stroid[i]);
                        stroid[findFreeStroid()] = new Asteroid(stroid[i]);
                    }
                    delete stroid[i];
                    stroid[i] = NULL;
                }
            }
            else
                stroid[i]->draw(win);
        }
    }

    count++;
    if (count == cfg::getInst()->read["STROID"]["SPAWN_RATE"].as_int())
    {
        count = 0;
        stroid[findFreeStroid()] = new Asteroid();
    }
}

/**@fn void GameLogic::pulseLogic(sf::RenderWindow& win);
 * @brief Allocates and deallocates all laser pulses. Draws appropriate pulses.
 * @param[out] win - window in which to render pulses
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

/**@fn void GameLogic::drawShip(sf::RenderWindow& win)
 * @brief Draws the ship, the Ship class manages destruction internally.
 * @param win Window in which to draw the ship
 */
void GameLogic::drawShip(sf::RenderWindow& win)
{
    ship.render(win);
}

/**@fn void GameLogic::checkCollisions()
 * @brief Checks all SpaceObjects for collision, performs necessary actions upon collision.
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
