/*
 * PROGRAM: util
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation file for util.hpp
 */

#include "util.hpp"

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
/*
 * FUNCTION randInt
 * DESCRIPTION: Returns a pseudo-random integer between given
 *  low and high values, inclusive
 * PARAMETERS:
 *  low - the lowest number to be generated
 *  high - the highest number to be generated
 * RETURN: A pseudo-random number between low and high (inclusive)
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

/*
 * FUNCTION: randFloat
 * DESCRIPTION: returns a pseudo-random flaot between low and high, inclusive
 * PARAMETERS:
 *  low - lowest number to be generated
 *  high - highest number to be generated
 * RETURN: a pseudo-random float type number
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
/*
 * FUNCTION: rad2deg
 * DESCRIPTION: converts radians to degrees
 * PARAMETERS:
 *  rad = the radians to convert, as a float
 * RETURN: the angle (float) in degrees
 */
float util::rad2deg(float rad)
{
    return (180 * rad) / PI;
}

/*
 * FUNCTION: deg2rad
 * DESCRIPTION: converts ang to radians
 * PARAMTERS:
 *  deg = the ang to convert
 * RETURN:
 *  radians as a float
 */
float util::deg2rad(float deg)
{
    return (PI * deg) / 180;
}

/*
 * FUNCTION: slope2deg
 * DESCRIPTION: gets a slope (either as a vector or a float),
 *  converts it to ang, and stores it
 * PARAMETERS:
 *  slope (vector) - the rise (y) and run (x) values of the slope
 *  slope (float) - the rise and run, pre-divided
 */
float util::slope2deg(Vect2d slope)
{
    return rad2deg(atan(slope.y / slope.x));
}

float util::slope2deg(float slope)
{
    return rad2deg(atan(slope));
}

/*
 * FUNCTION: deg2slope
 * DESCRIPTION: converts ang to a slope for use on
 *  a Cartesian plane, ranged
 * RETURN: slope of angle expressed as a vector
 */
Vect2d util::deg2slope(float deg)
{
    Vect2d slope;
    slope.x = cos(deg2rad(deg));
    slope.y = sin(deg2rad(deg));
    return slope;
}
