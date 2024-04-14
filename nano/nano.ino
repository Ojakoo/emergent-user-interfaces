#include "Arduino.h"
#include "Arduino_LSM9DS1.h"

float x, y, z;

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  IMU.begin();
  Serial.println("X, Y, Z");
}

void loop()
{
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print(',');
    Serial.print(y);
    Serial.print(',');
    Serial.print(z);
    Serial.println();

    delay(100);
  }
}