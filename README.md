# Function-generator-using-8051-microcontroller

## Introduction
This project is a versatile function generator based on the 8051 microcontroller. It allows users to generate and manipulate different types of waveforms, such as Square, Sinusoid, Sawtooth, and Triangular, through a keypad interface. The generated waveforms can be visualized in real-time using the EDSim51 DAC scope.

## Project Overview
The function generator includes the following features:
- **Waveform Types**: Square, Sinusoid, Sawtooth, and Triangular
- **Amplitude Scaling**: 0.5x, 1x, 2x
- **Frequency Scaling**: 0.5x, 1x, 2x
- **DAC Resolution Scaling**: 3-bit, 5-bit, 8-bit

## Components
- 8051 Microcontroller
- Keypad Interface
- DAC (Digital-to-Analog Converter)

## Code
The project is implemented in Keil C. The source code can be found in the `src` directory.

## Full Project Report
For a detailed explanation of the project, including design considerations, challenges faced, and conclusions, please refer to the full project report available [here](https://drive.google.com/file/d/1MI7ayvY2UY3Qfk63b5VnnG9CX0VVR8bu/view?usp=sharing).

## Problems Faced
- **Time Lag Error**: The transition between different waveforms experienced delays.
- **Sine Wave Resolution**: Difficulty achieving desired resolution in generated sine waves.
- **Distorted Waveforms**: Visual distortions in complex waveform signals in EDSim.

## Conclusion
This project demonstrates the capabilities of the 8051 microcontroller in generating and manipulating waveforms. It provides a useful educational tool for understanding microcontroller interfacing and waveform generation.

## Author
Himanshu Kohade (BT21ECE086)
Semester 5, VNIT Nagpur
