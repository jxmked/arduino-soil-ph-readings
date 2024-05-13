#ifndef phSensor_h
#define phSensor_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class phSensor {
public:
  phSensor(uint8_t MRX, uint8_t MTX, uint8_t MA, uint8_t MB, int BAUD_RATE);

  void begin();
  bool isAvailable();

  void update(unsigned long ms);

  float read();


private:
  const byte TX_DATA[8] = { 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A };

  byte values[11];
  SoftwareSerial sSerial;

  uint8_t MRX;
  uint8_t MTX;
  uint8_t MA;
  uint8_t MB;
  int BAUD_RATE;

  void BUSMode(bool isHigh);

};


#endif