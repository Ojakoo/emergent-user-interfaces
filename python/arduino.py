import serial

from constants import *

"""
API for handling arduino communication and control
"""

class Arduino:
    def __init__(self, data):
        super(Arduino, self).__init__()
        self.name = data[1]
        self.port = data[0]
        self.serial = serial.Serial(data[0], 14400, timeout=1)

    def handshake(self):
        try:
            print("\nStarting handshake.")

            self.serial.write(bytes([HANDSHAKE]))

            answer = self.serial.readline()
            print(answer.decode())

        except serial.SerialException:
            print("Handshake failed")

    # def open_serial(self):
    #     self.serial.open()

    # def close_serial(self):
    #     self.serial.close()
