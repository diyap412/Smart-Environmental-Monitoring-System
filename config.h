#pragma once
#include <Arduino.h>

// I2C pins for the ESP32 DevKit.
constexpr uint8_t PIN_I2C_SDA = 21;
constexpr uint8_t PIN_I2C_SCL = 22;

// Output pins.
constexpr uint8_t PIN_ALERT_LED = 2;
constexpr uint8_t PIN_BUZZER = 25;

// Common I2C addresses.
constexpr uint8_t BME280_ADDRESS_PRIMARY = 0x76;
constexpr uint8_t BME280_ADDRESS_SECONDARY = 0x77;
constexpr uint8_t OLED_ADDRESS = 0x3C;

// Sampling and alert configuration.
constexpr uint32_t SENSOR_SAMPLE_INTERVAL_MS = 2000;
constexpr float TEMPERATURE_ALERT_C = 30.0f;
constexpr float HUMIDITY_ALERT_PERCENT = 70.0f;

// OLED dimensions.
constexpr int OLED_WIDTH = 128;
constexpr int OLED_HEIGHT = 64;
