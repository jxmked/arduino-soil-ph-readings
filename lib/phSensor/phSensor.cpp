#include "phSensor.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

#include <Wire.h>

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

  Serial.begin(BAUD_RATE);
  sSerial.begin(BAUD_RATE);

  pinMode(MA, OUTPUT);
  pinMode(MB, OUTPUT);


  BUSMode(LOW);

}

bool phSensor::isAvailable() {
  // No Data To Read
  return sSerial.available() > 0;
}

void phSensor::update(unsigned long ms) {
  BUSMode(HIGH);

  delay(10);

  if (sSerial.write(TX_DATA, sizeof(TX_DATA)) >= sizeof(TX_DATA)) {

    BUSMode(LOW);
    delay(10);


      for (byte i = 0; i < 11; i++) {
        values[i] = sSerial.read();
        Serial.print(values[i], HEX);

      }

      Serial.println();
  }
}

float phSensor::read() {
  return float(values[4]) / 10;
}

void phSensor::BUSMode(uint8_t v) {
    digitalWrite(MA, v);
    digitalWrite(MB, v);
}
