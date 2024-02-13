from constants import *

import serial
import serial.tools.list_ports
import mouse

from arduino import Arduino

class Controller:
    def __init__(self):
        super(Controller, self).__init__()

        self.arduino = self.create_arduino()

    def command_loop(self):
        print("Command loop started.")
        while True:
            cmd = int(input("Give command.\n"))

            if cmd == IDLE:
                pass
            elif cmd == START:
                self.send_sensor_data()
            else:
                print("No command available.")

    def send_sensor_data(self):
        if self.arduino == None:
            print("No device found.")
            return

        self.arduino.serial.write(bytes([START]))

        print('Reading data from arduino:')
        while True:
            # Read data from arduino, prob need to set some way to control the sample rate?
            try:
                line = self.arduino.serial.readline()
                dataArr = line.decode('UTF-8').rstrip().split(',')

                print(dataArr)

                # calculate the x and y values from the sensor data
                x = float(dataArr[0]) * 100
                y = float(dataArr[1]) * 100

                mouse.move(y, x, absolute=False, duration=0)

            except serial.SerialException:
                print(
                    "Something went wrong with serial communication.\nCheck Arduino connection."
                )
                break

            except KeyboardInterrupt:
                self.arduino.serial.write(bytes([IDLE]))
                print("\nExit data read.")
                break

    # Arduino port handling should probably be moved to arduino class
    def create_arduino(self):
        while True:
            ports = list(serial.tools.list_ports.comports())

            try:
                for port in ports:
                    print("Found in ", port[0], ": ", port[1])
                    if port[1] == "Nano 33 BLE":
                        arduino = Arduino(port)

                        if arduino.serial.isOpen():
                            print("Serial port is open.")
                            return arduino
                        else:
                            print("Serial port is not open, aborting.")
                            return None

                i = input("No device found, do you want to try again? (y/n)")

                if i.lower() == "y" or "yes":
                    pass
                elif i.lower() == "n" or "no":
                    exit()
                else:
                    return None

            except UnboundLocalError:
                i = input("No device found, do you want to try again? (y/n)")

                if i.lower() == "y" or "yes":
                    pass
                else:
                    return None
