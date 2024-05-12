#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


#define RE 8
#define DE 7

const byte ph[] = { 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A };
//const byte ph[] = { 0x01, 0x06, 0x07, 0xD1, 0x00, 0x02, 0x59, 0x46 };
byte values[11];
SoftwareSerial mod(2, 3);

LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  Serial.begin(38400);

  while (!Serial);

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  mod.begin(9600);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();


  delay(3000);
}

void loop() {

  // if (mod.isListening()) {
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Listening");
  //   //return;
  // }


  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);

  lcd.clear();
  if (mod.write(ph, sizeof(ph)) == 8) {

    Serial.println(mod.available());


    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    lcd.setCursor(0, 1);
    for (byte i = 0; i < 11; i++) {
      values[i] = mod.read();
      char un = ((values[i] & 0xF0) >> 4) + 'A';
      char ln = (values[i] & 0x0F) + 'O';

      lcd.print(un);
      lcd.print(ln);

    }

  }
  float soil_ph = float(values[4]) / 10;
  // Serial.print("Soil Ph: ");
  // Serial.println(soil_ph, 1);
  // lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(soil_ph);

  delay(300);
}