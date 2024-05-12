#ifndef ALKALINE_SERVO_H
#define ALKALINE_SERVO_H

#include <Arduino.h>
#include <Servo.h>

#include "PIN_MAP.h"

class alkalineServo {
public:
  alkalineServo();
  void begin();
  void update(unsigned long ms);
  void open();
  void close();


private:
  bool active;
  Servo servo;

  const int OPEN = 180;
  const int CLOSED = 0;

};

#endif
