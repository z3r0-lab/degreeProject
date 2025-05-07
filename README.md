# 🎓 Head Pose-Controlled Servo System using MediaPipe and Arduino

This project was developed as part of my **Bachelor’s thesis**, combining computer vision with embedded systems to create an intuitive, real-time head pose-based control system for servo motors.

---

## 📘 Project Overview

The goal of the project is to design and implement a hands-free control system that tracks the user's head movement via webcam and translates that into physical servo motion using an Arduino. This system demonstrates the integration of **computer vision**, **3D pose estimation**, and **hardware actuation**.

---

## 🧠 Technologies Used

### Software (Python):
- [OpenCV](https://opencv.org/) – real-time image processing
- [MediaPipe Face Mesh](https://google.github.io/mediapipe/) – head pose estimation
- [NumPy](https://numpy.org/) – numerical operations
- [PySerial](https://pythonhosted.org/pyserial/) – serial communication with Arduino

### Hardware (Arduino):
- Arduino Uno (or compatible)
- 2 Servo Motors
- USB connection for serial data
- External 5V power supply (optional for servo power)

---

## ⚙️ How It Works

1. **Face Tracking**:  
   Using a webcam, `MediaPipe` detects facial landmarks and estimates the 3D rotation of the user's head via `solvePnP`.

2. **Pose Classification**:  
   The system determines if the user is:
   - Looking Left
   - Looking Right
   - Looking Up
   - Looking Down
   - Looking Forward (neutral)

3. **Serial Communication**:  
   A string command (e.g., `"Looking Right"`) is sent via USB to the Arduino.

4. **Servo Control**:  
   Based on the command, two servos are rotated to represent the user's head movement.

---

## 🔧 Installation & Setup

### 🖥 Python Side:

1. Install dependencies:
   ```bash
   pip install opencv-python mediapipe pyserial numpy
   
2. Connect Arduino and find the correct port (e.g., /dev/cu.usbserial-XXXX on Mac, COM3 on Windows).

3. Update the port in the Python script:
   ```python
   arduino = serial.Serial(port='/dev/cu.usbserial-10', baudrate=9600, timeout=.1)

4. Run the script:
   ```bash
   python3 head_pose_control.py

### 🤖 Arduino Side:

1. Upload the provided Arduino sketch from arduino_control.ino using the Arduino IDE.

2. Connect:
   Servo 1 to Pin 3 (horizontal)
   Servo 2 to Pin 4 (vertical)

3. Power your servos via 5V and GND.

### 🕹 Commands Sent from Python:

| Head Direction | Command Sent    | Servo Action            |
| -------------- | --------------- | ----------------------- |
| Looking Right  | `Looking Right` | Servo 1 to 25° (left)   |
| Looking Left   | `Looking Left`  | Servo 1 to 155° (right) |
| Looking Up     | `Looking Up`    | Servo 2 to 45° (up)     |
| Looking Down   | `Looking Down`  | Servo 2 to 145° (down)  |
| Forward        | `Forward`       | Both to 90° (neutral)   |

## 📷 Example Use Cases
* Touchless robot or device control
* Accessibility assistance for users with limited mobility
* Human-computer interaction research
* Real-time gesture-based interfaces

## 🧪 Limitations & Future Work

- Currently supports single-user tracking with a frontal webcam.

### Future Improvements:
- Use of IMU sensors for better precision
- BLE/Wi-Fi communication instead of USB
- Integration with robotic platforms or wheelchair systems


## 🎓 Author

**Bagzhan Artykbai**  
Bachelor of Engineering in Robotics and Automation  
**Almaty University of Power Engineering and Telecommunications (AUES)**

