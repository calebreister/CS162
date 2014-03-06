#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <cassert>
#include "json.hh"
using namespace std;
using namespace JSON;

JSON::Value configInit()
{
    //get home directory
    int myuid;
    passwd *homedir;
    myuid = getuid();
    homedir = getpwuid(myuid);
    string path = homedir->pw_dir;
    path += "/StroidConfig.json";

    ofstream cfgFile;

    //create file if it does not exist
    if (!ifstream(path.c_str()))
    {
        cfgFile.open(path.c_str());
        cerr << "StroidConfig.json file does not exist... creating." << endl;
        cfgFile.close();
    }

    //if the file does exist, check its values
    Value in = parse_file(path.c_str());
    Object out = in;

    //all if statements make sure that the property exists
    //and that the type is correct
    if (!in["REF_HZ"] || in["REF_HZ"].type() == NIL
        || in["REF_HZ"].type() == BOOL)
        out["REF_HZ"] = 120;

    if (in["SHIP"].type() == OBJECT)
    {
        if (!in["SHIP"]["SPEED"] || in["SHIP"]["SPEED"].type() != INT
            || in["SHIP"]["SPEED"].type() != FLOAT)
            out["SHIP"]["SPEED"] = 5.01;

        if (!in["SHIP"]["FWD_THRUST"] || in["SHIP"]["FWD_THRUST"].type() != INT
            || in["SHIP"]["FWD_THRUST"].type() != FLOAT)
            out["SHIP"]["FWD_THRUST"] = 0.05;

        if (!in["SHIP"]["EF_THRUST"] || in["SHIP"]["REV_THRUST"].type() != INT
            || in["SHIP"]["REV_THRUST"].type() != FLOAT)
            out["SHIP"]["REV_THRUST"] = -0.05;

        if (!in["SHIP"]["TURN_RATE"] || in["SHIP"]["TURN_RATE"].type() != INT
            || in["SHIP"]["TURN_RATE"].type() != FLOAT)
            out["SHIP"]["TURN_RATE"] = 2.01;

        ////////////////////////////////////////////
        if (in["SHIP"]["COLOR"].type() == ARRAY)
        {
            if (in["SHIP"]["COLOR"][0].as_int() > 255
                || in["SHIP"]["COLOR"][0].as_int() < 0)
                out["SHIP"]["COLOR"][0] = 255;
            if (in["SHIP"]["COLOR"][1].as_int() > 255
                || in["SHIP"]["COLOR"][1].as_int() < 0)
                out["SHIP"]["COLOR"][1] = 0;
            if (in["SHIP"]["COLOR"][2].as_int() > 255
                || in["SHIP"]["COLOR"][2].as_int() < 0)
                out["SHIP"]["COLOR"][2] = 0;
        }
        else
        {
            Array color;
            color.push_back(255);
            color.push_back(0);
            color.push_back(0);
            out["SHIP"]["COLOR"] = color;
        }
/////////////////////////////////////////////////////
        if (!in["SHIP"]["OUTLINE_PX"] || in["SHIP"]["OUTLINE_PX"].type() != INT)
            out["SHIP"]["OUTLINE_PX"] = 1;
    }
    else
    {
        Object ship;
        ship["SPEED"] = 5.01;
        ship["FWD_THRUST"] = 0.05;
        ship["REV_THRUST"] = -0.05;
        ship["TURN_RATE"] = 2.01;
        Array color;
        color.push_back(255);
        color.push_back(0);
        color.push_back(0);
        ship["COLOR"] = color;
        ship["OUTLINE_PX"] = 1;
        out["SHIP"] = ship;
    }

    //write the changes
    cfgFile.open(path.c_str());
    cfgFile << out;
    cfgFile.close();

    return parse_file(path.c_str());
}

int main()
{

    cout << configInit();
}
