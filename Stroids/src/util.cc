/**@file util
 * @author Caleb Reister <calebreister@gmail.com>
 *
 * This file contains various useful definitions...
 * - Vect2d is a simple vector struct with multiple operator overloads
 * - @see cfg A singleton class that works with a JSON configuration file.
 * - @see util
 */

#include "util.hh"
using namespace std;
using namespace JSON;

//////////////////////////////////////////////////////////////////
//Operator overloads for Vect2d
std::ostream& operator<<(std::ostream& out, const Vect2d& in)
{
    out << "(" << in.x << ", " << in.y << ")";
    return out;
}
Vect2d operator+(const Vect2d& in, float op)
{
    Vect2d result;
    result.x = in.x + op;
    result.y = in.y + op;
    return result;
}
Vect2d operator-(const Vect2d& in, float op)
{
    Vect2d out;
    out.x = in.x - op;
    out.y = in.y - op;
    return out;
}
Vect2d operator*(const Vect2d& in, float op)
{
    Vect2d out;
    out.x = in.x * op;
    out.y = in.y * op;
    return out;
}
Vect2d operator/(const Vect2d& in, float op)
{
    Vect2d out;
    out.x = in.x / op;
    out.y = in.y / op;
    return out;
}
void operator+=(Vect2d& out, float op)
{
    out.x += op;
    out.y += op;
}
void operator-=(Vect2d& out, float op)
{
    out.x -= op;
    out.y -= op;
}
void operator*=(Vect2d& out, float op)
{
    out.x *= op;
    out.y *= op;
}
void operator/=(Vect2d& out, float op)
{
    out.x /= op;
    out.y /= op;
}
////////////////////////////////////////////////////////////////////////
/**@fn int util::randInt(int low, int high)
 * @brief Returns a pseudo-random integer between given low and high values, inclusive
 * @param low The lowest number to be generated
 * @param high The highest number to be generated
 * @return A pseudo-random number between low and high (inclusive)
 */
int util::randInt(int low, int high)
{
    static bool firstTime = true;
    int randNum;

    //if first time called, seed random number generator
    if (firstTime)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        firstTime = false;
    }

    //generate random number between given low and high values (inclusive)
    randNum = rand() % (high - low + 1) + low;
    return randNum;
}

/**@fn float util::randFloat(float low, float high)
 * @brief Same as randInt but returns a float.
 * @param low The lowest number to be generated
 * @param high The highest number to be generated
 * @return A pseudo-random number between low and high (inclusive)
 */
float util::randFloat(float low, float high)
{
    static bool firstTime = true;
    float randNum;

    //if first time called, seed random number generator
    if (firstTime)
    {
        srand(static_cast<float>(time(NULL)));
        firstTime = false;
    }

    //generate the random number
    randNum = fmod(0.01 * rand(), (high - low + 1) + low);
    if (randInt(0, 1) == 1)
        randNum *= -1;
    return randNum;
}

///////////////////////////////////////////////////////////////////////////////
/**@fn float util::rad2deg(float rad)
 * @brief Converts radians to degrees.
 * @param rad The radians to convert, as a float
 * @return The angle (float) in degrees.
 */
float util::rad2deg(float rad)
{
    return (180 * rad) / PI;
}

/**@fn float util::deg2rad(float deg)
 * @brief Converts degress to radians.
 * @param deg The ang to convert.
 * @return Radians as a float.
 */
float util::deg2rad(float deg)
{
    return (PI * deg) / 180;
}

/**@fn float util::slope2deg(Vect2d slope)
 * @brief Gets a slope and converts it to degrees.
 * @param slope The rise (y) and run (x) values of the slope
 * @return The angle of the slope in degress.
 */
float util::slope2deg(Vect2d slope)
{
    return rad2deg(atan(slope.y / slope.x));
}
/**@fn float util::slope2deg(Vect2d slope)
 * @brief Gets a slope and converts it to degrees.
 * @param slope The rise / run, pre-divided.
 * @return The angle of the slope in degress.
*/
float util::slope2deg(float slope)
{
    return rad2deg(atan(slope));
}

/**@fn Vect2d util::deg2slope(float deg)
 * @brief Converts an angle to a slope for use on a Cartesian plane, ranged.
 * @param deg The slope as a vector.
 * @return Slope of angle expressed as a vector
 */
Vect2d util::deg2slope(float deg)
{
    Vect2d slope;
    slope.x = cos(deg2rad(deg));
    slope.y = sin(deg2rad(deg));
    return slope;
}
