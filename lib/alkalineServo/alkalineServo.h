#ifndef ALKALINE_SERVO_H
#define ALKALINE_SERVO_H

#include <Arduino.h>
#include <Servo.h>

class alkalineServo {
public:
  alkalineServo(uint8_t PIN);
  void begin();
  void update(unsigned long ms);
  void open();
  void close();


private:
  bool active;
  bool lastState;
  Servo servo;
  uint8_t _PIN;

  // Jittering issue. Let it jitter when open. :)
  const int OPEN = 0;
  const int CLOSED = 180;

};

#endif
