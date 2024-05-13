#ifndef AUTO_INTERVAL_h
#define AUTO_INTERVAL_h

#include <Arduino.h>


class AutoInterval {
public:
  AutoInterval();
  void begin();
  void update(unsigned long ms);

  int rotation;
  bool isOpen;

  bool isServoOn;
  bool isValveOn;






};




#endif