##@file Asteroid.hh
#@author Caleb Reister <calebreister@gmail.com>
#@brief Contains a class declaration for a single asteroid.

import random as rand
import sfml as sf
import util
import SpaceObject

#enum equivalents
#Python treats classes as objects, meaning that their member
#values can be accessed directly
class Side:
    left, right, top, bottom = range(4)
    
class Quadrant:
    pp, nn, pn, np = range(4)
    
    
##@class Asteroid
#@brief A SpaceObject that draws an asteroid in the given window.
class Asteroid(SpaceObject.SpaceObject):
    radius = rand.randint(MIN_SIZE, MAX_SIZE)
    _loc = [rand.uniform(0, util.WIN_SIZE[0]),
            rand.uniform(0, util.WIN_SIZE[1])]
    _sides = rand.randint(6, 12)
    _rotationVel = rand.uniform(-.1, .1)
    hit = False
    split = False
    ##############################################
    def _checkSide(self, side):
        if side is Side.left:
            if self._loc[0] - self.radius < 0: return True
            else: return False
        elif side is Side.right:
            if self._loc[0] + self.radius > util.WIN_SIZE[0]:
                return True
            else: return False
        elif side is Side.top:
            if self._loc[1] - self.radius < 0: return True
            else: return False
        elif side is Side.bottom:
            if self._loc[1] + self.radius > util.WIN_SIZE[1]:
                return True
            else: return False
    ############################################################
    def checkLocBound(self, quad, loc, point = util.WIN_MID,
                      radius = 200):
        if quad is Quadrant.pp:
            if (self._loc[0] > point[0] and
                self._loc[1] > point[1] and
                self._loc[0] < point[0] + self.radius and
                self._loc[1] < point[1] + self.radius):
                return True
            else: return False
        elif quad is Quadrant.nn:
            if (self._loc[0] < point[0] and
                self._loc[1] < point[1] and
                self._loc[0] > point[0] - self.radius and
                self._loc[1] > point[1] - self.radius):
                return True
            else: return False
        elif quad is Quadrant.pn:
            if (self._loc[0] > point[0] and
                self._loc[1] < point[1] and
                self._loc[0] < point[0] + self.radius and
                self._loc[1] > point[1] - self.radius):
                return True
            else: return False
        elif quad is Quadrant.np:
            if (self._loc[0] < point[0] and
                self._loc[1] > point[1] and
                self._loc[0] > point[0] - self.radius and
                self._loc[1] < point[1] + self.radius):
                return True
            else: return False
        else:
            raise ValueError("Not a valid quadrant")
    ###############################################################
    def __init__(self):
        if self.checkLocBound(Quadrant.pp, self._loc):
            self._loc[0] += 100
            self._loc[1] += 100
        elif self.checkLocBound(Quadrant.nn, self._loc):
            self._loc[0] -= 100
            self._loc[1] -= 100
        elif self.checkLocBound(Quadrant.pn, self._loc):
            self._loc[0] += 100
            self._loc[1] -= 100
        elif self.checkLocBound(Quadrant.np, self._loc):
            self._loc[0] -= 100
            self._loc[1] += 100
        
        if COLOR_RAND is True:
            self.color = sf.Color(rand.randint(rand.randint(0, 100), 255),
                                   rand.randint(rand.randint(0, 100), 255),
                                   rand.randint(rand.randint(0, 100), 255))
        else:
            #put user color code here
            pass
    ################################################################
    def draw(self, win):
        self._boundFix()
        
        #create asteroid
        stroid = sf.CircleShape
        stroid.radius = self.radius
        stroid.point_count = self.sides
        
        #define properties
        stroid.origin = sf.Vector2(self.radius, self.radius)
        stroid.fill_color = sf.Color(0, 0, 0)
        stroid.outline_thickness = 5
        stroid.outline_color = sf.Color(self.color)
        
        #update values
        stroid.rotation = self.getAngle()
        stroid.position = sf.Vector2(self._loc[0], self._loc[1])
        self.chgAngle(self._rotationVel)
        stroid.rotate(self._rotationVel)
        self.updateLocation()
        
        #draw
        win.draw(stroid)
        
        #Yes, this is a function definition within a function definition...
        #it is possible in Python. I will use it to condense repeated code
        def update():
            stroid.rotation = self._angleDeg
            win.draw(stroid)
        
        #run edge and corner checks
        if self.checkSide(Side.bottom) and self.checkSide(Side.right):
            stroid.position = sf.Vector2(-(util.WIN_SIZE[0] - self._loc[0]),
                                         -(util.WIN_SIZE[1] - self._loc[1]))
            update()
        elif self.checkSide(Side.left) and self.checkSide(Side.top):
            stroid.position = sf.Vector2(util.WIN_SIZE[0] + self._loc[0],
                                         util.WIN_SIZE[1] + self._loc[1])
            update()
        elif self.checkSide(Side.right) and self.checkSide(Side.top):
            stroid.position = sf.Vector2(-(util.WIN_SIZE[0] - self._loc[0]),
                                         util.WIN_SIZE[1] + self._loc[1])
            update()
        elif self.checkSide(Side.left) and self.checkSide(Side.bottom):
            stroid.position = sf.Vector2(util.WIN_SIZE[0] + self._loc[0],
                                         -(util.WIN_SIZE[1] - self._loc[1]))
            update()
        else:
            #x
            if self.checkSide(Side.right):
                stroid.position = sf.Vector2(-(util.WIN_SIZE[0] - self._loc[0]),
                                             self._loc[1])
                update()
            elif self.checkSide(Side.left):
                stroid.position = sf.Vector2(util.WIN_SIZE[0] + self._loc[0],
                                             self._loc[1])
                update()
            #y
            if self.checkSide(Side.bottom):
                stroid.position = sf.Vector2(self._loc[0],
                                             -(util.WIN_SIZE[1] - self._loc[1]))
                update()
            elif self.checkSide(Side.top):
                stroid.position = sf.Vector2(self._loc[0],
                                             util.WIN_SIZE[0] + self._loc[1])
                update()

###########################################################################
#This function is a friend of the asteroid class
#Python does not support mulitple constructors, so this takes an
#old asteroid, creates 2 new ones based off of the old, and the returns
#the new asteroids in list
def seed(old):
    #Generate 2 new asteroids
    new = [Asteroid(), Asteroid()]
    for i in range(2):
        new[i].radius = old._radius / 2
        new[i].sides = old._sides / 2
        new[i]._loc = old._loc
        new[i]._color = old._color
        new[i].hit = False
        new[i].split = True
    return new
    