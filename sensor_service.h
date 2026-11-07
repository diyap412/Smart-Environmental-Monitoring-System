#pragma once
#include <Arduino.h>
#include <Adafruit_BME280.h>

struct EnvironmentReading {
  float temperatureC;
  float humidityPercent;
  float pressureHpa;
  uint32_t timestampMs;
  bool valid;
};

class SensorService {
 public:
  bool begin();
  EnvironmentReading read();
  bool isReady() const;

 private:
  Adafruit_BME280 bme_;
  bool ready_ = false;
};
