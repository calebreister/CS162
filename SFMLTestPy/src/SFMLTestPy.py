#!/usr/bin/env python3.3

import sfml as sf

def drawShip():
    ship = sf.ConvexShape()
    ship.point_count = 3
    ship.set_point(0, sf.Vector2(4, 0))
    ship.set_point(1, sf.Vector2(0, 10))
    ship.set_point(2, sf.Vector2(8, 10))
    
    midpoint = sf.Vector2(5, 10)
    ship.origin = midpoint
    
    ship.rotation = 45
    ship.position = (4, 10)
    
    ship.fill_color = sf.Color(0, 0, 0)
    ship.outline_thickness = 1
    ship.outline_color = sf.Color(255, 255, 255)
    
    return ship

window = sf.RenderWindow(sf.VideoMode(640, 480), "SFML works!")
ship = drawShip()
print("ship drawn")
angle = 0
x, y = 0, 0

while window.is_open:
    for event in window.events:
        if type(event) is sf.CloseEvent:
            window.close()
            
    if sf.Keyboard.is_key_pressed(sf.Keyboard.LEFT):
        angle -= 2
        ship.rotation = angle
    if sf.Keyboard.is_key_pressed(sf.Keyboard.RIGHT):
        angle += 2
        ship.rotation = angle
    if sf.Keyboard.is_key_pressed(sf.Keyboard.UP):
        x += 1
        y += 1
        ship.position = (x, y)
    if sf.Keyboard.is_key_pressed(sf.Keyboard.DOWN):
        x -= 1
        y -= 1
        ship.position = (x, y)
    if x < 0 and y < 0:
        x, y = 500, 500
        ship.position = (x, y)
    if x > 500 and y > 500:
        x, y = 0, 0
        ship.position = (x, y)
        
    window.clear()
    window.draw(ship)
    window.display()
