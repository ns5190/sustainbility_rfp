# Arduino Enviornmental Sensor Testing

This repository contains Arduino sketches for various environmental and gas sensors, plus a PDF with notes from testing and error logs.

---

## Contents

- **BME680+PMS5003.ino** — Combined sketch for Bosch BME680 (temperature, humidity, pressure, gas) and PMS5003 (particulate matter).
- **BME680.ino** — Standalone sketch for BME680.
- **DHT11.ino** — Sketch for DHT11 temperature/humidity sensor.
- **DHT22.ino** — Sketch for DHT22 temperature/humidity sensor.
- **MG811.ino** — Sketch for MG811 CO₂ sensor.
- **MQ135.ino** — Sketch for MQ135 air quality sensor.
- **PMS5003.ino** — Standalone sketch for PMS5003.
- **SCD41.ino** — Sketch for SCD41 CO₂ sensor.
- **SDS011.ino** — Sketch for SDS011 particulate matter sensor.
- **SGP30.ino** — Sketch for SGP30 air quality sensor.
- **Sustainability RFP Sensor Testing.pdf** — Notes from testing, calibration attempts, and error logs.
- **LICENSE** — License information.

---

## Purpose

- Test and validate multiple sensors with Arduino.
- Document integration challenges and calibration issues.
- Provide a reference for sustainability and sensor network projects.

---

## Notes

- Some sensors (MQ135, MG811) need burn‑in time for stable readings.
- Combining sensors on the same bus may cause communication errors.
- See the PDF for detailed troubleshooting and error logs.
