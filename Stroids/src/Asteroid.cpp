/*
 * PROGRAM: Asteroid
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of ASTEROID_HPP
 */

#include "Asteroid.hpp"
#include <iostream>

Asteroid::Asteroid()
{
    setRadius(util::randInt(30, 60));
    sides = util::randInt(5, 11);
    setLocation(static_cast<float>(util::randInt(0, WIN_SIZE.x)),
                static_cast<float>(util::randInt(0, WIN_SIZE.y)));
    //setLocation(100, 100);
    rotationVel = util::randFloat(.05, .25);
    //setVelocity(util::randFloat(.1, .75), util::randFloat(.1, .75), .75);
    setVelocity(1, 1, 1);
}

/*
 * FUNCTION: draw
 * DESCRIPTION: draw an asteroid
 *  - Change the angle by the rotational velocity amount.
 *  - Then draw the asteroid as a regular polygon of the given number of sides.
 *  - If it’s near an edge (within one radius), you should draw it again off the
 *     opposite edge so the part that is there shows up.
 * PARAMETERS:
 *  win - the window in which to draw the asteroid
 */
void Asteroid::draw(sf::RenderWindow& win)
{
    util::Vect2d loc = getLocation();
    sf::CircleShape stroid(getRadius(), sides);

    //define properties
    stroid.setFillColor(sf::Color(0, 0, 0));
    stroid.setOutlineThickness(5);
    stroid.setOutlineColor(sf::Color(255, 255, 255));

    //update values
    stroid.setPosition(loc.x, loc.y);
    chgAngle(rotationVel);
    stroid.setRotation(getAngle());

    //draw
    updateLocation();
    win.draw(stroid);

    //test code
    sf::CircleShape ctr(2, 4);
    sf::CircleShape circ(getRadius(), 300);
    ctr.setFillColor(sf::Color(255, 255, 255));
    circ.setFillColor(sf::Color(0, 0, 0, 0));
    circ.setOutlineThickness(1);
    circ.setOutlineColor(sf::Color(255, 255, 255));
    circ.setPosition(loc.x, loc.y);
    ctr.setPosition(loc.x, loc.y);
    win.draw(ctr);
    win.draw(circ);
}
