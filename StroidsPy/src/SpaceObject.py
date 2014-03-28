import math

import util


##@class SpaceObject
#@brief A base class that defines any object that moves from above in a 2d world.
#@var _loc The location
#@var __vel The velocity
#@var __angleDeg The angle of the object in degrees. Should not be directly changed
#@var radius The radius of the object, should not be changed after __init__
class SpaceObject:
    #@var radius
    #radius is fine to change, but in most situations it should be left constant
    #note that radius will NOT change the actual size of the object, it will only
    #change the likliness of collision 
    radius = 5
    ##@var __vel
    #vel and angleDeg both require value validations. These are done
    #with the set, chg, and get functions.
    __vel = [0, 0]
    ##@var __angleDeg
    #vel and angleDeg both require value validations. These are done
    #with the set, chg, and get functions.
    __angleDeg = 0
    ##@var _loc
    #loc can be changed by the user, but be aware that it has optional value validations
    #and is connected to the velocity with updateLocation, meaning that it is subject to
    #change very quickly and without notice.
    _loc = [0, 0]
    
    ##################################################
    def __init__(self, radius):
        self.radius = radius
    
    ##################################################
    ##@fn boundFix()
    #@brief Makes sure the object does not go outside the screen
    def _boundFix(self):
        if self._loc[0] > util.WIN_SIZE[0]:
            self._loc[0] = 0
        elif self._loc[0] < 0:
            self._loc[0] = util.WIN_SIZE[0]
            
        if self._loc[1] > util.WIN_SIZE[1]:
            self._loc[1] = 0
        elif self._loc[1] < 0:
            self._loc[1] = util.WIN_SIZE[1]
       
    ################################################### 
    ##@fn updateLocation()
    #@brief Adds the velocity to the location
    def updateLocation(self):
        self._loc[0] += self.vel[0]
        self._loc[1] += self.vel[1]
     
    ##################################################     
    ##@fn getAngVel()
    #@brief Gets the angular velocity of the object
    #@return object's angular velocity as a float
    def getAngVel(self):
        # ** is the power operator
        return math.sqrt(self.vel[0] ** 2 + self.vel[1] ** 2)
    
    ###################################################
    ##@fn setVelocity(newVel, max)
    #@brief Set the velocity of the SpaceObject.
    #@param newVel The new velocity value to set [x,y]
    #@param max The maximum angular velocity to allow
    def setVelocity(self, newVel, max):
        self.__vel[0] = newVel[0]
        self.__vel[1] = newVel[1]
        
        #speed limiting and validations
        angMaxRatio = self.getAngVel()
        if angMaxRatio > 1:
            self.__vel[0] /= angMaxRatio
            self.__vel[1] /= angMaxRatio
        assert(self.__vel <= max);
        assert(self.__vel >= -max);
        assert(self.__vel <= max);
        assert(self.__vel >= -max);
        
    #####################################################
    ##@fn chgVelocity(vel, max)
    #@brief Changes the velocity
    #@param vel The velocity vector [x,y]
    #@param max The max allowable velocity
    def chgVelocity(self, vel, max):
        self.setVelocity([self.__vel[0] + vel[0],
                          self.__vel[1] + vel[1]])
    
    #####################################################
    ##@fn setAngle(deg)
    #@param deg The new angle
    def setAngle(self, deg):
        self.__angleDeg = deg
       
    ################################################# 
    ##@fn chgAngle(deg)
    #@param The angle to add to the existing angle
    def chgAngle(self, deg):
        self.__angleDeg += deg
     
    ###############################################   
    ##@fn getAngle()
    #@return The angle of the object (deg) between 0 and 359
    def getAngle(self):
        self.__angleDeg %= 360
        return self.__angleDeg
        
################################################################
##@fn objectsIntersect(obj1, obj2)
#@brief Checks to see whether the radius of one SpaceObject intersects another
#@param obj1 The 1st object to check
#@param obj2 The 2nd object to check
#@return bool of whether or not objects intersect       
def objectsIntersect(obj1, obj2):
    distBetween = math.sqrt((obj2._loc[0] - obj1._loc[0]) ** 2 + 
                            (obj2._loc[1] - obj1._loc[1]) ** 2)
    if distBetween < obj1.radius + obj2.radius:
        return True
    else:
        return False
