#ifndef WATERVALVE_h
#define WATERVALVE_h

#include <Arduino.h>

class  waterValve {
public:
  waterValve();
  void begin();
  void update(unsigned long ms);
  void open();
  void close();


private:
  bool active;

  const bool ACTIVATED = LOW;
  const bool DEACTIVATED = HIGH;

};

#endif
