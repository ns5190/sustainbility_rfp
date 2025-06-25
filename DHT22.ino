/**
 * Component: DHT-22 sensor
 * Measures: temperature and humidity
 * 
 * https://www.instructables.com/How-to-use-DHT-22-sensor-Arduino-Tutorial/ 
*/

//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 2     // pin
#define DHTTYPE DHT22   // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  // Stores humidity value
float temp; // Stores temperature value

void setup()
{
    Serial.begin(9600);
	dht.begin();

}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);

    Serial.print(" %, Temp: ");
    Serial.print(temp);

    delay(2000); //Delay 2 sec.
}

   