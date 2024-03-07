#include "Mouse.h"
#include <Adafruit_LSM6DS33.h>
Adafruit_LSM6DS33 lsm6ds;

void setup(void) {
  if (!lsm6ds.begin_I2C()){
    delay(100);
  }

  Mouse.begin();
}

enum STATE {
  NONE,
  LEFT,
  RIGHT,
};

int pressedButton;

void loop(void) {
  sensors_event_t accel, gyro, magn;

  lsm6ds.getEvent(&accel, &gyro, &magn);

  if (
    accel.acceleration.x < 0.6 && 
    accel.acceleration.y < 0.6 &&
    accel.acceleration.x > -0.6 &&
    accel.acceleration.y > -0.6 
  ) {
    if (pressedButton == NONE) {
      if (gyro.gyro.z > 0.4) {
        Mouse.press(MOUSE_LEFT);
        pressedButton = LEFT;
        delay(400);
      }
      
      if (gyro.gyro.z < -0.4) {
        Mouse.press(MOUSE_RIGHT);
        pressedButton = RIGHT;
        delay(400);
      }
    } else {
      if (
        pressedButton == LEFT && 
        gyro.gyro.z < -0.4
      ) {
        Mouse.release(MOUSE_LEFT);
        pressedButton = NONE;
        delay(1000);
      }
      
      if (
        pressedButton == RIGHT &&
        gyro.gyro.z > 0.4
      ) {
        Mouse.release(MOUSE_RIGHT);
        pressedButton = NONE;
        delay(1000);
      }
    }
  } else {
    Mouse.move(accel.acceleration.x, accel.acceleration.y, 0);
  }

  delay(10);
}