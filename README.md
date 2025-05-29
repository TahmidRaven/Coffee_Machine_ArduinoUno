# Smart Coffee Machine Project

## Overview
This project is a Smart Coffee Machine designed to automate the coffee-making process. The machine detects the presence of a mug, brews coffee, pours water, mixes ingredients, and monitors water levels and temperatures. The system is based on the Arduino Uno R3 microcontroller and integrates various sensors and communication protocols like I2C, GPIO, PWM, and OneWire.

The project aims to minimize human effort in making coffee while maintaining precision and consistency. The system integrates multiple components such as sensors, actuators, and displays to ensure the coffee-making process is fully automated.

## Project Video
[![Watch on YouTube](https://img.shields.io/badge/Watch%20on%20YouTube-FF0000?style=for-the-badge&logo=youtube)](https://youtube.com/shorts/YfagplvcO6o?si=1KiaXHhoE4QHvvBF)


## Project Structure
The project files are organized as follows:

```
│
├── code_files/
│ ├── Arduino1.ino # Code for the first Arduino (main coffee machine control)
│ └── Arduino2.ino # Code for the second Arduino (sensor and display control)
│
├── pictures/ # Folder containing images related to the project
│ ├── IMG_20250512_180700.jpg
│ ├── IMG_20250512_180727.jpg
│ ├── IMG_20250512_181339.jpg
│ ├── IMG_20250512_181503.jpg
│ └── IMG_20250512_181531.jpg
│
├── CoffeeMachine_Group9_Report.pdf # Final report in PDF format
├── LICENSE # Project license file (GNU)
└── README.md # This README file

```
## Developers
- **Tahmid Iqbal** (ID: 21201701)  
- Golam Sarwar Sami (ID: 21101276) 
- Farhan Tanvir Niloy (ID: 22301329)  
- Abrar Fahim (ID: 21301073) 

## Features
- Automated coffee brewing process
- IR sensor for mug detection
- Real-time display with OLED using I2C protocol
- Water pump and motor control using PWM
- Water level and temperature monitoring
- Audible alerts using a buzzer when brewing is done

## Hardware Components
1. **Microcontroller**: Arduino Uno R3
2. **Temperature Sensor**: LM35 / DS18B20
3. **Water Level Sensor**: YL-69 / HC-SR04
4. **Water Pump**: DC 3–6V Mini Pump
5. **Switch**: Rocker Switch KCD11
6. **Motor Driver**: L298N Module
7. **Display**: OLED (SSD1306)
8. **Buzzer**: Passive Buzzer Module
9. **Mixer Motor**: 3–12V Yellow DC Motor
10. **Power Supply**: 6V Battery + USB Power Bank
11. **Mug Detection Sensor**: IR Detection Sensor

## Communication Protocols Used
- **I2C**: Used for communication with the OLED Display (SSD1306).
- **GPIO (Digital I/O)**: Used for IR Sensor, Motor Driver (L298N), Buzzer, and Switch.
- **PWM**: Used to regulate motor and pump speed.
- **OneWire**: Used for DS18B20 Temperature Sensor for temperature monitoring.

## How It Works
1. The system detects the presence of a mug using the IR sensor.
2. The water level and temperature are checked.
3. If the conditions are met (sufficient water and proper temperature), the pump starts pouring water, and the motor begins grinding and mixing the ingredients.
4. Once brewing is done, the buzzer signals that the coffee is ready.

## Setup
1. **Hardware Setup**:
   - Connect the Arduino Uno R3 to all required components such as the IR sensor, water pump, motors, and OLED display.
   - Ensure proper power supply to both the Arduino and motors/pumps (separate power sources recommended for stability).

2. **Software Setup**:
   - Upload the provided Arduino code to the Arduino Uno R3 using the Arduino IDE.
   - Install necessary libraries for I2C, OLED display, and any other required components.

3. **Testing**:
   - Once the setup is complete, power the system on.
   - The system will automatically start, and the display will show "System Ready".
   - If a mug is detected, the coffee-making process will begin.

## Future Improvements
- **Touchscreen UI**: Integrate a touchscreen for beverage selection and custom control.
- **Flow Sensor**: Add a volumetric flow sensor for precise brew volume.
- **Mobile App**: Develop a mobile app for complete remote control of the coffee machine.

## Applications
- **Home Automation**: Can be integrated with home automation systems for an automated coffee brewing experience.
- **Office Kitchens**: Ideal for office smart kitchens, allowing employees to brew coffee without manual intervention.

## License
This project is licensed under the GNU License - see the [LICENSE](LICENSE) file for details.

---

Thank you for exploring this project! For any questions or contributions, feel free to reach out to the development team.
