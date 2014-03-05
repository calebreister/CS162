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

    ofstream cfgFile;
    cfgFile.open(path.c_str(), ios::out | ios::app);

    if (!ifstream(path.c_str()))
    {
        cerr << "StroidConfig.json file does not exist... creating." << endl;
        //Default values string generated from
        //http://www.freeformatter.com/javascript-escape.html#ad-output
    }

    Object cfg = parse_file(path.c_str());
    if (!cfg["REF_HZ"] || cfg["REF_HZ"].type() == NIL
        || cfg["REF_HZ"].type() == BOOL)
        cfg["REF_HZ"] = 120;

    cfgFile.close();

    return parse_file(path.c_str());
}
