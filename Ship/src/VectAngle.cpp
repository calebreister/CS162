/*
 * PROGRAM: VectAngle
 * AUTHOR: Caleb Reister
 * DESCRIPTION: implementation file for VectAngle.hpp
 */

#include "VectAngle.hpp"

AngleDeg::AngleDeg()
{
    degrees = 0;
}

/*
 * FUNCTION: range
 * DESCRIPTION:
 *  ensures that degrees is within 0 and 359 degrees
 */
void AngleDeg::range()
{
    degrees = fmod(degrees, 360);
}

/*
 * FUNCTION: toRadians
 * DESCRIPTION: converts degrees to radians
 * PARAMTERS:
 *  deg = the degrees to convert
 * RETURN:
 *  radians as a float
 */
float AngleDeg::toRadians(float deg)
{
    return (PI * deg) / 180;
}

/*
 * FUNCTION: toDegrees
 * DESCRIPTION: converts radians to degrees
 * PARAMETERS:
 *  rad = the radians to convert, as a float
 * RETURN: the degrees (float)
 */
float AngleDeg::toDegrees(float rad)
{
    return (180 * rad) / PI;
}

/////////////////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: set
 * DESCRIPTION: sets the angle and then forces the range
 * PARAMETERS:
 *  angle - the angle to set, overwrites any previous angle
 */
void AngleDeg::set(float angle)
{
    degrees = angle;//accounts for ship creation, which is 90 degrees off
}

/*
 * FUNCTION: change
 * DESCRIPTION: changes the angle, adds or subtracts to previous angle
 * PARAMETERS:
 *  difference - the number of degrees to add or subtract
 */
void AngleDeg::change(float difference)
{
    degrees += difference;
}

/*
 * FUNCTION: radiansIn
 * DESCRIPTION: converts radians to degrees and stores the angle
 * PARAMETERS:
 *  radians - the input angle in radians
 */
void AngleDeg::setRadians(float radians)
{
    degrees = toDegrees(radians);
}

/*
 * FUNCTION: slopeIn
 * DESCRIPTION: gets a slope (either as a vector or a float),
 *  converts it to degrees, and stores it
 * PARAMETERS:
 *  slope (vector) - the rise (y) and run (x) values of the slope
 *  slope (float) - the rise and run, pre-divided
 */
void AngleDeg::setSlope(Vect2d slope)
{
    degrees = toDegrees(atan(slope.y / slope.x));
}

void AngleDeg::setSlope(float slope)
{
    degrees = toDegrees(atan(slope));
}

///////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION: get
 * DESCRIPTION: ensures that the angle is between 0 and 359 and returns it.
 *  Can be used to ensure that the number of degrees is valid and
 */
float AngleDeg::get()
{
    range();
    return degrees;
}

/*
 * FUNCTION: getRadians
 * DESCRIPTION: converts degrees to radians, ranged
 * RETURN: radians
 */
float AngleDeg::getRadians()
{
    range();
    return toRadians(degrees);
}

/*
 * FUNCTION: getSlope
 * DESCRIPTION: converts degrees to a slope for use on
 *  a Cartesian plane, ranged
 * RETURN: slope of angle expressed as a vector
 */
Vect2d AngleDeg::getSlope()
{
    Vect2d slope;
    slope.x = cos(toRadians(degrees));
    slope.y = sin(toRadians(degrees));
    return slope;
}
