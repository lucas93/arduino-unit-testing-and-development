#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <Wire.h>
#include <functional>

#define IMPLEMENT_FORWARDING_CALL_TO_MOCK(RETURN_TYPE, FUNCTION_NAME) \
template< typename... Args>\
RETURN_TYPE FUNCTION_NAME (Args... args)\
{\
  return mockPointer->FUNCTION_NAME(args...);\
}\


class SampleMockImplementation
{
public:
  MOCK_METHOD0(foo, int() );
  MOCK_METHOD1(foo, int(int) );
  MOCK_METHOD2(foo, int(int, int) );
};


template< typename MockImplementationTypename>
class MockGlobalObjectTemplate
{
  using ThisClassType = MockGlobalObjectTemplate<MockImplementationTypename>;
  MockGlobalObjectTemplate& operator=(const MockGlobalObjectTemplate& other) = delete;
  MockGlobalObjectTemplate(const MockGlobalObjectTemplate& other) = delete;

public:
  MockGlobalObjectTemplate(){}
  MockImplementationTypename* mockPointer = nullptr;

  static ThisClassType& getGlobalInstanceReference()
  {
    static MockGlobalObjectTemplate globalInstance;
    return globalInstance;
  }
  IMPLEMENT_FORWARDING_CALL_TO_MOCK(int, foo);
};


template<typename MockImplementationTypename,
         typename MockGlobalObject = MockGlobalObjectTemplate<MockImplementationTypename> >
class MockLocalObjectTemplate
{

  MockImplementationTypename mockImpl{};
  MockGlobalObject& globalObj = MockGlobalObject::getGlobalInstanceReference();

public:
  MockLocalObjectTemplate()
  {
    EXPECT_EQ(nullptr, globalObj.mockPointer)
      << "Are you trying to instantiate multiple local mock object in one scope?";
    globalObj.mockPointer = &mockImpl;
  }

  ~MockLocalObjectTemplate()
  {
    EXPECT_NE(nullptr, globalObj.mockPointer);
    globalObj.mockPointer = nullptr;
  }

  MockImplementationTypename& operator*()
  {
    return mockImpl;
  }
};

using MockGlobalObject = MockGlobalObjectTemplate<SampleMockImplementation>;
using MockLocalObject = MockLocalObjectTemplate<SampleMockImplementation>;


using ::testing::Return;
using ::testing::_;



auto& globalObj = MockGlobalObject::getGlobalInstanceReference();



TEST(SomeMock, FirstTest)
{
  MockLocalObject obj;

  EXPECT_CALL(*obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(*obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(*obj, foo(3, 3)).WillOnce(Return(3) );

  EXPECT_EQ(1, globalObj.foo());
  EXPECT_EQ(2, globalObj.foo(2));
  EXPECT_EQ(3, globalObj.foo(3, 3));
}
TEST(SomeMock, SecondTest)
{
  MockLocalObject obj;

  EXPECT_CALL(*obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(*obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(*obj, foo(3, 3)).WillOnce(Return(3) );

  EXPECT_EQ(1, globalObj.foo());
  EXPECT_EQ(2, globalObj.foo(2));
  EXPECT_EQ(3, globalObj.foo(3, 3));
}


