#include "waterValve.h"
#include <Arduino.h>

waterValve::waterValve(uint8_t PIN) :
  active(false),
  _PIN(PIN) {

}

void waterValve::begin() {
  pinMode(_PIN, OUTPUT);
  digitalWrite(_PIN, DEACTIVATED);
}

void waterValve::update(unsigned long ms) {
  digitalWrite(_PIN, active ? ACTIVATED : DEACTIVATED);
}

void waterValve::close() {
  active = DEACTIVATED;
}

void waterValve::open() {
  active = ACTIVATED;
}
