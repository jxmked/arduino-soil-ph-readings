#ifndef PIN_MAP_h
#define PIN_MAP_h

#include "Arduino.h"

struct PIN_MAP_T {

  uint8_t MODBUS_RX = 2;
  uint8_t MODBUS_TX = 3;
  uint8_t MODBUS_A = 7;
  uint8_t MODBUS_B = 8;

  uint8_t SERVO_PIN = 11;
  uint8_t SOLENOID_VALVE_PIN = 12; // Target Relay
};

const PIN_MAP_T PIN_MAP;

#endif
