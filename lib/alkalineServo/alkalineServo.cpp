#include "alkalineServo.h"
#include <Arduino.h>
#include <Servo.h>

alkalineServo::alkalineServo(uint8_t PIN) :
  active(false),
  servo(),
  _PIN(PIN) { }


void alkalineServo::begin() {
  servo.attach(_PIN);
}

void alkalineServo::update(unsigned long ms) {
  servo.write(active ? OPEN : CLOSED);
}

void alkalineServo::open() {
  active = OPEN;
}

void alkalineServo::close() {
  active = CLOSED;
}

