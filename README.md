# Automatic Irrigation System

## Overview
This repository contains the implementation of a **smart irrigation system** designed to optimize water usage for gardening and agriculture. The system uses sensors and an Arduino-based controller to automate watering tasks while minimizing water waste. Key features include real-time monitoring, automated water pump control, and an LCD interface for user feedback.

---

## Features
- **Soil Moisture and Rainfall Monitoring**: Continuously tracks soil and weather conditions to determine watering needs.
- **Automated Watering**: Activates the water pump only when necessary, ensuring efficient irrigation.
- **Real-Time Feedback**: Displays live updates on soil moisture, rainfall status, and pump activity via an LCD module.

---

## Repository Structure
```plaintext
- autowateringsys/
            - Box/
                        - Lid.stl
                        - Box.stl
            - hardware/
                        - circuit-diagram.png
                        - installed_modules.png
            - Datasheets/
                        - rainsensor.pdf
                        - moisture detector.pdf
            - src/
                        - WateringSys.ino
            - video and pictures/
                        - rain.mp4
                        -soildry.png
                        -soilwet.png
            - README.md
```

---

## How It Works
1. **Data Collection**: Sensors monitor soil moisture and rainfall.
2. **Decision Making**: The Arduino controller evaluates data and compares it to preset thresholds.
3. **Action Execution**: The relay module controls the water pump to irrigate the soil.
4. **User Feedback**: Real-time data is displayed on the LCD for monitoring.

---

## Getting Started

### Hardware Setup
1. Download .stl files in folder box which are the models for 3D printing.
2. Connect the rain sensor to A0 and the soil moisture sensor to A3 on the Arduino.
3. Wire the LCD module via the I2C interface (SDA to A4, SCL to A5).
4. Attach the relay module to Pin 8 for controlling the water pump.
5. Refer to the circuit diagram in `/hardware/circuit-diagram.png` for detailed wiring.
   And inside of container after installing all modules should looks like the diagram `/hardware/installed_graph.png` 

### Software Setup
1. Install the Arduino IDE and the `LiquidCrystal_I2C` library.
2. Open `src/main.ino` in the Arduino IDE.
3. Upload the code to the Arduino board.
4. Power the system with a 5V DC source or USB connection.

---

## Testing and Results
- **Dry Soil**: Pump activated within 2 seconds, ensuring timely irrigation.
- **Wet Soil**: Pump remained off, conserving water.
- **Rainfall**: Irrigation paused immediately upon detecting rain.

The system was tested under various environmental conditions, and the following results were recorded:

| Condition             | Soil Moisture (%) | Rainfall Detected | Pump Status  | Notes                  |
|-----------------------|-------------------|-------------------|--------------|------------------------|
| Dry soil, no rain     | 30%              | No                | Activated    | Need watering |
| Wet soil, no rain     | 60%              | No                | Inactive     | No need watering |
| Dry soil, with rain   | 30%              | Yes               | Inactive     | No need watering      |
| Wet soil, with rain   | 50%              | Yes               | Inactive     | No need watering       |

Detailed test result video are available in the `autowateringsys/videos/` directory.

---

## Future Enhancements
- **Additional Sensors**: Integrate temperature and light sensors for comprehensive environmental monitoring.
- **Remote Access**: Add Wi-Fi or Bluetooth modules for remote monitoring and control via a mobile app.
- **Compact Design**: Redesign the enclosure to make the system more portable and aesthetically pleasing.
- **Solar Power Integration**: Incorporate solar panels to enable off-grid operation.

---

## Debugging and Challenges
- **Sensor Calibration**: Early readings from the soil moisture sensor showed inconsistencies, which were resolved through calibration using test soil samples.
- **Rain Sensor Noise**: Fluctuations in rain sensor readings were stabilized by adding a resistor and applying a software smoothing algorithm.
- **Power Distribution**: To support multiple components, a power distribution module was introduced, ensuring stable voltage supply.
  
---
## References
•DatasheetHub (2022) Rain Sensor Module: Technical Datasheet [PDF]. Available at: https://datasheethub.com/wp-content/uploads/2022/10/rain_sensor_module.pdf (Accessed: 7 January 2025).
•DFRobot (2022) SEN0114 Soil Moisture Sensor: Technical Datasheet [PDF]. Available at: https://www.datasheethub.com/wp-content/uploads/2022/08/SEN0114_Web.pdf (Accessed: 7 January 2025).
