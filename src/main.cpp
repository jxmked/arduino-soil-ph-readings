#include <Arduino.h>
#include <Servo.h>


Servo serv;

void setup() {
  serv.attach(3);

}

void loop() {
  // put your main code here, to run repeatedly:
  serv.write(0);
  delay(1000);
  serv.write(45);
  delay(1000);
  serv.write(90);
  delay(1000);
  serv.write(135);
  delay(1000);
  serv.write(180);
  delay(1000);

}
