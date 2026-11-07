# Wiring Guide

Power the ESP32 and modules from USB during initial testing. Use a 3.3V-compatible BME280 breakout and verify each module's pin labels.

## Shared I2C bus

| ESP32 DevKit | BME280 | SSD1306 OLED |
|---|---|---|
| 3V3 | VIN/VCC | VCC |
| GND | GND | GND |
| GPIO 21 | SDA | SDA |
| GPIO 22 | SCL | SCL |

The BME280 address is commonly `0x76` or `0x77`. The OLED address is commonly `0x3C`.

## Alert outputs

| ESP32 DevKit | Component |
|---|---|
| GPIO 2 | LED anode through a 220 ohm resistor |
| GND | LED cathode |
| GPIO 25 | Active buzzer module signal/input |
| GND | Buzzer module ground |

Use an active buzzer module compatible with the ESP32's 3.3V logic. If the buzzer draws more current than a GPIO can safely supply, use a transistor driver. Never connect a high-current load directly to an ESP32 GPIO.
