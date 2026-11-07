#include "alert_service.h"
#include "config.h"

void AlertService::begin() {
  pinMode(PIN_ALERT_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_ALERT_LED, LOW);
  digitalWrite(PIN_BUZZER, LOW);
}

bool AlertService::evaluate(const EnvironmentReading& reading) {
  if (!reading.valid) {
    alertActive_ = false;
  } else {
    alertActive_ =
        reading.temperatureC >= TEMPERATURE_ALERT_C ||
        reading.humidityPercent >= HUMIDITY_ALERT_PERCENT;
  }

  digitalWrite(PIN_ALERT_LED, alertActive_ ? HIGH : LOW);
  digitalWrite(PIN_BUZZER, alertActive_ ? HIGH : LOW);
  return alertActive_;
}

bool AlertService::isAlertActive() const {
  return alertActive_;
}
