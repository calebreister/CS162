/*
 * HEADER: VectAngle
 * AUTHOR: Caleb Reister
 * DESCRIPTION: defines a struct for 2d vectors and
 *  a class for angles in degrees
 */

#ifndef VECTANG_H
#define VECTANG_H
#include <cmath>

const float PI = M_PI;

struct Vect2d
{
        float x;
        float y;
};

namespace Angle
{
    //degrees class
    class deg
    {
        private:
            float ang;
            void range();

        public:
            deg();
            void set(float angle);
            void change(float difference);
            /////////////////////////////////////
            float get();
    };

    //utility functions
    float rad2deg(float rad);
    float deg2rad(float deg);
    float slope2deg(Vect2d slope);
    float slope2deg(float slope);
    Vect2d deg2slope(float deg);
}

#endif
