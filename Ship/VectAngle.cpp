/*
 * AUTHOR: CALEB REISTER
 * DESCRIPTION: implementation file for VectAngle.hpp
 */

#include "VectAngle.hpp"

//Angle class ------------------------->
Angle::Angle()
{
    degrees = 0;
}

////////////////////////////////////////////////////////////////
/*
 * FUNCTION: set
 * DESCRIPTION: sets the angle and then forces the range
 * PARAMETERS:
 *  angle - the angle to set, overwrites any previous angle
 */
void Angle::set(float angle)
{
    degrees = angle;
    range();
}

/*
 * FUNCTION: change
 * DESCRIPTION: changes the angle, adds or subtracts to previous angle
 * PARAMETERS:
 *  difference - the number of degrees to add or subtract
 */
void Angle::change(float difference)
{
    degrees += difference;
    range();
}

////////////////////////////////////////////////////////////////
/*
 * FUNCTION: get
 * DESCRIPTION: returns the angle in degrees forcing the range
 */
float Angle::get()
{
    return degrees;
}

/*
 * FUNCTION: radians
 * DESCRIPTION: converts degrees to radians
 * RETURN: radians
 */
float Angle::radians()
{
    return (PI * degrees) / 180;
}

/*
 * FUNCTION: slope
 * DESCRIPTION: converts degrees to a slope for use on
 *  a Cartesian plane
 * RETURN: slope of angle expressed as a vector
 */
Vect2d Angle::slope()
{

}

////////////////////////////////////////////////////////////////
/*
 * FUNCTION: range
 * DESCRIPTION: forces an angle value to be between 0 and 359
 */
void Angle::range()
{
    degrees %= 360;
}
