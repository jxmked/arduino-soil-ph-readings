#ifndef phSensor_h
#define phSensor_h


#include <Arduino.h>
#include <SoftwareSerial.h>
// #include "PIN_MAP.h"

class phSensor {
public:
  phSensor();

  void begin();
  bool isAvailable();

  void update(unsigned long ms);

  float read();
  bool started;


private:
  const byte TX_DATA[8] = { 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A };

  byte values[11];
  SoftwareSerial sSerial;

  void BUSMode(bool isHigh);

};


#endif