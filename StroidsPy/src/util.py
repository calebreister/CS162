import math
#many of the utilities included in util in the C++ version
#already exists in the Python standard library

#CONSTANTS
def WIN_SIZE(): return [800, 800]
def WIN_MID(): return [400, 400]
def ZERO(): return [0, 0]

##@fn float util::slope2deg(Vect2d slope)
#@brief Gets a slope and converts it to degrees.
#@param slope The rise / run, pre-divided.
#@return The angle of the slope in degress.
def slope2deg(slope):
    return math.degrees(math.atan2(slope[1], slope[0]))
    
##@fn Vect2d util::deg2slope(float deg)
#@brief Converts an angle to a slope for use on a Cartesian plane, ranged.
#@param deg The slope as a vector.
#@return Slope of angle expressed as a vector
def deg2slope(deg):
    #Python's lists are much easier to work with.
    #They are treated as objects and have their own
    #devoted function set. They also can be returned.
    #Individual items can be inserted, removed, or appended
    #meaning that Python lists are dynamically allocated.
    return [math.cos(math.radians(deg)), 
            math.sin(math.radians(deg))]
    
##@fn angleRange
#@brief makes sure a given angle (degrees) is between 0 and 359
def angleRange(deg):
    return deg % 360