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
#include <cassert>//master cassert
#include <iostream>
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
            friend std::ostream& operator<<(std::ostream& out,
                                            const Vect2d& obj);
    };
    //Print Vect2d
    std::ostream& operator<<(std::ostream& out, const Vect2d& vect)
    {
        out << "(" << vect.x << ", " << vect.y << ")";
        return out;
    }

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
