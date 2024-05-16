#ifndef PIN_MAP_h
#define PIN_MAP_h

#include "Arduino.h"

struct PIN_MAP_T {

  uint8_t MODBUS_RX = 12;
  uint8_t MODBUS_TX = 9;
  uint8_t MODBUS_A = 10;
  uint8_t MODBUS_B = 11;

  uint8_t SERVO_PIN = 6;
  uint8_t SOLENOID_VALVE_PIN = 7; // Target Relay
};

const PIN_MAP_T PIN_MAP;

#endif
