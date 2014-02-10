/*
 * HEADER: util
 * AUTHOR: Caleb Reister
 * DESCRIPTION: defines a utilities namespace
 *  - functions for angle conversion (radians, degrees, slope)
 *  - 2d vector struct
 */

#ifndef UTIL_HPP
#define UTIL_HPP
#include <cmath>

const float PI = M_PI;

namespace util
{
    struct Vect2d
    {
            float x;
            float y;
    };

    //Angles
    float rad2deg(float rad);
    float deg2rad(float deg);
    float slope2deg(Vect2d slope);
    float slope2deg(float slope);
    Vect2d deg2slope(float deg);
}

#endif
