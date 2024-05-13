#ifndef WATERVALVE_h
#define WATERVALVE_h

#include <Arduino.h>

class  waterValve {
public:
  waterValve(uint8_t PIN);
  void begin();
  void update(unsigned long ms);
  void open();
  void close();


private:
  bool active;
  uint8_t _PIN;

  const bool ACTIVATED = LOW;
  const bool DEACTIVATED = HIGH;

};

#endif
