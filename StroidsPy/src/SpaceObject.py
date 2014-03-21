from math import sqrt
import util

##@class SpaceObject
#@brief A base class that defines any object that moves from above in a 2d world.
#@var loc The location
#@var vel The velocity
#@var __angleDeg The angle of the object in degrees. Should not be directly changed
#@var __radius The radius of the object, should not be changed after __init__
class SpaceObject:
    _radius = 5
    angleDeg = 0
    vel = [0, 0]
    loc = [0, 0]
    
    def __init__(self, radi):
        self.__radius = radi
    
    ##@fn void SpaceObject::boundFix()
    #@brief Makes sure the object does not go outside the screen
    def __boundFix(self):
        if self.loc[0] > util.WIN_SIZE[0]:
            self.loc[0] = 0
        elif self.loc[0] < 0:
            self.loc[0] = util.WIN_SIZE[0]
            
        if self.loc[1] > util.WIN_SIZE[1]:
            self.loc[1] = 0
        elif self.loc[1] < 0:
            self.loc[1] = util.WIN_SIZE[1]
        
    def updateLocation(self):
        self.loc[0] += self.vel[0]
        self.loc[1] += self.vel[1]
        
    ##@fn float getAngVel()
    #@brief Gets the angular velocity of the object
    #@return object's angular velocity as a float
    def getAngVel(self):
        # ** is the power operator
        return sqrt(self.vel[0] ** 2 + self.vel[1] ** 2)
    
##@fn bool objectsIntersect(SpaceObject obj1, SpaceObject obj2)
#@brief Checks to see whether the radius of one SpaceObject intersects another
#@param obj1 The 1st object to check
#@param obj2 The 2nd object to check
#@return bool of whether or not objects intersect       
def objectsIntersect(obj1, obj2):
    distBetween = sqrt((obj2.loc[0] - obj1.loc[0]) ** 2 + 
                       (obj2.loc[1] - obj1.loc[1]) ** 2)
    if distBetween < obj1._radius + obj2._radius:
        return True
    else: return False
