# Emergent user interfaces

## Development

* Setup vscode with the recommended extensions
* Install the required arduino packages with Arduino Library Manager (ctrl+shift+p): 
  * Adafruit LSM6DS, Version 4.7.2
  * Arduino Mouse, 1.0.1
* Install the required arduino packages with Arduino Board Manager (ctrl+shift+p):
  * Arduino AVR Boards, 1.8.6

The vscode extension uses the included arduino cli but you still need g++, Install packages (ubuntu):

```bash
sudo apt install build-essential
```

The intellisense generation [is a bit lacking](https://github.com/microsoft/vscode-arduino/issues/1265) so I suggest to generate the intellisense configuration using 'Arduino: Rebuild Intellisense Configuration' for the project once and adding the missing libraries to the includePath in the c_cpp_properties.json file. Before you do that set 'arduino.disableIntelliSenseAutoGen' to false in ./vscode/arduino.json.

### Port permissions

This should not be relevant when using arduino micro but I'll leave it here. I had few issues with permissions on ubuntu, create [udev file](https://askubuntu.com/questions/15570/configure-udev-to-change-permissions-on-usb-hid-device/15643#15643) shoud be created, for reference I used:

```
SUBSYSTEM=="usb"
ATTRS{idVendor}=="2341"
ATTRS{idProduct}=="805a"
MODE="0666"
```

## Hardware

* [Arduino Micro](https://docs.arduino.cc/hardware/micro/)
* [Adaafruit LSM6D33 + LIS3MDL 9-DoF IMU](https://www.adafruit.com/product/4485)

## Library references

* [Arduino Mbed OS Nano Boards](https://github.com/arduino/ArduinoCore-mbed)
* [Adafruit_LSM6DS3](https://github.com/adafruit/Adafruit_LSM6DS)
* [Adafruit_LIS3MDL](https://github.com/adafruit/Adafruit_LIS3MDL)
* [Mouse](https://www.arduino.cc/reference/en/libraries/mouse/)