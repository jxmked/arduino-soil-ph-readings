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
  const byte TX_DATA[8] = { 0xff, 0x03, 0x00, 0x00, 0x00, 0x04, 0x44, 0x09}; 

  // const byte TX_DATA[8] = { 0x01, 0x03, 0x00, 0x1e, 0x00, 0x03, 0x65, 0xcd };

  // const byte TX_DATA[8] = { 0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c }; // Nitro

  // const byte TX_DATA[8] = { 0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc }; // Phosporus

  // const byte TX_DATA[8] = { 0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0 }; // Potassium


  byte values[11];
  SoftwareSerial sSerial;

  uint8_t MRX;
  uint8_t MTX;
  uint8_t MA;
  uint8_t MB;
  int BAUD_RATE;

  void BUSMode(uint8_t v);

};


#endif