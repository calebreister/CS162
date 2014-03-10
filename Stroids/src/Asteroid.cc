/*
 * PROGRAM: Asteroid
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of ASTEROID_H
 */

//#define NDEBUG
#include <cassert>
#include "Asteroid.hh"

Asteroid::Asteroid()
{
    //cfg = &stroidConfig;

    //initialize variables
    radius = util::randInt(cfg::getInst()->read["STROID"]["SIZE_MIN"].as_int(),
                           cfg::getInst()->read["STROID"]["SIZE_MAX"].as_int());
    sides = util::randInt(6, 12);
    Vect2d loc = {util::randFloat(0, WIN_SIZE.x),
                  util::randFloat(0, WIN_SIZE.y)};

    //check/correct location bounds
    if (checkLocBound(pp, loc))
        loc += 100;
    else if (checkLocBound(nn, loc))
        loc -= 100;
    else if (checkLocBound(pn, loc))
    {
        loc.x += 100;
        loc.y -= 100;
    }
    else if (checkLocBound(np, loc))
    {
        loc.x -= 100;
        loc.y += 100;
    }

    //set values
    location = {loc.x, loc.y};
    //setLocation(400, 400);
    rotationVel = util::randFloat(-.1, .1);
    setVelocity(util::randFloat(-cfg::getInst()->read["STROID"]["MAX_SPEED"].as_float(),
                                cfg::getInst()->read["STROID"]["MAX_SPEED"].as_float()),
                util::randFloat(-cfg::getInst()->read["STROID"]["MAX_SPEED"].as_float(),
                                cfg::getInst()->read["STROID"]["MAX_SPEED"].as_float()),
                cfg::getInst()->read["STROID"]["MAX_SPEED"].as_float() + .5);
    //setVelocity(1, 1, 1);

    if (cfg::getInst()->read["STROID"]["COLOR_RAND"].as_bool() == true)
        color = sf::Color(util::randInt(util::randInt(0, 100), 255),
                          util::randInt(util::randInt(0, 100), 255),
                          util::randInt(util::randInt(0, 100), 255));
    else
    {
        JSON::Array userColor = cfg::getInst()->read["STROID"]["COLOR"];
        color = sf::Color(userColor[0].as_int(),
                          userColor[1].as_int(),
                          userColor[2].as_int());
    }
    //color = sf::Color(255, 255, 255);

    hit = false;
    split = false;
}

/* Asteroid(Vect2d loc)
 * Asteroid constructor with a definite starting location, used for asteroids
 * that have been hit once and split. Due to the split status, it has several other
 * non-random properties.
 *
 * Asteroid* old - the asteroid from which to base the new one
 */
Asteroid::Asteroid(Asteroid* old)
{
    //initialize variables
    radius = old->radius / 2;
    sides = old->sides / 2;

    //set values
    location = old->location;
    rotationVel = util::randFloat(-.1, .1);
    setVelocity(util::randFloat(-.5, .5), util::randFloat(-.5, .5), .75);

    color = old->color;

    hit = false;
    split = true;
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
     * passing the entire location vector would be pointless for individual functions).
     * This method is also more self-documenting. In addition, no mathematical evaluation is
     * required when checking a side as it was already passed in the parameter. In addition,
     * the switch is a very streamlined method of writing this code, any other method would
     * require significantly more unnecessary whitespace. Based off of my understanding,
     * this is the fastest method.
     */

    static Vect2d loc; //static prevents memory from having to be re-allocated repeatedly
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
    return false;
}

/* void checkLocBound(Quadrant quad, Vect2d loc, Vect2d point,
 *                              int radius)
 * Checks to see if an asteroid is going to spawn too close
 * to a pointer with a given radius
 *
 * quadrant - string stating which quadrant can be checked, uses a graph
 *            with loc as the origin.
 *            pp covers points (x, y)
 *            nn covers points (-x, -y)
 *            pn covers points (x, -y)
 *            np covers points (-x, y)
 * loc - the location of the object
 * point - the point to avoid
 * radius - defines the space around the point to avoid
 *
 * if ++ and within radius of point return true
 * if -- and within radius of point return true
 * if +- and within radius of point return true
 * if -+ and within radius of point return true
 * else return false
 */
bool Asteroid::checkLocBound(Quadrant quad, Vect2d loc, Vect2d point,
                             int radius)
{
    assert(quad == pp
           || quad == nn
           || quad == pn
           || quad == np);

    switch (quad)
    {
        case pp:
            if (loc.x > point.x
                && loc.y > point.y
                && loc.x < point.x + radius
                && loc.y < point.y + radius)
                return true;
            else
                return false;
            break;
        case nn:
            if (loc.x < point.x
                && loc.y < point.y
                && loc.x > point.x - radius
                && loc.y > point.y - radius)
                return true;
            else
                return false;
            break;
        case pn:
            if (loc.x > point.x
                && loc.y < point.y
                && loc.x < point.x + radius
                && loc.y > point.y - radius)
                return true;
            else
                return false;
            break;
        case np:
            if (loc.x < point.x
                && loc.y > point.y
                && loc.x > point.x - radius
                && loc.y < point.y + radius)
                return true;
            else
                return false;
            break;
    }
    return false; //this line should never run, something is wrong if it does
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
    boundFix();

    Vect2d loc = getLocation();
    sf::CircleShape stroid(getRadius(), sides);

    //define properties
    stroid.setOrigin(getRadius(), getRadius());
    stroid.setFillColor(sf::Color(0, 0, 0));
    stroid.setOutlineThickness(5);
    stroid.setOutlineColor(color);

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
        stroid.setPosition(-(WIN_SIZE.x - loc.x), -(WIN_SIZE.y - loc.y));
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
        stroid.setPosition(-(WIN_SIZE.x - loc.x), WIN_SIZE.y + loc.y);
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
            stroid.setPosition(-(WIN_SIZE.x - loc.x), loc.y);
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
