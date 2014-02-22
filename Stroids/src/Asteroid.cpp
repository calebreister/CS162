/*
 * PROGRAM: Asteroid
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of ASTEROID_H
 */

#include "Asteroid.hpp"

Asteroid::Asteroid()
{
    setRadius(util::randInt(30, 60));
    sides = util::randInt(5, 11);
    setLocation(static_cast<float>(util::randInt(0, WIN_SIZE.x)),
                static_cast<float>(util::randInt(0, WIN_SIZE.y)));
    //setLocation(400, 400);
    rotationVel = util::randFloat( -.1, .1);
    setVelocity(util::randFloat( -.5, .5), util::randFloat( -.5, .5), .75);
    //setVelocity(1, 1, 1);
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
    stroid.setOrigin(getRadius(), getRadius());
    stroid.setFillColor(sf::Color(0, 0, 0, 0));
    stroid.setOutlineThickness(5);
    stroid.setOutlineColor(sf::Color(255, 255, 255));

    //update values
    stroid.setRotation(getAngle());
    stroid.setPosition(loc.x, loc.y);
    chgAngle(rotationVel);
    stroid.rotate(rotationVel);
    updateLocation();

    //draw
    win.draw(stroid);

    //run edge and corner checks, correct issues
    //Corners must be checked first, if they are not, there is
      //a rendering issue
    if (checkSide(bottom) && checkSide(right))
    {
        stroid.setPosition( -(WIN_SIZE.x - loc.x), -(WIN_SIZE.y - loc.y));
        stroid.setRotation(getAngle());
        win.draw(stroid);
    }
    else if (checkSide(left) && checkSide(top))
    {
        stroid.setPosition(WIN_SIZE.x + loc.x, WIN_SIZE.y + loc.y);
        stroid.setRotation(getAngle());
        win.draw(stroid);
    }
    else if (checkSide(right) && checkSide(top))
    {
        stroid.setPosition( -(WIN_SIZE.x - loc.x), WIN_SIZE.y + loc.y);
        stroid.setRotation(getAngle());
        win.draw(stroid);
    }
    else if (checkSide(left) && checkSide(bottom))
    {
        stroid.setPosition(WIN_SIZE.x + loc.x, -(WIN_SIZE.y - loc.y));
        stroid.setRotation(getAngle());
        win.draw(stroid);
    }
    else
    {
        //X
        if (checkSide(right))
        {
            stroid.setPosition( -(WIN_SIZE.x - loc.x), loc.y);
            stroid.setRotation(getAngle());
            win.draw(stroid);
        }
        else if (checkSide(left))
        {
            stroid.setPosition(WIN_SIZE.x + loc.x, loc.y);
            stroid.setRotation(getAngle());
            win.draw(stroid);
        }
        //Y
        if (checkSide(bottom))
        {
            stroid.setPosition(loc.x, -(WIN_SIZE.y - loc.y));
            stroid.setRotation(getAngle());
            win.draw(stroid);
        }
        else if (checkSide(top))
        {
            stroid.setPosition(loc.x, WIN_SIZE.y + loc.y);
            stroid.setRotation(getAngle());
            win.draw(stroid);
        }
    }
}

/*
 * FUNCTION: checkSide
 * DESCRIPTION: check a side of the screen to see if an
 *  asteroid's radius crosses an edge of the screen
 * PARAMETERS:
 *  s - the side to check
 * RETURN: whether or not the asteroid's radius crosses the given side
 */
bool Asteroid::checkSide(Side s)
{
    /*
     * NOTE: this is not the simplest method, but the other requires extra functions,
     * passing a location COMPONENT that is correct (*.y for top/bottom, *.x for left/right,
     * passing the entire location vector would be pointless for individual functions). This method is
     * also more self-documenting. In addition, no mathematical evaluation is required when
     * checking a side as it was already passed in the parameter. In addition, the switch
     * is a very streamlined method of writing this code, any other method would require significantly
     * more unnecessary whitespace. Based off of my understanding, this is the fastest method.
     */

    static util::Vect2d loc; //static prevents memory from having to be re-allocated repeatedly
    loc = getLocation();
    switch (s)
    {
        case left:
            return (loc.x - getRadius() < ZERO.x) ? true : false;
            break;
        case right:
            return (loc.x + getRadius() > WIN_SIZE.x) ? true : false;
            break;
        case top:
            return (loc.y - getRadius() < ZERO.y) ? true : false;
            break;
        case bottom:
            return (loc.y + getRadius() > WIN_SIZE.y) ? true : false;
            break;
    }
    //no outside return required, this switch has to be entered and not doing so correctly
    //will cause a compile time error.
}
