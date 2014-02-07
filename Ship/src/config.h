#ifndef CONFIG_H
#define CONFIG_H

#include "VectAngle.hpp"

//Hz at which to run the program
const int refHz = 120;

//size of the window
const Vect2d WIN_SIZE = { 800, 800 };
//center of the window
const Vect2d WIN_MID = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
const Vect2d ORIGIN = { 0, 0 };

const float MAX_SPEED = 5;

//degrees to turn per loop cycle
const float TURN_RATE = 2;

//amount of thrust to apply per cycle
const float THRUST = .05;

#endif
