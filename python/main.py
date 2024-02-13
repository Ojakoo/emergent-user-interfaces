import sys

sys.path.insert(1, sys.path[0] + "/src")
sys.path.insert(1, sys.path[0] + "/gui")

from controller import Controller

def main():
    # Init controller
    controller = Controller()

    if controller.arduino == None:
        print("Exit, no device found")
    else:
        controller.command_loop()


if __name__ == "__main__":
    main()
