#ifndef __Wire_h__
#define __Wire_h__

#include <stdint.h>
#include <gmock/gmock.h>
#include "GlobalMockTemplate.h"
#include "WString.h"
#include "Stream.h"

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
    STREAM_MOCK_METHODS()
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
    //inherited from Stream
    STREAM_MOCK_GLOBAL_METHODS()
  });

//class Print
//{
//    int getWriteError() { return write_error; }
//    void clearWriteError() { setWriteError(0); }
//    size_t write(const char *str);
//    virtual size_t write(const uint8_t *buffer, size_t size);

//    size_t print(const String &);
//    size_t print(char);
//    size_t print(int, int = DEC);
//    size_t print(const Printable&);

//    size_t println(const String &s);
//    size_t println(char);
//    size_t println(int, int = DEC);
//    size_t println(const Printable&);
//    size_t println(void);
//};

#endif
