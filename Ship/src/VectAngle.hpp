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

class AngleDeg
{
    private:
        float degrees;
        void range();
        float toRadians(float deg);
        float toDegrees(float rad);

    public:
        AngleDeg();
        void set(float angle);
        void change(float difference);
        void setRadians(float radians);
        void setSlope(Vect2d slope);
        void setSlope(float slope);
        /////////////////////////////////////
        float get();
        float getRadians();
        Vect2d getSlope(float multipler = 1);
};

#endif
