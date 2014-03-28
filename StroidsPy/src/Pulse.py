##@file Pulse.py
#@brief Defines the "bullets" fired by the ship in the
# asteroids game implementation.

import sfml as sf
import SpaceObject
import util

##@class Pulse
#@brief This class is a SpaceObject that simulates laser pulses.
class Pulse(SpaceObject.SpaceObject):
    radius = 1
    _pulse = sf.RectangleShape()
    _timeToLive = 250
    _color = sf.Color(255, 255, 255)
    #################################################
    def __init__(self, loc, ang):
        self.setAngle(ang)
        self._loc = loc
        
        vel = util.deg2slope(ang)
        self.setVelocity(vel, SHIP_SPEED + 2)
        
        self._pulse.set_position(self._loc[0], self._loc[1])
        self.pulse.set_rotation(self.getAngle())
        self.pulse.set_size(sf.Vector2(30, 3))
        
        #color setting code goes here
    ###################################################
    def hit(self):
        self._timeToLive = 0
    ####################################################
    def isDead(self):
        assert(self._timeToLive >= 0)
        if self._timeToLive == 0:
            return True
        else:
            return False
    ###################################################
    def draw(self, win):
        self._pulse.set_position(self._loc[0], self._loc[1])
        self._pulse.set_fill_color(sf.Color(self._color))
        
        win.draw(self._pulse)
        self._timeToLive -= 1
        self.updateLocation()
        
        if not EDGE_DEATH:
            self._boundFix()
    