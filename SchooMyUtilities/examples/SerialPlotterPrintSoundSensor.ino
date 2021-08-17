#include <SchooMyUtilities.h>

SchooMyUtilities scmUtils = SchooMyUtilities();

void setup() {
  Serial.begin(9600);
  scmUtils.soundSensorBegin(A5);
}

void loop() {
  scmUtils.serialPlotterPrint(scmUtils.soundSensorPlotterAnalogRead(A5), 600, 0);
}

