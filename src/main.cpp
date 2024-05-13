#include <Arduino.h>
#include <Wire.h>
#include "PIN_MAP.h"
#include <LiquidCrystal_I2C.h>
#include "phSensor.h"
#include "alkalineServo.h"
#include "waterValve.h"
#include "DEFINITION.h"
#include "TimeInterval.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
TimeInterval lcd_hz(200, 0, true);

phSensor phs(PIN_MAP.MODBUS_RX, PIN_MAP.MODBUS_TX, PIN_MAP.MODBUS_A, PIN_MAP.MODBUS_B, MODBUS_BAUD_RATE);
alkalineServo als(PIN_MAP.SERVO_PIN);
waterValve wav(PIN_MAP.SOLENOID_VALVE_PIN);

TimeInterval phInterval(3000, 0, true);

void setup() {

  lcd.begin(16, 2);
  lcd.backlight();


  phs.begin();
  als.begin();
  wav.begin();



  delay(3000);

}

void loop() {
  const auto ms = millis();

  // Update soil pH sensor every given sec
  // if ((!phs.isAvailable()) || phInterval.marked())
  if (phInterval.marked())
    phs.update(ms);

  wav.update(ms);
  als.update(ms);

  // if (!phs.isAvailable()) {
  //   // pH Sensor not available

  //   wav.close();
  //   als.close();

  //   if (lcd_hz.marked()) {
  //     lcd.clear();
  //     lcd.setCursor(3, 0);
  //     lcd.print("pH Sensor");

  //     lcd.setCursor(1, 1);
  //     lcd.print("Not Available");
  //   }

  //   return;
  // }

  // Refresh Screen Every 200 ms
  if (!lcd_hz.marked()) {
    return;
  }

  const float phVal = phs.read();
  // const float potVal = float(analogRead(A0)) / 1023;
  // const float phVal = (2 * potVal) + 5;

  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("Soil pH:");
  lcd.print(phVal);

  if (phVal >= ALKALINE_THRESHOLD) {
    lcd.setCursor(3, 1);
    lcd.print("< ALKALINE");
    wav.open();
    als.close();
  } else if (phVal <= ACIDIC_THRESHOLD) {
    lcd.setCursor(3, 1);
    lcd.print("< ACIDITY");
    wav.close();
    als.open();
  } else {
    lcd.setCursor(5, 1);
    lcd.print("Normal");
    wav.close();
    als.close();
  }
}