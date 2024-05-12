#include "phSensor.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

#include "PIN_MAP.h"
#include "DEFINITION.h"

phSensor::phSensor() :
  values(),
  sSerial(MODBUS_RX, MODBUS_TX) {

}

void phSensor::begin() {
  pinMode(MODBUS_A, OUTPUT);
  pinMode(MODBUS_B, OUTPUT);

  sSerial.begin(MODBUS_BAUD_RATE);

  BUSMode(true);

}

bool phSensor::isAvailable() {
  // No Data To Read
  return sSerial.available() > 0;
}

void phSensor::update(unsigned long ms) {
  BUSMode(true);

  if (sSerial.write(TX_DATA, sizeof(TX_DATA)) == 8) {
    BUSMode(false);

    for (byte i = 0; i < 11; i++) {
      values[i] = sSerial.read();
    }
  }
}

float phSensor::read() {
  return float(values[4]) / 10;
}

void phSensor::BUSMode(bool isHigh) {
  if (isHigh) {
    digitalWrite(MODBUS_A, HIGH);
    digitalWrite(MODBUS_B, HIGH);
  } else {
    digitalWrite(MODBUS_A, LOW);
    digitalWrite(MODBUS_B, LOW);
  }
}
