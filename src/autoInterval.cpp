#include "autoInterval.h"
#include <Arduino.h>

#include "TimeInterval.h"
#include "DEFINITION.h"
#include "alkalineServo.h"

TimeInterval aa(999, 0, true); // Servo

AutoInterval::AutoInterval() :
  isServoOn(false),
  isValveOn(false),
  rotation(0),
  isOpen(false) {

}

void AutoInterval::begin() {

  aa.reset();
}


void AutoInterval::update(unsigned long ms) {
  if (rotation == alkalineServo::CLOSED && aa.marked()) {
    
  }
}


