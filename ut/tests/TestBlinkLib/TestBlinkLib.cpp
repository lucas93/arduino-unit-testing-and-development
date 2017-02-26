#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

#include <Arduino.h>
#include <blinkLib.h>

TEST(BlinkTests, ShouldBlinkSetupCorrectly)
{
  ArduinoMockInstancePointer arduinoMock{};
  auto pin = 13;
  EXPECT_CALL(*arduinoMock, pinMode(pin, OUTPUT));
  blink_setup(pin);
}

TEST(BlinkTests, WhenSetupCorrectly_ShouldBlinkCorrectly)
{
  ArduinoMockInstancePointer arduinoMock{};
  auto pin = 13;
  EXPECT_CALL(*arduinoMock, pinMode(pin, OUTPUT));
  blink_setup(pin);

//  EXPECT_CALL(*arduinoMock, )
}
