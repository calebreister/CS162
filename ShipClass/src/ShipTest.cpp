#include <iostream>
#include "ship.h"

void
output(Ship ship);
using namespace std;

int
main()
{
  Ship test;
  float x, y; //general x and y coordinate variable, used for input
  float ang; //used for angle input
  int vel;//input
  //////////////////////////////////////////////////////////////////////////////
  cout << "Data is expressed as Location (x,y), Velocity <x,y>, Angle" << endl
       << "Press [ENTER] to continue";
  cin.get();
  output(test);

  /////////////////////////////////////////////////////////////////////////////////

  cout << "Set Location (x y): ";
  cin >> x >> y;
  test.setLocation(x, y);
  cout << "Set Velocity (x y): ";
  cin >> x >> y;
  test.setVelocity(x, y);

  cout << "Set Angle (0 to 359): ";
  cin >> ang;
  test.setAngle(ang);

  output(test);

  ////////////////////////////////////////////////////////////////////////////////

  cout << "Input degrees to turn (positive turns left): ";
  cin >> ang;
  if (ang > 0)
    for (int i = 0; i < ang; i++)
      test.turnLeft();
  else if (ang < 0)
    for (int i = 0; i < abs(ang); i++)
      test.turnRight();

  test.updateLocation();
  output(test);

  cout << "Input the velocity to go forward (int): ";
  cin >> vel;
  test.applyThrust(vel);
  test.updateLocation();
  output(test);
}

/////////////////////////////////////////////////////////////////////////////////

void
output(Ship ship)
{
  MyVect loc = ship.getLocation();
  MyVect vel = ship.getVelocity();
  float ang = ship.getAngle();
  cout << "(" << loc.x << "," << loc.y << "); <"
      << vel.x << "," << vel.y << ">; "
      << ang << endl;
}
