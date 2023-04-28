/* Copyright (c) 2020-2023 SchooMy, inc.  All rights reserved. */

#ifndef SchooMyUtilities_h
  #define SchooMyUtilities_h
  #include "Arduino.h"
  
  class SchooMyUtilities {
    public:
      SchooMyUtilities();
      void serialPlotterPrint(int value, int upperLimit, int lowerLimit);
      void soundSensorBegin(int echoPin);
      int soundSensorPlotterAnalogRead(int echoPin);
      String getChipId(uint64_t mac);
      static const int High = LOW;
      static const int Low = HIGH;

    private:
      int _plotAdjust;
      int _getSoundSensorPlotterAdjustValue(int echoPin);
  };
#endif
