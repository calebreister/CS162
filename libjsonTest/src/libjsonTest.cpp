/*
 * libjsonTest.cpp    Feb 21, 2014
 * AUTHOR: Caleb Reister
 * DEV ENV: Eclipse 4 CDT Linux AMD64
 * DESCRIPTION: A test for libjson that also shows how to correctly link
 *  to the library. Simple test to print out a JSON file.
 */
#include <iostream>
#include "json.hh"

using namespace std;
using namespace JSON;

int main(int argc, char** argv)
{
    // Load JSON file

    Value v = parse_file("comp.json");

    // Build object programmatically
    Object obj = v;

    obj["foo"] = true;
    obj["bar"] = 3LL;
    obj["bar"] = 3L;
    obj["bar"] = 3;

    Object o;
    o["failure"] = true;
    o["success"] = "no way";

    obj["baz"] = o;

    Array a;
    a.push_back(true);
    a.push_back("asia");
    a.push_back("europa");
    a.push_back(55LL);
    a.push_back(3.12L);
    a.push_back(3.12);

    obj["beer"] = a;

    cerr << obj << endl;

    return 0;
}
