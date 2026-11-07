#include "sensor_service.h"
#include "config.h"

bool SensorService::begin() {
  ready_ = bme_.begin(BME280_ADDRESS_PRIMARY);
  if (!ready_) {
    ready_ = bme_.begin(BME280_ADDRESS_SECONDARY);
  }
  return ready_;
}

EnvironmentReading SensorService::read() {
  EnvironmentReading result{};
  result.timestampMs = millis();
  result.valid = ready_;

  if (!ready_) {
    return result;
  }

  result.temperatureC = bme_.readTemperature();
  result.humidityPercent = bme_.readHumidity();
  result.pressureHpa = bme_.readPressure() / 100.0f;

  // Reject non-finite or obviously invalid readings.
  result.valid = isfinite(result.temperatureC) &&
                 isfinite(result.humidityPercent) &&
                 isfinite(result.pressureHpa) &&
                 result.humidityPercent >= 0.0f &&
                 result.humidityPercent <= 100.0f &&
                 result.pressureHpa > 0.0f;

  return result;
}

bool SensorService::isReady() const {
  return ready_;
}
