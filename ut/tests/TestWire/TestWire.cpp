#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <Wire.h>
#include "GlobalMockTemplate.h"

GLOBAL_MOCK_DEFINISION_H(
  Serial,
  {
    MOCK_METHOD0(foo, int() );
    MOCK_METHOD1(foo, int(int) );
    MOCK_METHOD2(foo, int(int, int) );
    MOCK_METHOD0(boo, int() );
    MOCK_METHOD1(boo, int(int) );
    MOCK_METHOD2(boo, int(int, int) );
  },
  {
    MOCK_GLOBAL_METHOD(foo, int)
    MOCK_GLOBAL_METHOD(boo, int)
  }
);

using ::testing::Return;
using ::testing::_;


TEST(WireTest, ShouldBegin)
{
  Wire_LocalMock WireLocal;

  EXPECT_CALL(WireLocal, begin(9600));

  Wire.begin(9600);
}


