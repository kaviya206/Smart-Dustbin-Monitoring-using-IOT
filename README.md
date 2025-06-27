# Smart Bin Monitoring System using IoT

This project is a smart dustbin system that detects the fill level of a bin using an ultrasonic sensor and displays the status through LEDs and the Blynk IoT platform. It helps automate waste monitoring in public or private areas by alerting users when the bin is full.



## Features

- Real-time bin status monitoring using an ultrasonic sensor
- Automatic LED indication for bin full or empty
- IoT-based alert system via Blynk cloud
- Push notification when the bin is full
- Compact and power-efficient design using ESP32
- Simple and cost-effective solution

## Components Used

| Component                 | Specification / Role                                    | Quantity |
|--------------------------|----------------------------------------------------------|----------|
| **ESP32 Dev Board**      | Microcontroller with built-in Wi-Fi, controls the system | 1        |
| **HC-SR04 Ultrasonic Sensor** | Measures the distance between bin lid and waste surface   | 1        |
| **Red LED**              | Indicates bin is full                                    | 1        |
| **Green LED**            | Indicates bin is empty                                   | 1        |
| **220Ω Resistor**        | Current limiter for each LED                             | 2        |
| **Jumper Wires (Male-to-Male)** | Used to connect components                         | As needed |

## Circuit Connections

| ESP32 Pin   | Connected To                      | Description                        |
|-------------|-----------------------------------|------------------------------------|
| 3V3         | VCC of HC-SR04                    | Power supply to sensor             |
| GND         | GND of HC-SR04 and LED cathodes   | Common ground                      |
| GPIO 16     | Trigger pin of HC-SR04            | Sends ultrasonic pulse             |
| GPIO 17     | Echo pin of HC-SR04               | Receives reflected pulse           |
| GPIO 2      | Anode of Red LED via 220Ω resistor| Indicator for "Bin Full"           |
| GPIO 4      | Anode of Green LED via 220Ω resistor| Indicator for "Bin Empty"        |

## Circuit Connections
![Screenshot (94)](https://github.com/user-attachments/assets/78314635-4d71-4ca5-bcd9-2cd433e5442d)


## Working

- The HC-SR04 ultrasonic sensor measures the distance between the sensor and the garbage surface inside the bin.
- If the distance is **less**, the bin is considered **full**.
- If the distance is **more**, the bin is considered **empty**.
- The status is reflected using:
  - **Red LED ON** = Bin Full
  - **Green LED ON** = Bin Empty
- Notifications are sent via **Blynk Cloud** using a custom event (`bin_alert`).


## Application

- Smart Campuses and Universities
- Office or corporate waste monitoring
- Public waste bins in malls or bus stations
- Smart homes
- Industrial waste management systems



## Conclusion

This Smart Bin system provides a simple and efficient way to manage waste overflow by combining real-time monitoring and wireless alerting. It ensures cleanliness and reduces manual checking of bins in both small and large-scale facilities.



## Developed By

**Kaviya R**
ECE Student
