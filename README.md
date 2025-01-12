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



---

## How It Works
1. **Data Collection**: Sensors monitor soil moisture and rainfall.
2. **Decision Making**: The Arduino controller evaluates data and compares it to preset thresholds.
3. **Action Execution**: The relay module controls the water pump to irrigate the soil.
4. **User Feedback**: Real-time data is displayed on the LCD for monitoring.

---

## Getting Started

### Hardware Setup
1. Connect the rain sensor to A0 and the soil moisture sensor to A3 on the Arduino.
2. Wire the LCD module via the I2C interface (SDA to A4, SCL to A5).
3. Attach the relay module to Pin 8 for controlling the water pump.
4. Refer to the circuit diagram in `/hardware/circuit-diagram.png` for detailed wiring.

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

---

## Future Enhancements
- **Additional Sensors**: Add temperature and light sensors to provide comprehensive environmental data.
- **Remote Access**: Integrate Wi-Fi or Bluetooth modules for remote monitoring and control via a mobile 


