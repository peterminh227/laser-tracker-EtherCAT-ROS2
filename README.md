# LaserTracker ROS2 

**Authors:** Gerald Ebmer, Minh Nhat Vu

## Overview

This project contains two main components for sending and receiving EtherCAT messages via UDP. The goal is to communicate with a 6-DoF Laser Tracker and publish its pose data to ROS 2 (Humble).

### Project Structure

1. **LaserTracker_TwinCAT**
   - This folder contains the working files for sending EtherCAT messages over UDP.
   - **UDP Configuration:**
     - Port: `10000`
     - IP Address: `192.168.0.123`
   - It establishes the communication with the Laser Tracker system using these settings.

2. **6-DoF-LaserTracker-ros2-humble**
   - This package is for receiving the UDP messages and passing the data as pose messages to a ROS 2 topic. It consists of two sub-packages:
     - **lasertracker** (C++): This package receives UDP packets asynchronously and publishes them to a ROS 2 topic.
     - **udp_LaserTracker** (Python): This package receives UDP packets synchronously and publishes them to a ROS 2 topic.

## Usage

To run the UDP listeners and handle Laser Tracker data in ROS 2, follow these steps:

### Python Version (Synchronous)
Run the Python UDP listener using:
```bash
ros2 run udp_LaserTracker udp_LaserTracker_listener
```
### C++ Version (Asynchronous)
Run the Python UDP listener using:
```bash
ros2 run lasertracker lasertracker
```
### Instruction of creating TwinCAT projects
```
please follow instrution in LaserTracker_UDP.pdf
```
