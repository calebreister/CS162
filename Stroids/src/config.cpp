#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "config.hpp"
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

    /*if (!ifstream(path.c_str()))
    {
        ofstream out;
        out.open(path.c_str());
        cerr << "StroidConfig.json file does not exist... creating." << endl;
        //Default values string generated from
        //http://www.freeformatter.com/javascript-escape.html#ad-output
        out << "{\r\n    \"CMT\" : \"From here on out, CMT is a comment.\",\r\n"
            << "    \r\n    \"CMT\" : \"Refresh rate of the game (FPS)\",\r\n"
            << "    \"REF_HZ\" : 120,\r\n\r\n"
            << "    \"SHIP\" :\r\n    {\r\n"
            << "        \"MAX_SPEED\" : 5.0,\r\n"
            << "        \"CMT\" : \"Degrees to turn per refresh.\",\r\n"
            << "        \"TURN_RATE\" : 2.0,\r\n        \"COLOR\" : [255, 0, 0],\r\n"
            << "        \"OUTLINE_PX\" : 1\r\n    },\r\n    \r\n    \"LASER\" :\r\n"
            "    {\r\n"
            << "        \"CMT\" : \"Lifetime of a single laser shot (pulse), "
            "relative to REF_HZ\",\r\n"
            << "        \"PULSE_LIFE\" : 80,\r\n"
            "        \"PULSE_COLOR\" : [255, 255, 255]\r\n    },\r\n"
            << "    \r\n    \"ASTEROID\" :\r\n    {\r\n        \"START_NUM\" : 10,\r\n"
            << "        \"CMT\" : \"Number seconds between asteroid spawns\",\r\n"
            << "        \"SPAWN_RATE\" : 10,\r\n        \"MAX_SPEED\" : null,\r\n"
            << "        \"MIN_SPEED\" : null,\r\n        \"MAX_SIZE\" : null,\r\n"
            "        \"MIN_SIZE\" : null,\r\n"
            << "        \"CMT\" : \"Whether or not to use a random color.\",\r\n"
            "        \"RAND_COLOR\" : true,\r\n"
            << "        \"CMT\" : \"The color to use if it is not random\",\r\n"
            "        \"COLOR\" : [255, 255, 255]\r\n"
            << "    }\r\n}\r\n";
        out.close();
    }*/

    return parse_file(path.c_str());
}

/*void configValidate()
{
    if (!cfg["REF_HZ"])

}
*/
