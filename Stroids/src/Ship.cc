/**@file Ship
 * @author Caleb Reister <calebreister@gmail.com>
 * @brief Implementation of @see Ship
 */

#include "Ship.hh"
using namespace std;

Ship::Ship()
{
    radius = 5;
    location = WIN_MID;
    setVelocity(0, 0, 0);
    setAngle(-45);
    state = GOOD;
}

////////////////////////////////////////////////////////////////////////////
/**@fn void Ship::draw()
 * @brief Contains drawing instructions for the ship based on its current state
 * @param explodeAlpha Opacity reduction during ship explosion
 */
void Ship::draw()
{
    JSON::Array color = cfg::getInst()->read["SHIP"]["COLOR"];
    boundFix();

    //explosion variables
    const int STEPS = 100; //resolution (FPS) of explosion, dictates speed
    static int count = 1; //counts times function has been executed
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
        ship.setOutlineColor(sf::Color(color[0].as_int(),
                                       color[1].as_int(),
                                       color[2].as_int()));
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
            ship.setOutlineColor(sf::Color(color[0].as_int(),
                                           color[1].as_int(),
                                           color[2].as_int(),
                                           alpha));
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

    ship.setOutlineThickness(cfg::getInst()->read["SHIP"]["OUTLINE_PX"].as_int());
}

////////////////////////////////////////////////////////////////////////
/**@fn void Ship::render(sf::RenderWindow& win)
 *
 * Renders the ship in the given window and gets position information from the class.
 * Does NOT get input for positioning
 *
 * @param[out] win The window in which to draw the ship
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
    updateLocation();
}

//////////////////////////////////////////////////////////////
/**@fn void Ship::applyThrust(float thrust)
 *
 * Simulates firing the engine. Changes the current velocity based on the
 * angle the ship is facing (it may be facing a different direction than it’s
 * traveling).
 *
 * @param thrust The amount of thrust to apply
 */
void Ship::applyThrust(float thrust)
{
    float rad = util::deg2rad(getAngle());
    chgVelocity(thrust * cos(rad), thrust * sin(rad),
                cfg::getInst()->read["SHIP"]["SPEED"].as_float());
}

/**@fn void Ship::explode()
 * @brief Change the state of the ship to explode, set velocity to 0.
 */
void Ship::explode()
{
    if (state != GONE)
        state = EXPLODE;
    setVelocity(0, 0, 0);
}

/**@fn ShipState getState()
 * @return The state of the ship: GOOD, EXPLODING, or GONE.
 */
ShipState Ship::getState()
{
    return state;
}
