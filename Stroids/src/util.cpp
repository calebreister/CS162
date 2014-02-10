/*
 * PROGRAM: VectAngle
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation file for VectAngle.hpp
 */

#include "util.hpp"

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
util::Vect2d util::deg2slope(float deg)
{
    Vect2d slope;
    slope.x = cos(deg2rad(deg));
    slope.y = sin(deg2rad(deg));
    return slope;
}
