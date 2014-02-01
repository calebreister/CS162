/*
 * HEADER: VectAngle
 * DESCRIPTION: defines a struct for 2d vectors and
 *  a class for angles in degrees
 */

#ifndef VECTMATH_H
#define VECTMATH_H
#include <cmath>

const float PI = M_PI;

struct Vect2d
{
        float x;
        float y;
};

class Angle
{
    public:
        Angle();
        void set(float angle);
        void change(float difference);
        float radiansIn(float radians);
        float slopeIn(Vect2d slope);// atan(y/x)
        /////////////////////////////////////
        float get();
        float radiansOut();
        float slopeOut();//use tan(angle)

    private:
        void range();
        float degrees;
};

#endif
