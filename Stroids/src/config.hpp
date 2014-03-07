/*
 * config.hpp    Mar 4, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION:
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <iostream>
#include "json.hh"
#include "util.hpp"

const Vect2d WIN_SIZE = {800, 800};
const Vect2d WIN_MID = {400, 400};
const Vect2d ZERO = {0, 0};

const int MAX_STROIDS = 1000;
const int MAX_PULSE = 200;

class Config
{
    private:
        JSON::Object write;
        JSON::Array validateColor(std::string obj, int defR, int defG, int defB);
        void validateValues();
    public:
        Config();
        JSON::Value read;
} cfg;

#endif
