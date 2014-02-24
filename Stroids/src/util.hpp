/*
 * HEADER: UTIL_HPP
 * AUTHOR: Caleb Reister
 * DESCRIPTION: defines a utilities namespace
 *  - functions for angle conversion (radians, degrees, slope)
 *  - 2d vector struct
 *  - random number generators
 */

#ifndef UTIL_HPP
#define UTIL_HPP

//#define NDEBUG
#include <cassert>
//cassert needs to be in a file that is included in multiple places
//this files is included in almost everything.
#include <cmath>
#include <cstdlib>
#include <ctime>

const float PI = M_PI;

namespace util
{
    struct Vect2d
    {
            float x;
            float y;
    };

    //Random number generator
    int randInt(int low, int high);
    float randFloat(float low, float high);

    //Angle conversions
    float rad2deg(float rad);
    float deg2rad(float deg);
    float slope2deg(Vect2d slope);
    float slope2deg(float slope);
    Vect2d deg2slope(float deg);
}

#endif
