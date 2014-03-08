//Localized includes to prevent
//other parts of the program from accessing
//the data made available
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>

//#define NDEBUG
#include <cassert>
#include "util.hpp"
using namespace std;
using namespace JSON;

//global instance of cfg
cfg* cfg::pInst = NULL;

//return instance of config
cfg* cfg::getInst()
{
    if (!pInst)//only allow 1 instance
        pInst = new cfg();
    return pInst;
}

cfg::cfg()
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
        cerr << "Stroidcfg.json file does not exist. Creating..." << endl;
        cfgFile << "{\"SHIP\":{\"COLOR\":[null,null,null]},"
                << "\"LASER\":{\"COLOR\":[null,null,null]},"
                << "\"STROID\":{\"COLOR\":[null, null, null]}}";
        cfgFile.close();
    }

    read = parse_file(path.c_str());
    write = read;

    validateValues();

    //write the changes to HD
    cfgFile.open(path.c_str());
    cfgFile << write;
    cfgFile.close();

    read = parse_file(path.c_str());
}

Array cfg::validateColor(string obj, int defR, int defG, int defB)
{
    Array tempColor;

    int def[3];
    def[0] = defR;
    def[1] = defG;
    def[2] = defB;

    tempColor = read[obj]["COLOR"];

    for (int i = 0; i < 3; i++)
    {
        if (read[obj]["COLOR"][i].type() != INT
            || read[obj]["COLOR"][i].as_int() > 255
            || read[obj]["COLOR"][i].as_int() < 0)
        {
            cerr << "Property [" << obj
                 << ":COLOR["
                 << i << "] is invalid. Regenerating..." << endl;
            tempColor[i] = def[i];
        }
    }

    return tempColor;
}

void cfg::validateValues()
{
    //all if statements make sure that the property exists
    //and that the type is correct
    //NOTE: all properties that contain sub-properties
    //(objects and arrays) have to exist beforehand

    string obj;
    string item;

    item = "FRAME_RATE";
    if (read[item].type() != INT || read[item].as_int() < 1)
        write[item] = 120;

    //CHECK LASER
    obj = "LASER";

    item = "PULSE_LIFE";
    if (read[obj][item].type() != INT || read[obj][item].as_int() < 0)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 1;
    }

    write[obj]["COLOR"] = validateColor(obj, 255, 255, 255);

    item = "EDGE_DEATH";
    if (read[obj][item].type() != BOOL)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = true;
    }

    /////////////////////////////////////////////////////////////////////////////////
    //CHECK SHIP
    obj = "SHIP";

    item = "SPEED";
    if ((read[obj][item].type() != INT && read[obj][item].type() != FLOAT)
        || read[obj][item].as_float() < 0)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 5.01;
    }

    item = "THRUST_FWD";
    if (read[obj][item].type() != INT && read[obj][item].type() != FLOAT)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 0.05;
    }

    item = "THRUST_REV";
    if (read[obj][item].type() != INT && read[obj][item].type() != FLOAT)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = -0.05;
    }

    item = "TURN_RATE";
    if (read[obj][item].type() != INT && read[obj][item].type() != FLOAT)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 2.01;
    }

    item = "OUTLINE_PX";
    if (read[obj][item].type() != INT || read[obj][item].as_int() < 0)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 1;
    }

    write["SHIP"]["COLOR"] = validateColor("SHIP", 255, 0, 0);

    //////////////////////////////////////////////////////////////////////////
    //CHECK ASTEROID
    obj = "STROID";

    item = "START_NUM";
    if (read[obj][item].type() != INT
        || read[obj][item].as_int() > MAX_STROIDS
        || read[obj][item].as_int() < 1)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 10;
    }

    item = "SPAWN_RATE";
    if (read[obj][item].type() != INT
        || read[obj][item].as_int() < 1)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 10;
    }

    item = "MAX_SPEED";
    if ((read[obj][item].type() != INT && read[obj][item].type() != FLOAT)
        || read[obj][item].as_float() < 0)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = .5;
    }

    item = "MAX_SIZE";
    if (read[obj][item].type() != INT || read[obj][item].as_int() < 0
        || read[obj][item].as_int() < read[obj]["MIN_SIZE"].as_int())
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 30;
    }

    item = "MIN_SIZE";
    if (read[obj][item].type() != INT || read[obj][item].as_int() < 0
        || read[obj][item].as_int() > read[obj]["MAX_SIZE"].as_int())
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = 10;
    }

    item = "COLOR_RAND";
    if (read[obj][item].type() != BOOL)
    {
        cerr << "Property " << obj << ":" << item << " is invalid. Regenerating..."
             << endl;
        write[obj][item] = true;
    }

    write[obj]["COLOR"] = validateColor(obj, 255, 255, 255);
}
