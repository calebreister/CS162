#!/usr/bin/env python3.3

import os  #gives access to environment variables
import json  #builtin JSON library

class Config:
    _instance = None
    _path = os.environ['HOME'] + '/StroidConfig.json'
    #########################################################
    ##@fn _validateColor(color, defR, defG, defB)
    #@brief Checks a color to make sure it is within range and applies
    #default values if it isn't.
    #@param obj The JSON object with an Array called COLOR on which to apply the validation.
    #@param default The default RGB color, as a list (each value 0-255)
    #@return The validated JSON array.
    #
    #Like before, all objects must exist beforehand. Nonexistance of an object will
    #raise a KeyError exception. This can be changed, I just do not have the time to do so.
    def _validateColor(self, obj, default):
        tempColor = self.cfg[obj]['COLOR']
        
        for i in range(3):
            try:
                if (type(self.cfg[obj]['COLOR'][i]) is not int or
                    self.cfg[obj]['COLOR'][i] > 255 or
                    self.cfg[obj]['COLOR'][i] < 0):
                    tempColor[i] = default[i]
            except KeyError:
                tempColor[i] = default[i]
        return tempColor
    ##########################################################
    ##@fn _validateValues()
    #@brief Check all of the values in the configuration file
    #(and create them if they don't exist).
    def _validateValues(self):
        #//all if statements make sure that the property exists
        #//and that the type is correct
        
        #check frame rate
        item = 'FRAME_RATE'
        try:
            if type(self.cfg[item]) is not int or self.cfg[item] < 1:
                self.cfg[item] = 120
        except KeyError:
            self.cfg[item] = 120
            
        #check laser object
        obj = 'LASER'
        
        item = 'PULSE_LIFE'
        try:
            if type(self.cfg[obj][item]) is not int or self.cfg[obj][item] < 0:
                self.cfg[obj][item] = 100
        except KeyError:
            self.cfg[obj][item] = 100
            
        item = 'COLOR'
        self.cfg[obj][item] = self._validateColor(obj, [255, 255, 255])
        
        item = 'EDGE_DEATH'
        try:
            if type(self.cfg[obj][item]) is not bool:
                self.cfg[obj][item] = True
        except KeyError:
            self.cfg[obj][item] = True
            
        #check ship
        obj = 'SHIP'
        
        item = 'SPEED'
        try:
            if ((type(self.cfg[obj][item]) is not int and
                type(self.cfg[obj][item] is not float)) or
                self.cfg[obj][item] < 0):
                self.cfg[obj][item] = 5.01
        except KeyError:
            self.cfg[obj][item] = 5.01
        
        item = 'THRUST_FWD'
        try:
            if (type(self.cfg[obj][item]) is not int and
                type(self.cfg[obj][item] is not float)):
                self.cfg[obj][item] = .05
        except KeyError:
            self.cfg[obj][item] = .05
        item = 'THRUST_REV'
        try:
            if (type(self.cfg[obj][item]) is not int and
                type(self.cfg[obj][item] is not float)):
                self.cfg[obj][item] = -.05
        except KeyError:
            self.cfg[obj][item] = -.05
        
        item = 'TURN_RATE'
        try:
            if (type(self.cfg[obj][item]) is not int and
                type(self.cfg[obj][item] is not float)):
                self.cfg[obj][item] = 2.01
        except KeyError:
            self.cfg[obj][item] = 2.01
        
        item = 'OUTLINE_PX'
        try:
            if (type(self.cfg[obj][item]) is not int or 
                self.cfg[obj][item] < 0):
                self.cfg[obj][item] = 1
        except KeyError:
            self.cfg[obj][item] = 1
            
        item = 'COLOR'
        self.cfg[obj][item] = self._validateColor(obj, [255, 0, 0])
        
        #check asteroid
        obj = 'STROID'
        
        item = 'START_NUM'
        try:
            if (type(self.cfg[obj][item]) is not int or
                self.cfg[obj][item] < 1):
                self.cfg[obj][item] = 10
        except KeyError:
            self.cfg[obj][item] = 10
            
        item = 'SPAWN_RATE'
        try:
            if (type(self.cfg[obj][item]) is not int or
                self.cfg[obj][item] < 1):
                self.cfg[obj][item] = 100
        except KeyError:
            self.cfg[obj][item] = 100
            
        item = 'MAX_SPEED'
        try:
            if (type(self.cfg[obj][item]) is not int and
                type(self.cfg[obj][item] is not float)):
                self.cfg[obj][item] = .5
        except KeyError:
            self.cfg[obj][item] = .5
         
        ################MAKE THIS SECTION WORK CORRECTLY##########   
        item = 'SIZE_MAX'
        try:
            if (type(self.cfg[obj][item]) is not int or
                self.cfg[obj][item] < 0):
                self.cfg[obj][item] = 30
        except KeyError:
            self.cfg[obj][item] = 30
            
        item = 'SIZE_MIN'
        try:
            if (type(self.cfg[obj][item]) is not int or
                self.cfg[obj][item] < 0 or
                self.cfg[obj][item] > self.cfg[obj]['SIZE_MAX']):
                self.cfg[obj][item] = 10
        except KeyError:
            self.cfg[obj][item] = 10
            
        item = 'COLOR_RAND'
        try:
            if type(self.cfg[obj][item]) is not bool:
                self.cfg[obj][item] = True
        except KeyError:
            self.cfg[obj][item] = True
            
        item = 'COLOR'
        self.cfg[obj][item] = self._validateColor(obj, [255, 255, 255])
    #####################################################################
    def __init__(self):
        try:
            cfgFile = open(self._path)
        except FileNotFoundError:
            cfgFile = open(self._path, 'w')
            cfgStr = '{"LASER": {"EDGE_DEATH": true, "COLOR": [255, 255, 255], "PULSE_LIFE": 100}, "FRAME_RATE": 120, "STROID": {"START_NUM": 10, "SPAWN_RATE": 100, "COLOR": [255, 255, 255], "MAX_SPEED": 0.5, "SIZE_MIN": 10, "SIZE_MAX": 30, "COLOR_RAND": true}, "SHIP": {"COLOR": [255, 0, 0], "THRUST_FWD": 0.05, "SPEED": 5.01, "TURN_RATE": 2.01, "OUTLINE_PX": 1, "THRUST_REV": -0.05}}'
            j = json.loads(cfgStr)
            json.dump(j, cfgFile, indent=4)
            cfgFile.close()
        self.cfg = json.load(open(self._path))
        self._validateValues()
        cfgFile = open(self._path, 'w')
        json.dump(self.cfg, cfgFile, indent=4, sort_keys=True)
        cfgFile.close()
    ###################################################################
        #overrides function that is run when a new instance is created
        def __new__(cls, *args, **kwargs):
            if not cls._instance:
                cls._instance = super(Config, cls).__new__(cls, *args, **kwargs)
            return cls._instance
        
c = Config()
