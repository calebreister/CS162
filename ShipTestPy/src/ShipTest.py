from Ship import Ship, output, listToFloat

test = Ship()#these parenthesis necessary, they allow the class
                #to instantiate

print("Data is expressed as Location (x,y), Velocity <x,y>, Angle")
input("Press [ENTER] to continue")

loc = input("Set Location (x y): ").split()
listToFloat(loc)
test.setLocation(loc)

vel = input("Set Velocity (x y): ").split()
listToFloat(vel)
test.setVelocity(vel)

ang = int(input("Set Angle (0 to 359): "))
test.setAngle(ang)

output(test)
#####################################################################
while True:
    ang = int(input("Enter degress to turn (+left): "))
    if ang > 0:
        for i in range(ang):
            test.turnLeft()
    elif ang < 0:
        for i in range(abs(ang)):
            test.turnRight()
    test.updateLocation()
    output(test)
    
    angVel = float(input("Input the velocity to go forward (float): "))
    test.applyThrust(angVel)
    test.updateLocation()
    output(test)