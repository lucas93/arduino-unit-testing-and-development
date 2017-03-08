#ifndef __Wire_h__
#define __Wire_h__

#include <stdint.h>
#include <gmock/gmock.h>
#include "GlobalMockTemplate.h"
#include "WString.h"

#define BUFFER_LENGTH 32

GLOBAL_MOCK_DEFINISION_H(
  Wire,
  {
    MOCK_METHOD0(begin, void());
    MOCK_METHOD1(begin, void(int));
    MOCK_METHOD1(beginTransmission, void(uint8_t));
    MOCK_METHOD0(endTransmission, uint8_t(void));
    MOCK_METHOD1(endTransmission, uint8_t(uint8_t));
    MOCK_METHOD2(requestFrom, uint8_t(uint8_t, uint8_t));
    MOCK_METHOD3(requestFrom, uint8_t(uint8_t, uint8_t, uint8_t));
    MOCK_METHOD1(write, size_t(unsigned int));
    MOCK_METHOD2(write, size_t(const uint8_t *, size_t));
    MOCK_METHOD0(available, int());
    MOCK_METHOD0(read, int());
    MOCK_METHOD0(peek, int());
    MOCK_METHOD0(flush, void());
    MOCK_METHOD1(onReceive, void( void (*)(int) ));
    MOCK_METHOD1(onRequest, void( void (*)(int) ));

    //inherited from Stream
    MOCK_METHOD1(setTimeout, void(unsigned long));
    MOCK_METHOD1(find, bool(char*));
    MOCK_METHOD2(find, bool(char*, size_t));
    MOCK_METHOD2(findUntil, bool(char*, char*));
    MOCK_METHOD4(findUntil, bool(char*, size_t, char*, size_t));
    MOCK_METHOD0(parseInt, long());
    MOCK_METHOD0(parseFloat, float());
    MOCK_METHOD2(readBytes, size_t(char *, size_t));
    MOCK_METHOD3(readBytesUntil, size_t(char, char *, size_t));
    MOCK_METHOD0(readString, String());
    MOCK_METHOD1(readStringUntil, String(char));
  },
  {
    MOCK_GLOBAL_METHOD(begin, void);
    MOCK_GLOBAL_METHOD(beginTransmission, void);
    MOCK_GLOBAL_METHOD(endTransmission, uint8_t);
    MOCK_GLOBAL_METHOD(requestFrom, uint8_t);
    MOCK_GLOBAL_METHOD(write, size_t);
    MOCK_GLOBAL_METHOD(available, int);
    MOCK_GLOBAL_METHOD(read, int);
    MOCK_GLOBAL_METHOD(peek, int);
    MOCK_GLOBAL_METHOD(flush, void);
    MOCK_GLOBAL_METHOD(onReceive, void);
    MOCK_GLOBAL_METHOD(onRequest, void);
    MOCK_GLOBAL_METHOD(setTimeout, void);
    MOCK_GLOBAL_METHOD(find, bool);
    MOCK_GLOBAL_METHOD(findUntil, bool);
    MOCK_GLOBAL_METHOD(parseInt, long);
    MOCK_GLOBAL_METHOD(parseFloat, float);
    MOCK_GLOBAL_METHOD(readBytes, size_t);
    MOCK_GLOBAL_METHOD(readBytesUntil, size_t);
    MOCK_GLOBAL_METHOD(readString, String);
    MOCK_GLOBAL_METHOD(readStringUntil, String);

  });

#endif
