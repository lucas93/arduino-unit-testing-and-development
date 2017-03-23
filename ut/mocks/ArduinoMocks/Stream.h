#ifndef STREAM_H
#define STREAM_H

#include "Print.h"


#define STREAM_MOCK_METHODS()\
  MOCK_METHOD1(setTimeout, void(unsigned long));\
  MOCK_METHOD1(find, bool(char*));\
  MOCK_METHOD2(find, bool(char*, size_t));\
  MOCK_METHOD2(findUntil, bool(char*, char*));\
  MOCK_METHOD4(findUntil, bool(char*, size_t, char*, size_t));\
  MOCK_METHOD0(parseInt, long());\
  MOCK_METHOD0(parseFloat, float());\
  MOCK_METHOD2(readBytes, size_t(char *, size_t));\
  MOCK_METHOD3(readBytesUntil, size_t(char, char *, size_t));\
  MOCK_METHOD0(readString, String());\
  MOCK_METHOD1(readStringUntil, String(char));\
  PRINT_MOCK_METHODS()\

#define STREAM_MOCK_OBJECT_GLOBAL_METHODS()\
  MOCK_OBJECT_GLOBAL_METHOD(setTimeout, void);\
  MOCK_OBJECT_GLOBAL_METHOD(find, bool);\
  MOCK_OBJECT_GLOBAL_METHOD(findUntil, bool);\
  MOCK_OBJECT_GLOBAL_METHOD(parseInt, long);\
  MOCK_OBJECT_GLOBAL_METHOD(parseFloat, float);\
  MOCK_OBJECT_GLOBAL_METHOD(readBytes, size_t);\
  MOCK_OBJECT_GLOBAL_METHOD(readBytesUntil, size_t);\
  MOCK_OBJECT_GLOBAL_METHOD(readString, String);\
  MOCK_OBJECT_GLOBAL_METHOD(readStringUntil, String);\
  PRINT_MOCK_OBJECT_GLOBAL_METHODS()\

#endif // STREAM_H

