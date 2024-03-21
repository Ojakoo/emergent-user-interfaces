#include "Mouse.h"
#include <Adafruit_LSM6DS33.h>

Adafruit_LSM6DS33 lsm6ds;

enum STATE {
  NONE,
  LEFT,
  RIGHT,
};

int pressedButton;

sensors_event_t accel, gyro, magn;

static float zero_accel_pitch = 0.0;
static float zero_accel_roll = 0.0;

float mouse_modifier = 1.3;

void setup(void) {
  if (!lsm6ds.begin_I2C()){
    delay(100);
  }

  // setZero();

  Mouse.begin();
}

// Calculates a zero position for the and set the zero position for the device 
void setZero(void) {
  lsm6ds.getEvent(&accel, &gyro, &magn);

  zero_accel_pitch = accel.acceleration.pitch;
  zero_accel_roll = accel.acceleration.roll; 
}

void loop(void) {
  lsm6ds.getEvent(&accel, &gyro, &magn);  

  if (
    accel.acceleration.pitch < 1.5 &&
    accel.acceleration.roll < 1.5 &&
    accel.acceleration.pitch > -1.5 &&
    accel.acceleration.roll > -1.5
  ) {
    // if (pressedButton == NONE) {
    //   if (gyro.gyro.z > 0.4) {
    //     Mouse.press(MOUSE_LEFT);
    //     pressedButton = LEFT;
    //     delay(400);
    //   }
      
    //   if (gyro.gyro.z < -0.4) {z`
    //     Mouse.press(MOUSE_RIGHT);
    //     pressedButton = RIGHT;
    //     delay(400);
    //   }
    // } else {
    //   if (
    //     pressedButton == LEFT && 
    //     gyro.gyro.z < -0.4
    //   ) {
    //     Mouse.release(MOUSE_LEFT);
    //     pressedButton = NONE;
    //     delay(1000);
    //   }
      
    //   if (
    //     pressedButton == RIGHT &&
    //     gyro.gyro.z > 0.4
    //   ) {
    //     Mouse.release(MOUSE_RIGHT);
    //     pressedButton = NONE;
    //     delay(1000);
    //   }
    // }

    if (gyro.gyro.z > 1) {
      Mouse.click(MOUSE_LEFT);
      delay(1000);
    } else if (gyro.gyro.z < -1) {
      Mouse.click(MOUSE_RIGHT);
      delay(1000);
    }

  } else {
    Mouse.move(
      accel.acceleration.roll * mouse_modifier,
      accel.acceleration.pitch * mouse_modifier,
      0
    );
  }

  delay(10);
}