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
  void setMinMaxServoRot(int m, int x);
  int rotation;



private:
  bool active;
  Servo servo;
  uint8_t _PIN;
  int OPEN;
  int CLOSED;



};

#endif
