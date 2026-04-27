# 🚗 Speed Detection Radar using Arduino and IR Sensors

A low-cost Arduino-based system to measure the speed of moving objects using two IR sensors.

---

## 📌 Features
- Measures speed in **cm/s and km/h**
- Uses dual IR sensors for detection
- Displays output on **16x2 LCD (I2C)**
- Speed limit alert system
- LED and buzzer warning

---

## 🧠 Working Principle

Two IR sensors are placed at a fixed distance.

- When object crosses Sensor 1 → timer starts  
- When object crosses Sensor 2 → timer stops  

Speed is calculated using:

Speed (cm/s) = Distance / Time  
Speed (km/h) = Speed (cm/s) × 0.036  

---

## 🛠 Components Used

- Arduino Uno  
- 2 × IR Sensors  
- 16x2 LCD Display (I2C)  
- LED  
- Buzzer  
- Breadboard  
- Jumper Wires  

---

## 🔌 Circuit Connections

See: `circuit/connections.txt`

---

## 📷 Project Images
[Setup](setup.jpg)
