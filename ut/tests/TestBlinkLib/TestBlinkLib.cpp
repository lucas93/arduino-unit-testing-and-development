#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <blinkLib.h>

TEST(BlinkTests, ShouldBlinkSetupCorrectly)
{
  ArduinoMock* arduinoMock = arduinoMockInstance();
  auto pin = 13;
  EXPECT_CALL(*arduinoMock, pinMode(pin, OUTPUT));
  blink_setup(pin);
}
