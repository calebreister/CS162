##@file Ship.hh
#@author Caleb Reister <calebreister@gmail.com>
#@brief defines a class for controlling a space ship from above.

import math

import SpaceObject
import sfml as sf

class Ship(SpaceObject.SpaceObject):
    __ship = sf.ConvexShape()
    ##@var _state
    #This variable defines the state of the ship.
    #It will either be 'GOOD', 'EXPLODE', or 'GONE'.
    #Any other values will raise a ValueError
    #This variable should only be read by the user.
    _state = 'GOOD'
    radius = 5
    
    #################################################
    ##@fn draw()
    #@brief Contains drawing instructions for the ship based on its current state
    #@param explodeAlpha Opacity reduction during ship explosion
    def __draw(self):
        self._boundFix()
        #explosion variables
        STEPS = 100
        count = 1
        alpha = 255
        size = 1
        
        #map the points
        self.__ship.set_point_count(3)
        self.__ship.set_point(0, sf.Vector2(10, 0))
        self.__ship.set_point(1, sf.Vector2(0, 25))
        self.__ship.set_point(2, sf.Vector2(20, 25))
        #check the state
        
        if self._state is 'GOOD':
            self.__ship.set_fill_color(sf.Color(0, 0, 0))
            self.__ship.set_outline_color(sf.Color(255, 255, 255))
        elif self._state is 'EXPLODE':
            count += 1
            size += .005
            alpha -= 255 / STEPS
            if count <= STEPS:
                self.__ship.set_scale(size, size)
                self.__ship.set_fill_color(sf.Color(0, 0, 0, alpha))
                self.__ship.set_outline_color(sf.Color(255, 255, 255, alpha))
            else: self._state = 'GONE'
        elif self._state is 'GONE':
            self.__ship.set_fill_color(sf.Color(0, 0, 0, 0))
            self.__ship.set_outline_color(sf.Color(0, 0, 0, 0))
            count = 0
        else:
            raise ValueError(self._state, "is not a valid Ship state."
                                    "It needs to be either GOOD,"
                                    "EXPLODE, or GONE")
        
        self.__ship.set_outline_thickness(2)
        
    ############################################
    ##@fn render(win)
    #Renders the ship in the given window and gets position information from the class.
    #Does NOT get input for positioning
    #@param[out] win The window in which to draw the ship
    def render(self, win):
        self.__ship.set_origin(sf.Vector2(10, 15))
        self.__ship.set_rotation(self.angleDeg + 90)
        self.__ship.set_position(self.loc[0], self.loc[1])
        self.__draw()
        self.updateLocation()
        
    ##############################################
    ##@fn applyThrust(thrust)
    #
    #Simulates firing the engine. Changes the current velocity based on the
    #angle the ship is facing (it may be facing a different direction than it’s
    #traveling).
    #
    #@param thrust The amount of thrust to apply
    def applyThrust(self, thrust):
        rad = math.degrees(self.angleDeg)
        self.chgVelocity(thrust * math.cos(rad),
                         thrust * math.sin(rad),
                         max)
        
    #############################################
    ##@fn void Ship::explode()
    #@brief Change the state of the ship to explode, set velocity to 0.
    def explode(self):
        if self._state is not 'GONE':
            self._state = 'EXPLODE'
        self.setVelocity(0, 0, 0)
        
