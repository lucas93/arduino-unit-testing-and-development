#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <blinkLib.h>

TEST(BlinkLibTests, ShouldSetupCorrectly)
{
  ArduinoMockInstanceGuard Arduino{};
  auto pin = 13;
  EXPECT_CALL(*Arduino, pinMode(pin, OUTPUT));
  blink_setup(pin);
}

TEST(BlinkLibTests, WhenSetupCorrectly_ShouldBlinkCorrectly)
{
  ArduinoMockInstanceGuard Arduino{};
  auto pin = 13;
  auto duration = 500ul;
  EXPECT_CALL(*Arduino, pinMode(pin, OUTPUT));
  EXPECT_CALL(*Arduino, digitalWrite(pin, HIGH));
  EXPECT_CALL(*Arduino, delay(duration)).Times(2);
  EXPECT_CALL(*Arduino, digitalWrite(pin, LOW));

  blink_setup(pin);
  blink(duration);
}


