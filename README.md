# Emergent user interfaces

## Development

* Setup vscode with the recommended extensions
* Install the required arduino packages with Arduino Library Manager (ctrl+shift+p):
  * Arduino_LSM9DS1, Version 1.1.1 
  * Adafruit LSM6DS, Version 4.7.2
  * Adafruit LIS3MDL, Version 1.2.4
* Install the required arduino packages with Arduino Board Manager (ctrl+shift+p):
  * Arduino Mbed OS Nano Boards, 4.0.8

Note: the arduino Nano 33 incldes an IMU chip but I also included refs to the Adafruit as I have a couple of them. Well see which ones are more accurate.

The vscode extension uses the included arduino cli but you still need g++, Install packages (ubuntu):

```bash
sudo apt install build-essential
```

The intellisense generation [is a bit lacking](https://github.com/microsoft/vscode-arduino/issues/1265) so I suggest to generate the intellisense configuration using 'Arduino: Rebuild Intellisense Configuration' for the project once and adding the missing libraries to the includePath in the c_cpp_properties.json file. Before you do that set 'arduino.disableIntelliSenseAutoGen' to false in ./vscode/arduino.json.

Add python packages:

```bash
pip install -r requirements.txt
```

### Port permissions

I had few issues with permissions on ubuntu, create [udev file](https://askubuntu.com/questions/15570/configure-udev-to-change-permissions-on-usb-hid-device/15643#15643) shoud be created, for reference I used:

```
SUBSYSTEM=="usb"
ATTRS{idVendor}=="2341"
ATTRS{idProduct}=="805a"
MODE="0666"
```

## Hardware

* [Arduino Nano 33 BLE Sense](https://docs.arduino.cc/hardware/nano-33-ble-sense/?queryID=undefined)
* [Adaafruit LSM6D33 + LIS3MDL 9-DoF IMU](https://www.adafruit.com/product/4485)

## Library references

* [Arduino Mbed OS Nano Boards](https://github.com/arduino/ArduinoCore-mbed)
* [Arduino_LSM9DS1](https://www.arduino.cc/reference/en/libraries/arduino_lsm9ds1/?_gl=1*1cuw2kt*_ga*MTcyMDAzNjA4Ny4xNzA3MjA3NTIz*_ga_NEXN8H46L5*MTcwNzIwNzUyMy4xLjEuMTcwNzIwODU0Ni4wLjAuMA..*_fplc*d2Y1b1k4a2NQTXclMkJueDdySW5BQXpncEw4UmJodnBndktxc1FpQTdaa3JwTVlWUjI4c2UyMWtZTWJEU1U2RE51U3VaN1RDRkRIUWlOUDdYSzU4bzUwQkloc09lZyUyQkZmSG9iRUxGaFdZYm04SEMwNVZaa3ZSTFpBZFBQR2xVQSUzRCUzRA..)
* [Adafruit_LSM6DS3](https://github.com/adafruit/Adafruit_LSM6DS)
* [Adafruit_LIS3MDL](https://github.com/adafruit/Adafruit_LIS3MDL)