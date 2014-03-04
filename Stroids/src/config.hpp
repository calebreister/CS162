#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "util.hpp"

//Hz at which to refresh the game
const int REF_HZ = 120;

//size of the window
const Vect2d WIN_SIZE = {800, 800};
//center of the window
const Vect2d WIN_MID = {400, 400};
const Vect2d ZERO = {0, 0};

const float SHIP_SPEED = 5;

//degrees to turn per loop cycle
const float TURN_RATE = 2;

const int MAX_STROIDS = 1000;
const int START_STROIDS = 10;
const int STROID_SPAWN_RATE = 10; //number of seconds between stroid spawns

const float PULSE_LIFE = 80;
const int MAX_PULSE = 100;

#endif
