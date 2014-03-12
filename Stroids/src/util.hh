/**@file util.hh
 * @author Caleb Reister <calebreister@gmail.com>
 */

#ifndef UTIL_HH
#define UTIL_HH

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "json.hh"

const float PI = M_PI;

/**
 * @struct Vect2d
 * @brief A struct that defines a simple 2d vector with a n X and Y component.
 *  It has been extended to also include common operator overloads for aggregate operations.
 */
struct Vect2d
{
        float x;
        float y;
        friend std::ostream& operator<<(std::ostream& out,
                                        const Vect2d& in);
        friend void operator+=(Vect2d& out, float op);
        friend void operator-=(Vect2d& out, float op);
        friend void operator*=(Vect2d& out, float op);
        friend void operator/=(Vect2d& out, float op);
        friend Vect2d operator+(const Vect2d& in, float op);
        friend Vect2d operator-(const Vect2d& in, float op);
        friend Vect2d operator*(const Vect2d& in, float op);
        friend Vect2d operator/(const Vect2d& in, float op);
};

const Vect2d WIN_SIZE = {800, 800};
const Vect2d WIN_MID = {400, 400};
const Vect2d ZERO = {0, 0};

const int MAX_STROIDS = 1000;
const int MAX_PULSE = 200;

/**@class cfg
 * @brief Defines functions for working with a JSON configuration file.
 */
class cfg
{
    private:
        cfg();
        static cfg* pInst;

        JSON::Object write;
        JSON::Array validateColor(std::string obj, int defR, int defG, int defB);
        void validateValues();

    public:
        JSON::Value read;
        static cfg* getInst();
};

/**@namespace util
 * @brief Defines various utilities such as a random number generators and
 *  various conversion functions.
 */
namespace util
{
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
