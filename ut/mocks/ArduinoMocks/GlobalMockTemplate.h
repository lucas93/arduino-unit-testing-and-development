#ifndef GLOBAL_MOCK_TEMPLATE_H
#define GLOBAL_MOCK_TEMPLATE_H

#define MOCK_GLOBAL_METHOD(FUNCTION_NAME, RETURN_TYPE) \
template< typename... Args>\
RETURN_TYPE FUNCTION_NAME (Args... args)\
{\
  EXPECT_NE(nullptr, mockPointer)\
    << "Are you trying to use a global mock without creating a local mock instance?";\
  return mockPointer->FUNCTION_NAME(args...);\
}\



#define GLOBAL_MOCK_DEFINISION_H(MockName, MOCK_IMPL, MOCK_GLOBAL_IMPL)\
struct MockName##_Implementation\
\
  MOCK_IMPL\
;  \
struct MockName##_PointerClass\
{\
  MockName##_Implementation* mockPointer = nullptr;\
};\
struct MockName##_GlobalObjectMethodImplementation : public MockName##_PointerClass\
\
  MOCK_GLOBAL_IMPL\
;\
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
class MockName##_LocalMock : public MockName##_Implementation\
{\
  MockName##_GlobalObject& globalObj = MockName##_GlobalObject::getGlobalInstanceReference();\
\
public:\
  MockName##_LocalMock()\
  {\
    EXPECT_EQ(nullptr, globalObj.mockPointer)\
      << "Are you trying to instantiate multiple local mock objects in one scope?";\
    globalObj.mockPointer = this;\
  }\
\
  ~MockName##_LocalMock()\
  {\
    EXPECT_NE(nullptr, globalObj.mockPointer);\
    globalObj.mockPointer = nullptr;\
  }\
};\
extern MockName##_GlobalObject& MockName;\
//auto& MockName = MockName##_GlobalObject::getGlobalInstanceReference()\//

#define GLOBAL_MOCK_DEFINISION_CPP(MockName)\
  MockName##_GlobalObject& MockName = MockName##_GlobalObject::getGlobalInstanceReference()\

#endif // GLOBAL_MOCK_TEMPLATE_H
