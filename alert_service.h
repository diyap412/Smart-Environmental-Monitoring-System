#pragma once
#include <Arduino.h>
#include "sensor_service.h"

class AlertService {
 public:
  void begin();
  bool evaluate(const EnvironmentReading& reading);
  bool isAlertActive() const;

 private:
  bool alertActive_ = false;
};
