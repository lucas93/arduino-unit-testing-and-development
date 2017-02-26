#include "Arduino.h"
#include <memory>

ArduinoMockImplementation* arduinoMock = nullptr;

ArduinoMockInstancePointer::ArduinoMockInstancePointer()
{
  arduinoMock = &arduino;
}

ArduinoMockImplementation &ArduinoMockInstancePointer::operator*()
{
  return arduino;
}

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(RETURN_TYPE, FUNCTION_NAME)\
RETURN_TYPE FUNCTION_NAME() \
{\
  return arduinoMock->FUNCTION_NAME();\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1) \
{\
  return arduinoMock->FUNCTION_NAME(ARG1);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2) \
{\
  return arduinoMock->FUNCTION_NAME(ARG1, ARG2);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3) \
{\
  return arduinoMock->FUNCTION_NAME(ARG1, ARG2, ARG3);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_4(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4) \
{\
  return arduinoMock->FUNCTION_NAME(ARG1, ARG2, ARG3, ARG4);\
}\

IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(void, pinMode, uint8_t, a, uint8_t, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(void, digitalWrite, uint8_t, a, uint8_t, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(int, digitalRead, uint8_t, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(int, analogRead, uint8_t, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(void, analogReference, uint8_t, mode)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(void, analogWrite, uint8_t, a, int, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(unsigned long, millis)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(unsigned long, micros)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(void, delay, unsigned long, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(void, delay, unsigned int, us)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(unsigned long, pulseIn, uint8_t, pin, uint8_t, state, unsigned long, timeout)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_4(void, shiftOut, uint8_t, dataPin, uint8_t, clockPin, uint8_t, bitOrder, uint8_t, val)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(uint8_t, shiftIn, uint8_t, dataPin, uint8_t, clockPin, uint8_t, bitOrder)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(void, detachInterrupt, uint8_t, pin)


void attachInterrupt(uint8_t, void (*)(void), int mode) { //TODO mock implementation
  UNUSED(mode);
}

