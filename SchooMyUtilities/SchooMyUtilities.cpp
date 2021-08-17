/* Copyright (c) 2020 SchooMy, inc.  All rights reserved. */

#include "SchooMyUtilities.h"
#define sec_num 15

SchooMyUtilities::SchooMyUtilities() {}

/**
 * common utilities
 */
void SchooMyUtilities::serialPlotterPrint(int value, int upperLimit, int lowerLimit) {
  Serial.print(upperLimit);
  Serial.print(",");
  Serial.print(lowerLimit);
  Serial.print(",");
  Serial.print(value);
  Serial.println("");
}

/**
 * soundSensor utilities
 */
void SchooMyUtilities::soundSensorBegin(int echoPin) {
  pinMode(echoPin, INPUT);
  _plotAdjust = _getSoundSensorPlotterAdjustValue(echoPin);
}

const int average_count = 10;
int SchooMyUtilities::_getSoundSensorPlotterAdjustValue(int echoPin) {
  int val = 0;
  unsigned int s = 0;
  for (int i = 0; i < average_count; i++) {
    val = analogRead(echoPin);
    delay(20);
    // Some data were excluded for correction.
    if (i == 0) continue;
    s += val;
  }
  return (int) s / (average_count -1) + 100;
}

int secList[sec_num]={0};
int SchooMyUtilities::soundSensorPlotterAnalogRead(int echoPin) {
  float total = 0.0;
  for(int i = sec_num - 1; i > 0; i--) {
    secList[i] = secList[i-1];
    total += secList[i];
  }
  int analogReadAdjust = abs(analogRead(echoPin) - _plotAdjust);
  delay(20);
  secList[0] = analogReadAdjust;
  total += secList[0];
  return (int) total / sec_num;
}
