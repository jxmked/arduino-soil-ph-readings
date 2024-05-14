#include "alkalineServo.h"
#include <Arduino.h>
#include <Servo.h>

alkalineServo::alkalineServo(uint8_t PIN) :
  rotation(0),
  active(false),
  servo(),
  _PIN(PIN),
  OPEN(0),
  CLOSED(0) { }


void alkalineServo::begin() {
  servo.attach(_PIN);
  servo.write(CLOSED);
}

void alkalineServo::update(unsigned long ms) {
  servo.write(active ? OPEN : CLOSED);
  rotation = servo.read();
}


void alkalineServo::open() {
  active = true;
}

void alkalineServo::close() {
  active = false;
}

void alkalineServo::setMinMaxServoRot(int m, int x) {
  CLOSED = m;
  OPEN = x;
}

