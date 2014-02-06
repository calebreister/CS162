#ifndef CONFIG_H
#define CONFIG_H

#include "VectAngle.hpp"

const int refHz = 120; //Hz at which to refresh the screen
const Vect2d WIN_SIZE = { 800, 800 };
const Vect2d WIN_MID = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
const Vect2d ORIGIN = { 0, 0 };
const float MAX_SPEED = 3;

#endif
