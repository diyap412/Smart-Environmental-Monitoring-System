#pragma once
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "sensor_service.h"

class DisplayService {
 public:
  bool begin();
  void showStartup();
  void showSensorError();
  void showReading(const EnvironmentReading& reading, bool alertActive);

 private:
  Adafruit_SSD1306 display_{128, 64, &Wire, -1};
  bool ready_ = false;
};
