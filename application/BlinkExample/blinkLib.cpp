#include <Arduino.h>

#include <blinkLib.h>


void blink_setup(uint8_t pin) {
  pinMode(pin, OUTPUT);
}

void koo1(int a)
{

}
void koo2(long a)
{

}
void koo3(unsigned long a)
{
  koo1(a);
}

void koo4(long a)
{
  koo3(a);
}

void blink(unsigned long duration, uint8_t pin) {
  digitalWrite(pin, HIGH);   // set the LED on
  delay(duration);           // wait for a second
  digitalWrite(pin, LOW);    // set the LED off
  delay(duration);           // wait for a second
}



