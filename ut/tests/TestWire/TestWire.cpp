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


#define REAL_MOCK_IMPLEMENTATION(MockName)\
struct MockName##_Implementation\

REAL_MOCK_IMPLEMENTATION(Serial)
{
  MOCK_METHOD0(foo, int() );
  MOCK_METHOD1(foo, int(int) );
  MOCK_METHOD2(foo, int(int, int) );
  MOCK_METHOD0(boo, int() );
  MOCK_METHOD1(boo, int(int) );
  MOCK_METHOD2(boo, int(int, int) );
};


#define GLOBAL_MOCK_IMPLEMENTATION(MockName)\
struct MockName##_PointerClass\
{\
  MockName##_Implementation* mockPointer = nullptr;\
};\
struct MockName##_GlobalObjectMethodImplementation : public MockName##_PointerClass\

GLOBAL_MOCK_IMPLEMENTATION(Serial)
{
  MOCK_GLOBAL_METHOD(int, foo)
  MOCK_GLOBAL_METHOD(int, boo)
};


//#define GLOBAL_MOCK_DEFINISIONS(MockName)
class MockGlobalObject : public Serial_GlobalObjectMethodImplementation
{
  MockGlobalObject& operator=(const MockGlobalObject& other) = delete;
  MockGlobalObject(const MockGlobalObject& other) = delete;

public:
  MockGlobalObject(){}


  static MockGlobalObject& getGlobalInstanceReference()
  {
    static MockGlobalObject globalInstance;
    return globalInstance;
  }

};


class MockLocalObject : public Serial_Implementation
{

  MockGlobalObject& globalObj = MockGlobalObject::getGlobalInstanceReference();

public:
  MockLocalObject()
  {
    EXPECT_EQ(nullptr, globalObj.mockPointer)
      << "Are you trying to instantiate multiple local mock objects in one scope?";
    globalObj.mockPointer = this;
  }

  ~MockLocalObject()
  {
    EXPECT_NE(nullptr, globalObj.mockPointer);
    globalObj.mockPointer = nullptr;
  }
};

using ::testing::Return;
using ::testing::_;

auto& globalObj = MockGlobalObject::getGlobalInstanceReference();

TEST(SomeMock, FirstTest)
{
  MockLocalObject obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );
  EXPECT_CALL(obj, boo(3, 3)).WillOnce(Return(4) );

  EXPECT_EQ(1, globalObj.foo());
  EXPECT_EQ(2, globalObj.foo(2));
  EXPECT_EQ(3, globalObj.foo(3, 3));
  EXPECT_EQ(4, globalObj.boo(3, 3));
}
TEST(SomeMock, SecondTest)
{
  MockLocalObject obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );

  EXPECT_EQ(1, globalObj.foo());
  EXPECT_EQ(2, globalObj.foo(2));
  EXPECT_EQ(3, globalObj.foo(3, 3));
}


