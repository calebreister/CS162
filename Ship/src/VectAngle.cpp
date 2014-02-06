/*
 * PROGRAM: VectAngle
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation file for VectAngle.hpp
 */

#include "VectAngle.hpp"

Angle::deg::deg()
{
    ang = 0;
}

/*
 * FUNCTION: range
 * DESCRIPTION:
 *  ensures that ang is within 0 and 359 ang
 */
void Angle::deg::range()
{
    ang = fmod(ang, 360);
}

/////////////////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: set
 * DESCRIPTION: sets the angle and then forces the range
 * PARAMETERS:
 *  angle - the angle to set, overwrites any previous angle
 */
void Angle::deg::set(float angle)
{
    ang = angle;//accounts for ship creation, which is 90 ang off
}

/*
 * FUNCTION: change
 * DESCRIPTION: changes the angle, adds or subtracts to previous angle
 * PARAMETERS:
 *  difference - the number of ang to add or subtract
 */
void Angle::deg::change(float difference)
{
    ang += difference;
}

/*
 * FUNCTION: get
 * DESCRIPTION: ensures that the angle is between 0 and 359 and returns it.
 *  Can be used to ensure that the number of ang is valid and
 */
float Angle::deg::get()
{
    range();
    return ang;
}

///////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: rad2deg
 * DESCRIPTION: converts radians to degrees
 * PARAMETERS:
 *  rad = the radians to convert, as a float
 * RETURN: the angle (float) in degrees
 */
float Angle::rad2deg(float rad)
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
float Angle::deg2rad(float deg)
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
float Angle::slope2deg(Vect2d slope)
{
    return rad2deg(atan(slope.y / slope.x));
}

float Angle::slope2deg(float slope)
{
    return rad2deg(atan(slope));
}

/*
 * FUNCTION: deg2slope
 * DESCRIPTION: converts ang to a slope for use on
 *  a Cartesian plane, ranged
 * RETURN: slope of angle expressed as a vector
 */
Vect2d Angle::deg2slope(float deg)
{
    Vect2d slope;
    slope.x = cos(deg2rad(deg));
    slope.y = sin(deg2rad(deg));
    return slope;
}
