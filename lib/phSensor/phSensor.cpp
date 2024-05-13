#include "phSensor.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

phSensor::phSensor(uint8_t MRX, uint8_t MTX, uint8_t MA, uint8_t MB, int BAUD_RATE) :
  values(),
  sSerial(MRX, MTX),
  MRX(MRX),
  MTX(MTX),
  MA(MA),
  MB(MB),
  BAUD_RATE(BAUD_RATE) {

}

void phSensor::begin() {
  pinMode(MA, OUTPUT);
  pinMode(MB, OUTPUT);

  sSerial.begin(BAUD_RATE);

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
    digitalWrite(MA, HIGH);
    digitalWrite(MB, HIGH);
  } else {
    digitalWrite(MA, LOW);
    digitalWrite(MB, LOW);
  }
}
