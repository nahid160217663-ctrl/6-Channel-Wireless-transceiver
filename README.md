# 6-Channel Arduino Nano RF Transmitter

This is a simple DIY 6-channel RF transmitter built using Arduino Nano and nRF24L01 modules. It’s designed for projects like RC cars, drones, or any wireless control system where you need multiple inputs.

## Overview

The transmitter uses:

* 2 joystick modules (for analog control)
* 2 toggle switches (for digital inputs)
* nRF24L01 for wireless communication

Each joystick provides 2 axes, giving 4 analog channels. The 2 switches add 2 more channels, making a total of 6 channels.

## Features

* 6 independent control channels
* Wireless communication using nRF24L01
* Suitable for RC and robotics projects

## Hardware Used

* Arduino Nano
* nRF24L01 module
* 2x Joystick modules
* 2x Toggle switches
* Li-ion battery (with boost module)

## Channel Mapping

| Channel | Input Source        |
| ------- | ------------------- |
| CH1     | Joystick 1 - X axis |
| CH2     | Joystick 1 - Y axis |
| CH3     | Joystick 2 - X axis |
| CH4     | Joystick 2 - Y axis |
| CH5     | Switch 1            |
| CH6     | Switch 2            |

## How It Works

The Arduino reads analog values from the joysticks and digital values from the switches.
These values are packed into a struct and sent wirelessly using the nRF24L01 module.

On the receiver side, the data can be decoded and used to control motors, servos, or other actuators.

## Wiring Notes

* Joysticks are connected to analog pins (A1–A4)
* Switches use digital pins with INPUT_PULLUP
* nRF24L01 uses SPI (pins 7, 8, 11, 12, 13 on Nano)

Make sure:

* Use a stable 3.3V supply for nRF24L01
* Add a capacitor (10µF–100µF) across VCC and GND for stability

## Usage

1. Upload the transmitter code to Arduino Nano
2. Power the circuit
3. Move joysticks / toggle switches
4. Data will be sent continuously to the receiver


## Notes

This is a basic implementation meant for learning and experimentation.
You can expand it further depending on your project (like drones, RC planes, etc).

---

Built for fun and learning 🚀
