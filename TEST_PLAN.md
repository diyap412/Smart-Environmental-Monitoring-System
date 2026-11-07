# Test Plan

| Test | Procedure | Expected result |
|---|---|---|
| Startup | Power on with modules connected | Startup message appears |
| Sensor initialization | Observe Serial Monitor | BME280 initialization succeeds |
| OLED | Observe display | Live temperature, humidity, pressure appear |
| Serial logging | Open at 115200 baud | CSV header and rows appear |
| Temperature alert | Temporarily set temperature threshold below room temperature | LED and buzzer activate |
| Humidity alert | Temporarily set humidity threshold below current humidity | LED and buzzer activate |
| Sensor fault | Disconnect BME280 and restart | Error appears and LED blinks |

Record the actual result, date, and setup for every test. Do not claim tests passed until you have run them on the physical hardware.
