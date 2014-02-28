/*
 * PROGRAM: Ship
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation of Ship.hpp
 */
#include "config.hpp"
#include "Ship.hpp"
using namespace std;

Ship::Ship()
{
    setRadius(5);
    setLocation(WIN_MID.x, WIN_MID.y);
    setVelocity(0, 0, 0);
    setAngle( -45);
    state = GOOD;
}

////////////////////////////////////////////////////////////////////////////
/*
 * draw()
 * contains drawing instructions for the ship based on its current state
 *
 * PARAMETERS:
 * explodeAlpha - Alpha reduction during ship explosion
 */
void Ship::draw()
{
    //explosion variables
    const int STEPS = 100; //resolution (FPS) of explosion, dictates speed
    static int count = 1;//counts times function has been executed
    static int alpha = 255; //sets alpha (aka opacity)
    static float size = 1;

    //map the points
    ship.setPointCount(3);
    ship.setPoint(0, sf::Vector2f(10, 0));
    ship.setPoint(1, sf::Vector2f(0, 25));
    ship.setPoint(2, sf::Vector2f(20, 25));

    //check the state of the ship
    if (state == GOOD)
    {
        ship.setFillColor(sf::Color(0, 0, 0));
        ship.setOutlineColor(sf::Color(255, 0, 0));
    }
    else if (state == EXPLODE)
    {
        //increment explosion variables
        count += 1;
        size += .005;
        alpha -= (255 / STEPS);

        if (count <= STEPS)
        {
            ship.setScale(size, size);
            ship.setFillColor(sf::Color(0, 0, 0, alpha));
            ship.setOutlineColor(sf::Color(255, 0, 0, alpha));
        }
        else
            state = GONE;
    }
    else
    {
        ship.setFillColor(sf::Color(0, 0, 0, 0));
        ship.setOutlineColor(sf::Color(0, 0, 0, 0));
        count = 0;
    }

    ship.setOutlineThickness(1);
}

////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: keyInput
 * DESCRIPTION: gets keyboard input for controlling the ship
 */
/*void Ship::keyCtrl()
{
    if (state == GOOD)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            chgAngle( -TURN_RATE);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            chgAngle(TURN_RATE);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            applyThrust(.05);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            applyThrust( -.05);
    }
}*/

/*
 * FUNCTIOPN: render
 * DESCRIPTION: renders the ship in the given window
 *  and gets position information from the class.
 *  Does NOT get input for positioning
 * PARAMETERS:
 *  win - the window in which to draw the ship
 */
void Ship::render(sf::RenderWindow& win)
{
    Vect2d loc = getLocation();

    sf::Vector2f midpoint(10, 15);
    ship.setOrigin(midpoint);
    ship.setPosition(loc.x, loc.y);
    ship.setRotation(getAngle() + 90);

    draw();
    win.draw(ship);
}

//////////////////////////////////////////////////////////////

/*
 * FUNCTION: applyThrust
 * DESCRIPTION:
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * traveling).
 */
void Ship::applyThrust(float thrust)
{
    float rad = util::deg2rad(getAngle());
    chgVelocity(thrust * cos(rad), thrust * sin(rad), MAX_SPEED);
}

/*
 * explode()
 * Change the state of the ship to explode, set velocity to 0.
 */
void Ship::explode()
{
    if (state != GONE)
        state = EXPLODE;
    setVelocity(0, 0, 0);
}

ShipState Ship::getState()
{
    return state;
}
