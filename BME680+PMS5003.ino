#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

// Initialize BME680 sensor on I2C
Adafruit_BME680 bme;

// Define SoftwareSerial for PMS5003 sensor
SoftwareSerial pmsSerial(10, 11);  // RX, TX pins for PMS5003

const int PMS_FRAME_SIZE = 32;  // PMS5003 sends 32-byte data frames

void setup() {
  Serial.begin(115200);      // Serial monitor for debugging
  pmsSerial.begin(9600);     // PMS5003 communicates at 9600 baud

  // Initialize BME680 sensor
  if (!bme.begin()) {
    Serial.println("Could not find BME680 sensor!");
    while (1);  // Halt if sensor not found
  }

  // Configure BME680 oversampling and heater settings
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setGasHeater(320, 150);  // 320°C for 150 ms

  Serial.println("Sensors initialized.");
}

void loop() {
  Serial.println("---- SENSOR READINGS ----");

  // Read and print BME680 data
  if (bme.performReading()) {
    Serial.println("[BME680]");
    Serial.print("Temp: "); Serial.print(bme.temperature); Serial.println(" °C");
    Serial.print("Pressure: "); Serial.print(bme.pressure / 100.0); Serial.println(" hPa");
    Serial.print("Humidity: "); Serial.print(bme.humidity); Serial.println(" %");
    Serial.print("Gas Resistance: "); Serial.print(bme.gas_resistance / 1000.0); Serial.println(" KOhms");
  } else {
    Serial.println("[BME680] Reading failed.");
  }

  // Read and print PMS5003 data
  readPMS5003();

  Serial.println();
  delay(3000);  // Wait before next reading
}

void readPMS5003() {
  // Check if enough bytes are available for a full frame
  if (pmsSerial.available() >= PMS_FRAME_SIZE) {

    // FRAME SYNC: Look for the first byte of the frame header (0x42)
    while (pmsSerial.read() != 0x42) {
      // If not enough bytes left to complete a frame, exit early
      if (pmsSerial.available() < PMS_FRAME_SIZE) {
        Serial.println("[PMS5003] Frame sync failed.");
        return;
      }
    }

    // Confirm second header byte (should be 0x4D)
    if (pmsSerial.read() != 0x4D) {
      Serial.println("[PMS5003] Invalid second header byte.");
      return;
    }

    // Read remaining 30 bytes of the frame (we already read 2)
    uint8_t buffer[PMS_FRAME_SIZE - 2];
    pmsSerial.readBytes(buffer, PMS_FRAME_SIZE - 2);

    // Extract PM values from buffer (standard frame format)
    uint16_t pm1_0 = buffer[4] << 8 | buffer[5];
    uint16_t pm2_5 = buffer[6] << 8 | buffer[7];
    uint16_t pm10  = buffer[8] << 8 | buffer[9];

    // Print PM readings
    Serial.println("[PMS5003]");
    Serial.print("PM1.0: "); Serial.print(pm1_0); Serial.println(" µg/m3");
    Serial.print("PM2.5: "); Serial.print(pm2_5); Serial.println(" µg/m3");
    Serial.print("PM10: ");  Serial.print(pm10);  Serial.println(" µg/m3");

  } else {
    // Not enough data yet — wait for next loop
    Serial.println("[PMS5003] Waiting for data...");
  }
}
