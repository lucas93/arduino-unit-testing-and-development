#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <Wire.h>
#include <functional>

#define MOCK_GLOBAL_METHOD(RETURN_TYPE, FUNCTION_NAME) \
template< typename... Args>\
RETURN_TYPE FUNCTION_NAME (Args... args)\
{\
  return mockPointer->FUNCTION_NAME(args...);\
}\



#define GLOBAL_MOCK_DEFINISIONS(MockName)\
struct MockName##_Implementation\
{\
  MOCK_METHOD0(foo, int() );\
  MOCK_METHOD1(foo, int(int) );\
  MOCK_METHOD2(foo, int(int, int) );\
  MOCK_METHOD0(boo, int() );\
  MOCK_METHOD1(boo, int(int) );\
  MOCK_METHOD2(boo, int(int, int) );\
};  \
struct MockName##_PointerClass\
{\
  MockName##_Implementation* mockPointer = nullptr;\
};\
struct MockName##_GlobalObjectMethodImplementation : public MockName##_PointerClass\
{\
  MOCK_GLOBAL_METHOD(int, foo)\
  MOCK_GLOBAL_METHOD(int, boo)\
};\
class MockName##_GlobalObject : public MockName##_GlobalObjectMethodImplementation\
{\
  MockName##_GlobalObject& operator=(const MockName##_GlobalObject& other) = delete;\
  MockName##_GlobalObject(const MockName##_GlobalObject& other) = delete;\
\
public:\
  MockName##_GlobalObject(){}\
\
  static MockName##_GlobalObject& getGlobalInstanceReference()\
  {\
    static MockName##_GlobalObject globalInstance;\
    return globalInstance;\
  }\
};\
class MockName##_LocalObject : public MockName##_Implementation\
{\
  MockName##_GlobalObject& globalObj = MockName##_GlobalObject::getGlobalInstanceReference();\
\
public:\
  MockName##_LocalObject()\
  {\
    EXPECT_EQ(nullptr, globalObj.mockPointer)\
      << "Are you trying to instantiate multiple local mock objects in one scope?";\
    globalObj.mockPointer = this;\
  }\
\
  ~MockName##_LocalObject()\
  {\
    EXPECT_NE(nullptr, globalObj.mockPointer);\
    globalObj.mockPointer = nullptr;\
  }\
};\
auto& MockName = MockName##_GlobalObject::getGlobalInstanceReference()\

GLOBAL_MOCK_DEFINISIONS(Serial);

using ::testing::Return;
using ::testing::_;

TEST(SomeMock, FirstTest)
{
  Serial_LocalObject obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );
  EXPECT_CALL(obj, boo(3, 3)).WillOnce(Return(4) );

  EXPECT_EQ(1, Serial.foo());
  EXPECT_EQ(2, Serial.foo(2));
  EXPECT_EQ(3, Serial.foo(3, 3));
  EXPECT_EQ(4, Serial.boo(3, 3));
}

TEST(SomeMock, SecondTest)
{
  Serial_LocalObject obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );

  EXPECT_EQ(1, Serial.foo());
  EXPECT_EQ(2, Serial.foo(2));
  EXPECT_EQ(3, Serial.foo(3, 3));
}


