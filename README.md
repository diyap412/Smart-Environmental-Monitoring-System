# Smart Environmental Monitoring System

An ESP32-based embedded system that monitors temperature, relative humidity, and atmospheric pressure using a BME280 sensor. The system displays live measurements on an SSD1306 OLED, streams CSV readings over USB serial, and activates an LED and buzzer when configured environmental thresholds are exceeded.

## Features

- Temperature, humidity, and pressure sensing.
- I2C communication with BME280 and OLED modules.
- Periodic sampling every two seconds.
- OLED live data display.
- CSV serial logging for later analysis.
- Configurable temperature and humidity alerts.
- LED and active buzzer warning outputs.
- Basic sensor initialization and reading validation.
- Modular source code split into sensor, display, and alert services.

## Hardware

- ESP32 DevKit V1
- BME280 sensor breakout
- SSD1306 128x64 I2C OLED
- LED and 220 ohm resistor
- 3.3V-compatible active buzzer module
- Breadboard and jumper wires

Estimated component cost: approximately $20–$45 depending on suppliers and parts selected.

## Software

- C++
- Arduino framework
- PlatformIO
- Adafruit BME280 library
- Adafruit SSD1306 library
- Adafruit GFX library

## Setup

1. Install Visual Studio Code.
2. Install the PlatformIO IDE extension.
3. Open this folder in VS Code.
4. Connect the ESP32 over USB.
5. Build and upload the `esp32dev` PlatformIO environment.
6. Open the Serial Monitor at 115200 baud.

PlatformIO installs the libraries declared in `platformio.ini`.

## Wiring

See [`docs/WIRING.md`](docs/WIRING.md) for the complete wiring table.

The I2C bus uses GPIO 21 (SDA) and GPIO 22 (SCL). The BME280 is searched at addresses `0x76` and `0x77`; the OLED is configured for `0x3C`.

## Configuration

Change thresholds and sampling interval in `include/config.h`:

```cpp
constexpr uint32_t SENSOR_SAMPLE_INTERVAL_MS = 2000;
constexpr float TEMPERATURE_ALERT_C = 30.0f;
constexpr float HUMIDITY_ALERT_PERCENT = 70.0f;
```

These are demonstration thresholds. Choose values appropriate for the environment you are monitoring.

## Serial output

The Serial Monitor outputs comma-separated values:

```text
time_ms,temperature_c,humidity_percent,pressure_hpa,alert
2000,23.45,41.20,1008.32,0
4000,23.47,41.18,1008.30,0
```

The `alert` column is `1` when either configured threshold is reached and `0` otherwise.

## Project structure

```text
Smart-Environmental-Monitoring-System/
├── include/
│   ├── config.h
│   ├── sensor_service.h
│   ├── alert_service.h
│   └── display_service.h
├── src/
│   ├── main.cpp
│   ├── sensor_service.cpp
│   ├── alert_service.cpp
│   └── display_service.cpp
├── docs/
│   ├── WIRING.md
│   └── TEST_PLAN.md
├── platformio.ini
└── README.md
```

## Testing

Follow [`docs/TEST_PLAN.md`](docs/TEST_PLAN.md). Test the OLED, sensor readings, serial output, both alert conditions, and sensor-disconnect behavior. Add photos and real test results after assembling the circuit.

## Future improvements

- Wi-Fi dashboard with historical charts.
- SD card or flash storage.
- User-adjustable thresholds.
- Sensor calibration and fault recovery.
- FreeRTOS tasks for sensor acquisition, display refresh, and communications.
- Automated unit tests for alert logic.

## Current project status

Starter firmware and documentation are provided. Physical assembly, compilation on the target board, and hardware validation still need to be completed. Do not report measured performance or successful hardware tests until you have verified them yourself.
