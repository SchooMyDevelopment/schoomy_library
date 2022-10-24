/* Copyright (c) 2020-2023 SchooMy, inc.  All rights reserved. */

#ifndef SchooMyUtilities_h
  #define SchooMyUtilities_h
  #include "Arduino.h"
  #include "Preferences.h"
  extern "C" {
    #include "crypto/base64.h"
  }

  class SchooMyUtilities {
    public:
      SchooMyUtilities();
      void serialPlotterPrint(int value, int upperLimit, int lowerLimit);
      void soundSensorBegin(int echoPin);
      int soundSensorPlotterAnalogRead(int echoPin);
      char* encrypt(char* password);
      char* decrypt(char* password);
      String getChipId(uint64_t mac);
      String getSchooMyApiKey(String registerKey);
    private:
      int _plotAdjust;
      int _getSoundSensorPlotterAdjustValue(int echoPin);
  };
#endif
