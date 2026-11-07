#include "display_service.h"
#include "config.h"

bool DisplayService::begin() {
  ready_ = display_.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  if (ready_) {
    display_.clearDisplay();
    display_.setTextColor(SSD1306_WHITE);
    display_.setTextSize(1);
    display_.setCursor(0, 0);
    display_.println("Environmental Monitor");
    display_.println("Initializing...");
    display_.display();
  }
  return ready_;
}

void DisplayService::showStartup() {
  if (!ready_) return;

  display_.clearDisplay();
  display_.setTextSize(1);
  display_.setCursor(0, 0);
  display_.println("ENVIRONMENT MONITOR");
  display_.println();
  display_.println("Starting sensors...");
  display_.display();
}

void DisplayService::showSensorError() {
  if (!ready_) return;

  display_.clearDisplay();
  display_.setTextSize(1);
  display_.setCursor(0, 0);
  display_.println("SENSOR ERROR");
  display_.println();
  display_.println("Check BME280 wiring");
  display_.println("I2C: 0x76 / 0x77");
  display_.display();
}

void DisplayService::showReading(const EnvironmentReading& reading,
                                 bool alertActive) {
  if (!ready_ || !reading.valid) return;

  display_.clearDisplay();
  display_.setTextSize(1);
  display_.setTextColor(SSD1306_WHITE);
  display_.setCursor(0, 0);

  display_.println("ENVIRONMENT MONITOR");
  display_.println("--------------------");

  display_.print("Temp: ");
  display_.print(reading.temperatureC, 1);
  display_.println(" C");

  display_.print("Humidity: ");
  display_.print(reading.humidityPercent, 1);
  display_.println(" %");

  display_.print("Pressure: ");
  display_.print(reading.pressureHpa, 1);
  display_.println(" hPa");

  display_.println();
  display_.println(alertActive ? "WARNING: LIMIT EXCEEDED" : "Status: NORMAL");
  display_.display();
}
