/**
 * Component: MQ135
 * Measures: co2, benzyne
 */

int sensorValue;
int digitalValue;

void setup()
{
  Serial.begin(9600); // sets the serial port to 9600
  pinMode(2, INPUT);
}

void loop()
{
  sensorValue = analogRead(0); // read analog input pin 0
  digitalValue = digitalRead(2);
  Serial.println(sensorValue, DEC); // prints the value read in ppm
  delay(1000); // wait 100ms for next reading
}
