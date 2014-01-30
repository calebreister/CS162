//FILE HEADER

#include "ship.h"

float
toRadians(float degrees)
{
  return (PI * degrees) / 180;
}

///////////////////////////////////////////////////////

Ship::Ship()
{
  location = {0, 0};
  velocity = {0, 0};
  angleDeg = 0;
  radius = 5;
  maxLocation = {1000, 1000};
}

//=======================================================

void
Ship::setLocation(float x, float y)
{
  //validate
  location.x = x;
  location.y = y;
}

void
Ship::setVelocity(float velX, float velY)
{
  velocity.x = velX;
  velocity.y = velY;
}

void
Ship::setAngle(float angle)
{
  //validate
  angleDeg = angle;
}

//========================================================

void
Ship::turnLeft()
{
  angleDeg++;
  if (angleDeg == 360)
    angleDeg = 0;
}

void
Ship::turnRight()
{
  angleDeg--;
  if (angleDeg == -1)
    angleDeg = 359;
}

void
Ship::applyThrust(int thrust)
{
  velocity.y = std::sin(toRadians(angleDeg)) * thrust;
  velocity.x = std::cos(toRadians(angleDeg)) * thrust;
  updateLocation();
}

void
Ship::updateLocation()
{
  location.x = location.x + velocity.x;
  location.y = location.y + velocity.y;
}

//========================================================

float
Ship::getRadius()
{
  return radius;
}

MyVect
Ship::getLocation()
{
  return location;
}

MyVect
Ship::getVelocity()
{
  return velocity;
}

float
Ship::getAngle()
{
  return angleDeg;
}
