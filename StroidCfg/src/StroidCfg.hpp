#ifndef STROIDCFG_HPP_
#define STROIDCFG_HPP_

#include <iostream>
#include <string>
#include "json.hh"

class Config
{
    private:
        JSON::Object write;
        JSON::Array validateColor(std::string obj, int defR, int defG, int defB);
        void validateValues();
    public:
        Config();
        JSON::Value read;
} cfig;

#endif
