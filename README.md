# Smart-Building-Security-Access-Control-and-IoT-Monitoring-System
Smart Building Security, Access Control and IoT Monitoring System
An intelligent, multi-level authenticated embedded security and IoT monitoring solution powered by the LPC2129 ARM7 Microcontroller. This project integrates contactless identification, biometric verification, password security, real-time logging, cloud connectivity, and industrial networking into a unified platform suitable for modern smart buildings.
🚀 Key Features
 * Multi-Level Authentication: Sequential validation using an RC522 RFID Reader, an Arduino-controlled R307S Fingerprint Sensor, and a 4\times4 Matrix Keypad.
 * Automated Access Control: Relays and servo motors mechanically manage the electromagnetic lock.
 * Comprehensive Environmental & Security Sensing: Features PIR Motion Sensors for occupancy detection and Magnetic Door Sensors for breach detection.
 * Real-Time Event Logging: Timestamps every security event using the DS1307 RTC, storing permanent configurations in AT24C256 EEPROM and detailed logs on an SD Card Module.
 * IoT Cloud Integration: Live event uploading and remote monitoring capabilities via the ESP-01 Wi-Fi Module connected to ThingSpeak.
 * Industrial CAN Networking: Inter-controller communication via the MCP2551 CAN Transceiver to synchronize multiple security nodes across buildings.
🛠️ Technology Stack & Hardware Components
 * Microcontroller: LPC2129 ARM7 (Main Controller), Arduino UNO (Fingerprint Sub-controller)
 * Programming Language: Embedded C
 * Authentication & Input: RC522 RFID Reader, R307S Fingerprint Sensor, 4\times4 Matrix Keypad, User Switches (SW1–SW3)
 * Sensors & Peripherals: PIR Motion Sensor, Magnetic Door Sensor, DS1307 RTC, 16x2 LCD Display
 * Storage & Communication: AT24C256 EEPROM, SD Card Module, ESP-01 Wi-Fi Module, MCP2551 CAN Transceiver
 * Actuators & Outputs: Relay Module, Electromagnetic Door Lock, Servo Motor, LED Indicators (Red/Yellow/Green), Buzzer
 * Cloud Platform: ThingSpeak IoT Cloud
⚙️ System Architecture & Block Diagram
The LPC2129 microcontroller coordinates peripheral controls, data storage management, cloud communication, and CAN packet distribution.
 [Input Devices] ──> [LPC2129 ARM7 MCU] ──> [Outputs / Actuators]
       │                      │
       ├─► RFID / Fingerprint ├─► SD Card & EEPROM (Storage)
       ├─► Keypad & Sensors   ├─► ESP-01 Wi-Fi (ThingSpeak Cloud)
       └─► RTC (Timekeeping)  └─► MCP2551 Transceiver (CAN Bus)

📂 Repository Structure
├── src/                 # Embedded C source files for LPC2129
├── arduino/             # Arduino UNO fingerprint processing code
├── include/             # Header files and configurations
├── docs/                # Circuit schematics and block diagrams
└── README.md            # Project documentation

📊 Working Workflow
 * Detection: The PIR motion sensor detects an approaching user, prompting the LCD to invite authentication.
 * Authentication Sequence:
   * Level 1: RC522 scans the employee RFID card.
   * Level 2: If RFID requires secondary validation or fails over, the R307S fingerprint sensor verifies the biometrics via Arduino.
   * Level 3: Fallback password verification via the 4\times4 keypad.
 * Access Execution: Upon successful validation, the relay energizes the lock and the servo motor opens the door temporarily.
 * Logging & Uplink: The DS1307 stamps the event time, logs it to the SD card/EEPROM, updates ThingSpeak via Wi-Fi, and broadcasts status updates across the CAN network.
🏢 Applications
 * Corporate Offices & Industrial Plants
 * Data Centers & Research Laboratories
 * Educational Institutions & Smart Residential Buildings
