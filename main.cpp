#include <Arduino.h>
#include <Wire.h>

#include "config.h"
#include "sensor_service.h"
#include "alert_service.h"
#include "display_service.h"

SensorService sensorService;
AlertService alertService;
DisplayService displayService;

uint32_t lastSampleTimeMs = 0;

void printCsvHeader() {
  Serial.println("time_ms,temperature_c,humidity_percent,pressure_hpa,alert");
}

void printCsvReading(const EnvironmentReading& reading, bool alertActive) {
  Serial.print(reading.timestampMs);
  Serial.print(",");
  Serial.print(reading.temperatureC, 2);
  Serial.print(",");
  Serial.print(reading.humidityPercent, 2);
  Serial.print(",");
  Serial.print(reading.pressureHpa, 2);
  Serial.print(",");
  Serial.println(alertActive ? 1 : 0);
}

void setup() {
  Serial.begin(115200);
  delay(300);

  alertService.begin();
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

  Serial.println();
  Serial.println("Smart Environmental Monitoring System");
  Serial.println("Initializing hardware...");

  displayService.begin();
  displayService.showStartup();

  if (!sensorService.begin()) {
    Serial.println("ERROR: BME280 was not found at I2C 0x76 or 0x77.");
    displayService.showSensorError();

    // Blink the LED to indicate a startup fault.
    while (true) {
      digitalWrite(PIN_ALERT_LED, HIGH);
      delay(200);
      digitalWrite(PIN_ALERT_LED, LOW);
      delay(200);
    }
  }

  Serial.println("BME280 initialized successfully.");
  printCsvHeader();
  lastSampleTimeMs = millis();
}

void loop() {
  const uint32_t now = millis();

  // Unsigned subtraction remains safe when millis() rolls over.
  if (now - lastSampleTimeMs < SENSOR_SAMPLE_INTERVAL_MS) {
    return;
  }
  lastSampleTimeMs = now;

  const EnvironmentReading reading = sensorService.read();

  if (!reading.valid) {
    Serial.println("ERROR: Invalid sensor reading.");
    return;
  }

  const bool alertActive = alertService.evaluate(reading);
  displayService.showReading(reading, alertActive);
  printCsvReading(reading, alertActive);
}
