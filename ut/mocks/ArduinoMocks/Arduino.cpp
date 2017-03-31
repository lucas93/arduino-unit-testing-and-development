#include "Arduino.h"
#include <gtest/gtest.h>
#include <memory>

Arduino_MockInstanceGuard* arduinoInstancePointer = nullptr;


Arduino_MockInstanceGuard::Arduino_MockInstanceGuard()
{
  EXPECT_EQ(nullptr, arduinoInstancePointer)
      << "Are you trying to instantiate multiple ArduinoMockWrappers in the same scope?";
  arduinoInstancePointer = this;
}

Arduino_MockInstanceGuard::~Arduino_MockInstanceGuard()
{
  arduinoInstancePointer = nullptr;
}


void assertArduinoMockWrapperInstanceWasCreated()
{
  ASSERT_NE(nullptr, arduinoInstancePointer)
      << "Are you trying to invoke Arduino functions without instatiating an ArduinoMockWrapper first?";
}

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(RETURN_TYPE, FUNCTION_NAME)\
RETURN_TYPE FUNCTION_NAME() \
{\
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->FUNCTION_NAME();\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1) \
{\
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->FUNCTION_NAME(ARG1);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2) \
{\
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->FUNCTION_NAME(ARG1, ARG2);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3) \
{\
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->FUNCTION_NAME(ARG1, ARG2, ARG3);\
}\

#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_4(RETURN_TYPE, FUNCTION_NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4)\
RETURN_TYPE FUNCTION_NAME(TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4) \
{\
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->FUNCTION_NAME(ARG1, ARG2, ARG3, ARG4);\
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
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{ //function pointer needs a unique implementation
  assertArduinoMockWrapperInstanceWasCreated();\
  return arduinoInstancePointer->attachInterrupt(interruptNum, userFunc, mode);
}

//#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(FUNCTION_NAME)\
//template< typename... Args>\
//auto FUNCTION_NAME(Args... args) -> decltype(arduinoInstancePointer->FUNCTION_NAME(args ...))\
//{\
//  EXPECT_NE(nullptr, arduinoInstancePointer);\
//  return arduinoInstancePointer->FUNCTION_NAME(args...);\
//}


//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(digitalWrite)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(attachInterrupt)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(pinMode)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(digitalRead)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogRead)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogReference)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogWrite)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(millis)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(micros)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(void, delay)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(pulseIn)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(shiftOut)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(shiftIn)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(detachInterrupt)
