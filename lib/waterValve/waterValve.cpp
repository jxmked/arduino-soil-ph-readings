#include "waterValve.h"
#include <Arduino.h>
#include "PIN_MAP.h"

waterValve::waterValve():
active(false) {

}

void waterValve::begin() {
  pinMode(SOLENOID_VALVE_PIN, OUTPUT);
  digitalWrite(SOLENOID_VALVE_PIN, DEACTIVATED);
}

void waterValve::update(unsigned long ms) {
    digitalWrite(SOLENOID_VALVE_PIN, active ? ACTIVATED : DEACTIVATED);
}

void waterValve::close() {
  active = DEACTIVATED;
}

void waterValve::open() {
  active = ACTIVATED;
}