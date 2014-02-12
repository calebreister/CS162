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
    rotationVel = util::randFloat(-.1, .1);
    setVelocity(util::randFloat(-.5, .5), util::randFloat(-.5, .5), .75);
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
    sf::Transform centerRotate;

    //define centerRotate
    centerRotate.rotate(getAngle(), loc.x + getRadius(),
                        loc.y + getRadius());

    //define properties
    stroid.setFillColor(sf::Color(0, 0, 0, 0));
    stroid.setOutlineThickness(5);
    stroid.setOutlineColor(sf::Color(255, 255, 255));

    //update values
    stroid.setPosition(loc.x, loc.y);
    chgAngle(rotationVel);

    //draw
    updateLocation();
    win.draw(stroid, centerRotate);
}
