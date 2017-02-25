/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Example uses a static library to show off generate_arduino_library().
 
  This example code is in the public domain.
 */
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include "blink_lib.h"
#include <BaseClass.h>

class Derived : public TeaBreak
{
protected:
  int makeCoffee(bool milk, double sugars) override
  {
    return milk ? sugars : -sugars;
  }

  int makeHerbalTea()
  {
    return 100;
  }
};



void setup() {                
    blink_setup(); // Setup for blinking
    Serial.begin(9600);
}

void loop() {
    blink(1000); // Blink for a second
}
