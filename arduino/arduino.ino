#include <Arduino_LSM9DS1.h>

float x, y, z;
int degreesX = 0;
int degreesY = 0;

enum STATE {
  IDLE,
  START,
};

int commandByte;

int state = IDLE;

void setup(void) {
  // set led pins as outputs
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LED_PWR, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(14400, SERIAL_8N1);

  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDR, HIGH);

  while (!Serial);

  digitalWrite(LEDR, LOW);

  if (!IMU.begin()) {
    digitalWrite(LEDG, LOW);
    while (1);
  }

  digitalWrite(LEDG, HIGH);
}

void read_acceleration() {
  if (!IMU.accelerationAvailable()) {
    return;
  }
  
  IMU.readAcceleration(x, y, z);
  
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.print(z);
  Serial.println();
}

void loop(void) {
  if ( Serial.available() > 0 ) {
    commandByte = Serial.read();
  }

  switch (commandByte) {
  case IDLE:
    state = IDLE;
    break;
  case START:
    state = START;
    break;
  }

  switch(state) {
    case IDLE:
      delay(500);
      digitalWrite(LEDR, LOW);
      delay(500);
      digitalWrite(LEDR, HIGH);
      break;
    case START:
      read_acceleration();
      break;
  }
  
  read_acceleration();
  delay(100);
}