# Arduino-Based Physical Honeypot

## Overview
This project is an Arduino-based physical honeypot prototype designed to simulate a secure access terminal and record interaction attempts. It demonstrates basic cybersecurity concepts related to deception, event logging, and security monitoring.

## Objectives
- Simulate a restricted-access terminal.
- Detect and record user interaction attempts.
- Demonstrate basic security event logging.
- Explore how honeypot concepts can be applied to physical devices.

## Hardware Components
- Arduino Uno or Arduino Nano
- 16x2 LCD with I2C module
- Push button
- MicroSD card module and microSD card
- Buzzer
- Breadboard and jumper wires

## How It Works
1. The LCD displays a simulated secure terminal welcome message.
2. The user presses the button to simulate an access attempt.
3. The system displays an access-denied message and activates the buzzer.
4. The Arduino records the event in a log file on the microSD card.
5. The display returns to its initial state for the next attempt.

## Cybersecurity Concepts
- Honeypot and deception techniques
- Unauthorized access simulation
- Event logging and monitoring
- Physical security awareness

## Project Status
Prototype
The current design and code demonstrate the initial concept. Hardware integration, testing, and validation are required before the system can be considered fully functional.

## Ethical Considerations
This project is intended for educational and authorized testing purposes. It simulates physical access attempts and does not target real systems or collect actual sensitive information.

## Future Improvements (working on it)
- Add RFID-based interaction.
- Include timestamps using a Real-Time Clock (RTC) module.
- Improve event logging and reporting.
- Add a serial interface for reviewing recorded events.

## Author
j.alfouzan
Cybersecurity Student.
