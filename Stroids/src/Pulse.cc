/**@file Pulse.cc
 * @brief Implementation of Pulse class.
 */

//#define NDEBUG
#include <cassert>
#include "Pulse.hh"

Pulse::Pulse()
{
    //cfg = &stroidConfig;
    timeToLive = 250;
    radius = 0;
    location = ZERO;
    setVelocity(0, 0, 0);
    setAngle(0);
    color = sf::Color(255, 255, 255);
}

/**@fn Pulse(Vect2d loc, float ang)
 *
 * This is a constructor that passes location and angle data, used to fire a pulse
 * from the ship. It also sets a constant velocity.
 *
 * @param loc The starting location of the pulse
 * @param ang The starting angle of the pulse
 */
Pulse::Pulse(Vect2d loc, float ang)
{
    Vect2d vel = util::deg2slope(ang);
    timeToLive = cfg::getInst()->read["LASER"]["PULSE_LIFE"].as_int();
    radius = 1;
    location = loc;
    setAngle(ang);

    vel *= 100;
    setVelocity(vel, cfg::getInst()->read["SHIP"]["SPEED"].as_float() + 2);
    pulse.setRotation(getAngle());
    pulse.setPosition(loc.x, loc.y);
    pulse.setSize(sf::Vector2f(30, 3));

    JSON::Array userColor = cfg::getInst()->read["LASER"]["COLOR"];
    color = sf::Color(userColor[0].as_int(),
                      userColor[1].as_int(),
                      userColor[2].as_int());
}

/**@fn void Pulse::hit()
 *
 * Sets timeToLive to 0, invoking the draw function will
 * cause the pulse to disappear.
 */
void Pulse::hit()
{
    timeToLive = 0;
}

/**@fn bool Pulse::isDead()
 * @brief Checks to see if the pulse has hit anything.
 * @return Whether or not timeToLive == 0
 */
bool Pulse::isDead()
{
    assert(timeToLive >= 0);
    if (timeToLive == 0)
        return true;
    else
        return false;
}

/**@fn void Pulse::draw(sf::RenderWindow& win)
 * @brief Draws the pulse on the screen where and when appropriate.
 * @param[out] win - the window in which to draw the pulse.
 */
void Pulse::draw(sf::RenderWindow& win)
{
    Vect2d loc = getLocation();

    pulse.setPosition(loc.x, loc.y);
    pulse.setFillColor(sf::Color(color));

    win.draw(pulse);
    timeToLive--;
    updateLocation();

    if (!cfg::getInst()->read["LASER"]["EDGE_DEATH"].as_bool())
        boundFix();
}
