/* Copyright (c) 2020 SchooMy, inc.  All rights reserved. */

#ifndef SchooMyUtilities_h
  #define SchooMyUtilities_h
  #include "Arduino.h"

  class SchooMyUtilities {
    public:
      SchooMyUtilities();
      void serialPlotterPrint(int value, int upperLimit, int lowerLimit);
      void soundSensorBegin(int echoPin);
      int soundSensorPlotterAnalogRead(int echoPin);
    private:
      int _plotAdjust;
      int _getSoundSensorPlotterAdjustValue(int echoPin);
  };
#endif

