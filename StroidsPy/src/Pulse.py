##@file Pulse.py
#@brief Defines the "bullets" fired by the ship in the
# asteroids game implementation.

import sfml as sf
import SpaceObject
import util


##@class Pulse
#@brief This class is a SpaceObject that simulates laser pulses.
class Pulse(SpaceObject.SpaceObject):
    pulse = sf.RectangleShape()
    timeToLive = 0
    color = sf.Color(255, 255, 255)
    