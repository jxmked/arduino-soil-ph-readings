#include "alkalineServo.h"

#include <Arduino.h>
#include <Servo.h>
#include "PIN_MAP.h"





alkalineServo::alkalineServo() :
  active(false),
  servo() { }


void alkalineServo::begin() {
  servo.attach(SERVO_PIN);

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

