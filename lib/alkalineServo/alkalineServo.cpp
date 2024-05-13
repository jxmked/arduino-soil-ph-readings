#include "alkalineServo.h"
#include <Arduino.h>
#include <Servo.h>

alkalineServo::alkalineServo(uint8_t PIN) :
  active(false),
  lastState(false),
  servo(),
  _PIN(PIN) { }


void alkalineServo::begin() {
  servo.attach(_PIN);
  servo.write(CLOSED);
}

void alkalineServo::update(unsigned long ms) {
  // if(active == lastState) return;

  servo.write(active ? OPEN : CLOSED);

  lastState = active;
}

void alkalineServo::open() {
  active = true;
}

void alkalineServo::close() {
  active = false;
}

