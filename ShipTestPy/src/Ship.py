import math    

#No vector class created, it does not make as much since
#in this case, because a list class already exists
def listToFloat(data):
    for i in range(len(data)):
        data[i] = float(data[i])

class Ship:
    #Python does not have a private declaration,
    #but it does have something called name mangling
    #that will change the names of the members to include
    #the class name so that they can't be called directly
    __maxLocation = [1000, 1000]
    __location = [500, 500]
    __velocity = [0, 0]
    __angleDeg = 0
    __radius = 5
    
    #no "default" constructor necessary, values already
    #initialized
    ########################################################
    def setLocation(self, new):
        self.__location[0] = new[0]
        self.__location[1] = new[1]
        
    def setVelocity(self, new):
        self.__velocity[0] = new[0]
        self.__velocity[1] = new[1]
        
    def setAngle(self, angle):
        self.__angleDeg = angle
    ########################################################
    def updateLocation(self):
        self.__location[0] += self.__velocity[0]
        self.__location[1] += self.__velocity[1]
    
    def turnLeft(self):
        self.__angleDeg += 1
        if self.__angleDeg == 360:
            self.__angleDeg = 0
    
    def turnRight(self):
        self.__angleDeg -= 1
        if self.__angleDeg == -1:
            self.angleDeg = 359
            
    def applyThrust(self, thrust):
        self.__velocity[0] = math.cos(math.radians(self.__angleDeg)) * thrust
        self.__velocity[1] = math.sin(math.radians(self.__angleDeg)) * thrust
        self.updateLocation()
    ############################################################
    def getRadius(self):
        return self.__radius
    def getLocation(self):
        return self.__location
    def getVelocity(self):
        return self.__velocity
    def getAngle(self):
        return self.__angleDeg

def output(ship):
    loc = ship.getLocation()
    vel = ship.getVelocity()
    ang = ship.getAngle()
    print('(', loc[0], ',', loc[1], '); <',
          vel[0], ',', vel[1], '>; ', ang, sep='')
