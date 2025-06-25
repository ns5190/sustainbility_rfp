/**
 * Component: SGP30
 * Measures: tvoc, e-co2
 * 
 * https://www.makerguides.com/interfacing-arduino-uno-sgp30-versatile-air-quality-sensor/
 */

#include "Wire.h"
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

void setup() {
  Serial.begin(9600);
  sgp.begin();
}

void loop() {
  if (sgp.IAQmeasure()) {
    Serial.print("TVOC:");  // ppb
    Serial.println(sgp.TVOC);
    Serial.print("eCO2:");  // ppm
    Serial.println(sgp.eCO2);    
  }
  delay(1000);
}