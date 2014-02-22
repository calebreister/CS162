#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "util.hpp"

//Hz at which to refresh the game
const int REF_HZ = 120;

//size of the window
const util::Vect2d WIN_SIZE = { 800, 800 };
//center of the window
const util::Vect2d WIN_MID = { 400, 400 };
const util::Vect2d ZERO = { 0, 0 };

const float MAX_SPEED = 6;

//degrees to turn per loop cycle
const float TURN_RATE = 2;

#endif
