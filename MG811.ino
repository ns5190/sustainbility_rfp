/**
 * Component: MG811
 * Measures: co2
 * 
 * https://www.instructables.com/Tutorial-How-to-Use-Mg811-Co2-Carbon-Dioxide-Gas-S/ 
 */

#include "CO2Sensor.h"

CO2Sensor co2Sensor(A0, 0.99, 100);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Initialized ===");
  co2Sensor.calibrate();
}

void loop() {
  int val = co2Sensor.read();
  Serial.print("CO2 value: ");
  Serial.println(val);

  delay(1000);
}