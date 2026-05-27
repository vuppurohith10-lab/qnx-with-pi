🔧 QNX with Raspberry Pi

This repository contains basic and intermediate projects using QNX RTOS with Raspberry Pi.

The projects demonstrate:

GPIO programming
LED blinking
7-segment display control
LCD interfacing
Client-server communication using QNX IPC
📌 Features
QNX RTOS programming
Raspberry Pi hardware interfacing
GPIO control
LCD display communication
Client-server architecture
Embedded C programming
📂 Project Structure
qnx-with-pi/
│
├── helloworld/        # Basic QNX hello world
├── ledblink/          # LED blinking using GPIO
├── segmentclient/     # 7-segment client
├── segmentserver/     # 7-segment server
│
├── lcd.c              # LCD interfacing
├── lcdclient.c        # LCD client program
├── lcdserver.c        # LCD server program
│
└── README.md
⚙️ Projects
1️⃣ Hello World

Basic QNX program for beginners.

2️⃣ LED Blink

Controls Raspberry Pi GPIO to blink an LED using QNX.

Features
GPIO access
LED ON/OFF control
Timing using delays
3️⃣ 7-Segment Display

Client-server model for controlling a 7-segment display.

Features
QNX IPC communication
Server handles display control
Client sends digit data
4️⃣ LCD Interfacing

Displays text on LCD using Raspberry Pi GPIO.

Features
LCD control using Embedded C
QNX hardware access
Client-server communication
Message passing
🧠 Technologies Used
QNX RTOS
Embedded C
Raspberry Pi
GPIO Programming
QNX IPC
Client-Server Architecture
🚀 Learning Goals

This repository helps in learning:

Real-Time Operating Systems (RTOS)
Embedded Systems Programming
Hardware interfacing
QNX Neutrino IPC
GPIO handling on Raspberry Pi
▶️ Build and Run

Example:

qcc program.c -o output
./output





👨‍💻 Author
Rohith Vuppu

Embedded Systems | QNX | Raspberry Pi | Embedded Linux
